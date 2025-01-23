#include<stdio.h>
#include<string.h>

void parseinput(char *str){
    int i=0;
    char temp[100];
    int index=0;
    while(str[i]!='\0'){
        
        if(str[i]=='"' || str[i]=='"' || str[i]==',' || str[i]==' '){
            i++;
            continue;
        }
        temp[index++]=str[i];
        i++;
    }
    temp[index]='\0';
    
    strcpy(str,temp);
}

void swap(char *ch1,char *ch2){
    
    char temp=*ch1;
    *ch1=*ch2;
    *ch2=temp;
}

void permutation(char *str,int start,int end,int *flag){
   
    
    if(start==end){
        if(*flag==0){
            printf(",");
        }
        printf("[");
        printf("%s",str);
        printf("]");
        *flag=0;
        }
    for(int i=start;i<end;i++){
        swap(&str[i],&str[start]);
        permutation(str,start+1,end,flag);
        swap(&str[i],&str[start]);
    } 
}

int main()
{
  char str[100];
  scanf("%[^\n]",str);
    parseinput(str);
  int len=0;
  while(str[len]!='\0'){
      len++;
  }
  printf("[");
   int flag=1;
  permutation(str,0,len,&flag);
  printf("]");
  
    return 0;
}
