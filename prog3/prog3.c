#include<stdio.h>
void printbits(int n){
    for(int i=31;i>=0;i--){
        printf("%d",(n>>i)&1);
        if(i%8==0)
        printf(" ");
    
    }
    
    printf("\n");
}

int countbits(int n){
    int i,count=0;
    for(i=0;i<32;i++){
        if(n&(1<<i)){
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    printf("enter the number:");
    scanf("%d",&n);

    printf("the bitwise number:\n");
    printbits(n);

    printf("the count of 1's in bit number:%d\n",countbits(n));
}