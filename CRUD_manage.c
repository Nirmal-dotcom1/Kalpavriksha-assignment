#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATA_FILE "user_data.txt"

typedef struct {
    int user_id;
    int user_age;
    char user_name[30];
} UserRecord;

void add_user();
int is_id_unique(int id);
void display();
void update();
void delete();
void display_menu();

int main() {
    int choice;


    //choosing the operation 

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_user();
            break;
        case 2:
            display();
            break;
        case 3:
            update();
            break;
        case 4:
            delete();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\nChoose the action you want to perform\n");
    printf("1. Add a New User\n");
    printf("2. View All the Users\n");
    printf("3. Update User Information\n");
    printf("4. Delete a User\n");
    printf("5. Exit\n");
    printf("Choose the action you want to perform\n : ");
}

// function for adding a user
void add_user() {
    FILE *file_ptr = fopen(DATA_FILE, "a");
    if (file_ptr == NULL) {
        printf("Error: Could not open the file.\n");
        return;
    }

    UserRecord user;
    int unique = 0;

    while (!unique) {
        printf("Enter User ID: ");
        scanf("%d", &user.user_id);

        if (is_id_unique(user.user_id)) {
            unique = 1;
        } else {
            printf("This ID already exists. Please enter a different ID.\n");
        }
    }

    getchar();
    printf("Enter User Name: ");
    fgets(user.user_name, sizeof(user.user_name), stdin);
    user.user_name[strcspn(user.user_name, "\n")] = '\0';

    printf("Enter User Age: ");
    scanf("%d", &user.user_age);

    fprintf(file_ptr, "ID: %d, Name: %s, Age: %d\n", user.user_id, user.user_name, user.user_age);
    fclose(file_ptr);
    printf("User has been added successfully.\n");
}

//checking the is is unique or not
int is_id_unique(int id) {
    FILE *file_ptr = fopen(DATA_FILE, "r");
    if (file_ptr == NULL) {
        return 1;
    }

    UserRecord user;

    while (fscanf(file_ptr, "ID: %d, Name: %[^,], Age: %d\n", &user.user_id, user.user_name, &user.user_age) != EOF) {
        if (user.user_id == id) {
            fclose(file_ptr);
            return 0;
        }
    }

    fclose(file_ptr);
    return 1;
}

// function to view all the users
void display() {
    FILE *file_ptr = fopen(DATA_FILE, "r");
    if (file_ptr == NULL) {
        printf("No user data found.\n");
        return;
    }

    char line[100];
    printf("\n List of Users\n");
    while (fgets(line, sizeof(line), file_ptr)) {
        printf("%s", line);
    }

    fclose(file_ptr);
}

// function for modifying the user data
void update() {
    FILE *file_ptr = fopen(DATA_FILE, "r");
    if (file_ptr == NULL) {
        printf("Error: No user data to modify.\n");
        return;
    }

    int id_to_update;
    printf("Enter the ID of the user to update: ");
    scanf("%d", &id_to_update);

    FILE *temp_file = fopen("temp_data.txt", "w");
    if (temp_file == NULL) {
        printf("Error: Unable to create a temporary file.\n");
        fclose(file_ptr);
        return;
    }

    UserRecord user;
    int found = 0;

    while (fscanf(file_ptr, "ID: %d, Name: %[^,], Age: %d\n", &user.user_id, user.user_name, &user.user_age) != EOF) {
        if (user.user_id == id_to_update) {
            found = 1;
            printf("Enter new name (current: %s): ", user.user_name);
            getchar();
            fgets(user.user_name, sizeof(user.user_name), stdin);
            user.user_name[strcspn(user.user_name, "\n")] = '\0';

            printf("Enter new age (current: %d): ", user.user_age);
            scanf("%d", &user.user_age);
        }
        fprintf(temp_file, "ID: %d, Name: %s, Age: %d\n", user.user_id, user.user_name, user.user_age);
    }

    fclose(file_ptr);
    fclose(temp_file);

    if (found) {
        remove(DATA_FILE);
        rename("temp_data.txt", DATA_FILE);
        printf("User information updated successfully.\n");
    } else {
        remove("temp_data.txt");
        printf("No user found with ID %d.\n", id_to_update);
    }
}

//delelting of a data
void delete() {
    FILE *file_ptr = fopen(DATA_FILE, "r");
    if (file_ptr == NULL) {
        printf("No user data to delete.\n");
        return;
    }

    int id_to_delete;
    printf("Enter the ID of the user to delete: ");
    scanf("%d", &id_to_delete);

    FILE *temp_file = fopen("temp_data.txt", "w");
    if (temp_file == NULL) {
        printf("Error: Unable to create a temporary file.\n");
        fclose(file_ptr);
        return;
    }

    UserRecord user;
    int deleted = 0;

    while (fscanf(file_ptr, "ID: %d, Name: %[^,], Age: %d\n", &user.user_id, user.user_name, &user.user_age) != EOF) {
        if (user.user_id != id_to_delete) {
            fprintf(temp_file, "ID: %d, Name: %s, Age: %d\n", user.user_id, user.user_name, user.user_age);
        } else {
            deleted = 1;
        }
    }

    fclose(file_ptr);
    fclose(temp_file);

    if (deleted) {
        remove(DATA_FILE);
        rename("temp_data.txt", DATA_FILE);
        printf("User with ID %d has been deleted.\n", id_to_delete);
    } else {
        remove("temp_data.txt");
        printf("No user found with ID %d.\n", id_to_delete);
    }
}
