#include<iostream>
using namespace std;

void insertionSort(int a[],int n){
    int i ,j,key;
    for(int i=1;i<n;i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){

}
