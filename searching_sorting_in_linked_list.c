#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int book_number;
    struct Node *next;
} Node;

Node *create_node(int book_number)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->book_number = book_number;
    new_node->next = NULL;
    return new_node;
}

void insert(Node **head, int book_number)
{
    Node *new_node = create_node(book_number);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->book_number);
        current = current->next;
    }
    printf("NULL\n");
}

Node *find_middle(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->book_number <= right->book_number)
    {
        left->next = merge(left->next, right);
        return left;
    }
    else
    {
        right->next = merge(left, right->next);
        return right;
    }
}

Node *merge_sort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *middle = find_middle(head);
    Node *next_to_middle = middle->next;
    middle->next = NULL;

    Node *left = merge_sort(head);
    Node *right = merge_sort(next_to_middle);

    return merge(left, right);
}

int search(Node *head, int target)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->book_number == target)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;

    int main()
    {
        Node *head = NULL;
        int n, book_number, target;

        printf("Enter the number of books: ");
        scanf("%d", &n);

        printf("Enter the book numbers:\n");
        for (int i = 0; i < n; i++)
        {
            printf("Book %d: ", i + 1);
            scanf("%d", &book_number);
            insert(&head, book_number);
        }

        printf("\nOriginal List: ");
        print_list(head);

        head = merge_sort(head);
        printf("Sorted List using MergeSort: ");
        print_list(head);

        printf("Enter the book number to search for: ");
        scanf("%d", &target);
        if (search(head, target))
        {
            printf("Book number %d found in the list.\n", target);
        }
        else
        {
            printf("Book number %d not found in the list.\n", target);
        }

        return 0;
    }
