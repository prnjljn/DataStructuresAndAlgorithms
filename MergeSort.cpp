#include<iostream>
using namespace std;
void merge(int *arr, int start, int mid, int end){
    int temp[end-start+1];
    int i = start,j=mid+1,k=0;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid) {
    temp[k] = arr[i];
    k += 1; i += 1;
    }
    while(j <= end) {
		temp[k] = arr[j];
		k += 1; j += 1;
	}
    for(i = start; i <= end; i += 1) {
		arr[i] = temp[i - start]
	}
}
void mergeSort(int *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}
