// Program to check if a number is a plaindrome,armstrong or perfect number

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes

void palindrome(int *num);
void armstrong(int *num);
void perfectnum(int *num);
void menu();

//Main function

int main(){
int *ch=(int *) malloc(sizeof(int));
*ch=1;
int *choice=(int *) malloc(sizeof(int));
while(*ch==1){
menu();
printf("Enter a choice from 1-4 : ");
scanf("%d",choice);
switch(*choice){
case 1:{

int *num=(int *) malloc(sizeof(int));
printf("Enter a number to check if it is a palindrome : ");
scanf("%d",num);
palindrome(num);
break;
}

case 2:{
int *num=(int *) malloc(sizeof(int));
printf("Enter a number to check if it is an armstrong number : ");
scanf("%d",num);
armstrong(num);
break;
}

case 3:{
int *num=(int *) malloc(sizeof(int));
printf("Enter a number to check if it is a perfect number : ");
scanf("%d",num);
perfectnum(num);
break;
}

case 4:{
printf("The program ended successfully !! Thank you \n");
break;
}

default:{
printf("The entered choice is wrong. Try a choice from 1-4 \n");
break;
}


}
printf("Enter 1 to continue : ");
scanf("%d",ch);
}
return 0;
}

//Menu

void menu(){

printf("\t\t\t\t\t\t\t\t\t\t MENU \t\t\t\t\t\t\t\t\t\t \n");
printf(" 1. CHECK IF A NUMBER IS PALINDROME \n 2. CHECK IF A NUMBER IS ARMSTRONG \n 3. CHECK IF A NUMBER IS PERFECT \n 4. EXIT \n");
}

//Function to find if a given number is palindrome number or not

void palindrome(int *num){

    int *temp=(int *) malloc(sizeof(int));
    *temp=*num;
    int *reversed=(int *) malloc(sizeof(int));
    *reversed=0;
    int *remainder=(int *) malloc(sizeof(int));
    while(*temp>0){
        *remainder=(*temp)%10;
        *reversed=(*reversed)*10+(*remainder);
        *temp=*temp/10;
    }
    if(*reversed==*num){
    printf("%d is a palindrome \n",*num);
    }
    else{
    printf("%d is not a palindrome \n",*num);
    }
}

// Function to find if a given number is armstrong number or not

void armstrong(int *num){
    int *temp=(int *) malloc(sizeof(int));
    *temp=*num;
    int *dig=(int *) malloc(sizeof(int));
    *dig=0;
    while(*temp>0){
        *temp=*temp/10;
        (*dig)++;
    }
    *temp=*num;
    int *remainder=(int *) malloc(sizeof(int));
    int *sum=(int *) malloc(sizeof(int));
    *sum=0;
    while(*temp>0){
        *remainder=(*temp)%10;
        *sum+=pow(*remainder,*dig);
        *temp=(*temp)/10;
    }
    if(*sum==*num){
        printf("%d is an armstrong number \n",*num);
    }
    else{
        printf("%d is not an armstrong number \n",*num);
    }

}

// Function to find if a given number is perfect number or not

void perfectnum(int *num){
    int *sum=(int *) malloc(sizeof(int));
    int *i = (int *) malloc(sizeof(int));
    *sum=0;
    for ((*i)=1;(*i)<*num;(*i)++){
        if ((*num)%(*i)==0){
            (*sum)+=(*i);
        }
    }
    if ((*sum)==(*num)){
        printf("%d is a perfect number \n",*num);
    }
    else{
        printf("%d is not a perfect number \n",*num);
    }
}


