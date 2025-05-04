//Program to search a given element in an array using multiple searching methods 

#include <stdio.h>
#include "lab1.2.h"

//Function to perform linear search

int linearsearch(int arr[],int n,int flg);

//Function to perform binary search

int binarysearch(int arr[],int n,int flg);

//Main Function

int main(){
int choice ;
int ch=1;
int n;
int flg;
int arr[50];
while(ch=1){
    printf("\t\t\t\t\t\t\t\t\t\t MENU \t\t\t\t\t\t\t\t\t\t\n");
    printf("\n 1.Linear search \n 2.Binary search \n 3.Exit \n ");
    printf("Enter your choice from 1-3 : \n");
    scanf("%d",&choice);
    if (choice ==3){
        printf("The program ended successfully !! Thank you.");
        break;
    }
    printf("Enter the size of your array : \n");
    scanf("%d",&n);

    printf("Enter the elements of your array : \n");
    for (int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    printf("Enter the target element to search : \n");
    scanf("%d",&flg);

    switch(choice){

    case 1:
    linearsearch(arr,n,flg);
    break;

    case 2:
    bubblesort(arr,n);
    binarysearch(arr,n,flg);
    break;


    default:
    printf("The entered choice is wrong !! Please try again with choices 1-4.");
    break;


    }
    }
}

//Function to implement Linear Search
int linearsearch(int arr[],int n,int flg){

for(int i=0;i<n;i++){
if (arr[i]==flg){
printf("The element %d is found at position %d",flg,i+1);
return 1 ;
}
}
printf("The element is not found in the given array");
return -1;
}

//Function to implement Binary Search
int binarysearch(int arr[],int n,int flg){
int low=0;
int high=n-1;
while (low<=high){
    int mid=low + (high-low)/2;
    if (arr[mid]==flg){
    printf("The element %d is found at position %d",flg,mid);
    return mid;
    }
    else if (arr[mid]<flg){
    low=mid+1;
    }
    else {
    high=mid-1;
    }
}
printf("The element is not found in the given array");
return -1;
}
