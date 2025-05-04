// Program to sort an array using multiple sorting methods 

#include <stdio.h>
#include <stdlib.h>

// Function to perform  Bubble sort
void bubblesort(int arr[],int n);

// Function to perform Insertion sort
void insertionsort(int arr[],int n);

// Function to perform Selection sort
void selectionsort(int arr[],int n);

// Function to Print array 
void printarray(int arr[],int n);

// Main Function
int main(){
int choice ;
int ch=1;
int n;
int arr[50];

while (ch=1){
    printf("\t\t\t\t\t\t\t\t\t\t MENU \t\t\t\t\t\t\t\t\t\t\n");
    printf("\n 1.Bubble sort \n 2.Insertion sort \n 3.Selection sort \n 4.Exit \n");
    printf("Enter your choice from 1-4 : \n");
    scanf("%d",&choice);
    if (choice==4){
        printf("Program ended successfully!! Thank you");
        break;
    } 
    printf("Enter the size of your array : \n");
    scanf("%d",&n);
    printf("Enter the elements of your array : \n");
    for (int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }

    switch(choice){
    case 1:
    printf("The array before bubblesort : \n");
    printarray(arr,n);
    printf("The array after sorting is : \n");
    bubblesort(arr,n);
    printarray(arr,n);
    break;

    case 2:
    printf("The array before insertionsort : \n");
    printarray(arr,n);
    printf("The array after sorting is : \n");
    insertionsort(arr,n);
    printarray(arr,n);
    break;

    case 3:
    printf("The array before selectionsort : \n");
    printarray(arr,n);
    printf("The array after sorting is : \n");
    selectionsort(arr,n);
    printarray(arr,n);
    break;

    default:
    printf("The entered choice is wrong !! Please try again with choices 1-4.");

    }
    }
}

void bubblesort(int arr[],int n){
    
for (int i=0;i<n-1;i++){ 
for (int j=0;j<n-i-1;j++){
if (arr[j]>arr[j+1]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}

void insertionsort(int arr[],int n){

for (int i=1;i<n;i++){
int key=arr[i];
int j=i-1;
while (j>=0 && arr[j]>key){
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
}

void selectionsort(int arr[],int n){

for (int i=0;i<n-1;i++){
int minidx=i;
for (int j=i+1;j<n;j++){
if (arr[j]<arr[minidx]){
minidx=j;
}
}
if (minidx!=i){
int temp=arr[i];
arr[i]=arr[minidx];
arr[minidx]=temp;
}
}
}

void printarray(int arr[],int n){
for (int i=0;i<n;i++){
printf("%d \n",arr[i]);
}
}