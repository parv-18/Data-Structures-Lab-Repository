// Header file for sorting 

#include <stdio.h>

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
