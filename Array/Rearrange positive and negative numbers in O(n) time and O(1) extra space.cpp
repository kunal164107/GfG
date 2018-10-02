#include<iostream>

using namespace std;

void rearrange(int* arr,int n,int pivot);
void swapElements(int* arr,int n,int pos);
int main(){
	int n = 9;
	int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
	
	int pivot = 0;
	rearrange(arr,n,pivot);
	
	int pos;
	for(pos=0;pos<n;pos++){
		if(arr[pos]>=0){
			break;
		}
	}
	
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
	swapElements(arr,n,pos);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}


void rearrange(int* arr,int n,int pivot){
	int pindex = 0;
	for(int i=0;i<n;i++){
		if(arr[i]<pivot){
			swap(arr[pindex],arr[i]);
			pindex++;
		}
	}
}

void swapElements(int* arr,int n,int pos){
	int i=0,j=pos;
	while(i<n){
		swap(arr[i],arr[j]);
		i+=2;
		j++;
	}
}