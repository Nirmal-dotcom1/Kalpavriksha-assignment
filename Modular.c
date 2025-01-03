#include<stdio.h>

void clearInputBuffer();
long long evaluate(long long base,long long exponent,long long mod);

int main(){
    long long base;
    long long exponent;
    long long mod;
    long long Result;

    printf("Enter value for Base : ");
    if(scanf("%lld",&base)!=1 || base<0){
        printf("Invalid Value Entered");
        return 1;
    }
    clearInputBuffer();

    printf("Enter value for Exponent : ");
    if(scanf("%lld",&exponent)!=1 || exponent<0){
        printf("Invalid Value Entered");
        return 1;
    }
    clearInputBuffer();

    printf("Enter value for Modulas : ");
    if(scanf("%lld",&mod)!=1 || mod<=1){
        printf("Invalid Value Entered");
        return 1;
    }
    clearInputBuffer();

    Result=evaluate(base, exponent, mod);

    printf("The Output OF The mathematic Expression is : %lld",Result);

}

void clearInputBuffer(){
    while(getchar()!='\n');
}

long long evaluate(long long base,long long exponent,long long mod){

    base=base%mod;
    long long Result=1;

    while(exponent>0){
      if(exponent%2==1){
            Result=(Result*base)%mod;
      }
        else{
            base=(base*base)%mod;
            exponent/=2;
        }
    }
    return Result;
}
