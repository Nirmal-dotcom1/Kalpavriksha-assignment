/* Check for Valid ip address
for eg. input : 232.45.23.12
        output Valid
        
        input : 12..21.23
        output invalid
        */



#include <stdio.h>
int CheckDigit(char character){
  return character>='0' && character<='9';
}

int CheckIPadress(char str[100]){
    int nums[4];
    int countDot=0;
    int index=0;
    int i=0;
    while(str[i]!='\0'){
      if(str[i]=='.'){
        countDot++;
        i++;
      }
      if(str[i]=='.'){
          printf("Invalid IP address");
          return 0;
      }
      int currentNum=0;
      while(CheckDigit(str[i])){
        currentNum=currentNum*10 + ( str[i] - '0');
        i++;
        if(currentNum==0 && CheckDigit(str[i])){
            printf("Invalid IP address");
            return 0;
        }
      }
      
      nums[index++]=currentNum;
     
    }

    int countNumber=0;
    for(int i=0;i<index;i++){
      if(nums[i]>=0 && nums[i]<=255){
        countNumber++;
      }
    }
    if(countDot==3 && countNumber==4 ){
      printf("Valid IP address");
    }
    else{
      printf("Invalid IP address");
    }
}


int main()
{
    char str[100];
    printf("Enter IP address : ");
    scanf("%[^\n]",str);
    CheckIPadress(str);
}
