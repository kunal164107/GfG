#include <iostream>

using namespace std;


void swap(int arr[],int a,int b){
	int temp = arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
	
}

int partition(int arr[],int start,int end){
	
	int pindex = start;
	int pivot = arr[end];
	
	for(int i=start;i<end;i++){
		
		if(arr[i]<=pivot){
			swap(arr,pindex,i);
			pindex += 1;
			cout<<"chk2 "<<pindex<<endl;
		}
	}
	swap(arr,pindex,end);
	return pindex;
	
}



void quicksort(int arr[],int start,int end){
	
	if(start>=end){
		return ;
	}
	int pindex = partition(arr,start,end);
	cout<<"chk1 "<<arr[pindex]<<endl;
	quicksort(arr,start,pindex-1);
	quicksort(arr,pindex+1,end);
	
}


int main(){
	
	int n=5;
	int arr[] = {5, 4, 3, 2, 1};
	
	quicksort(arr,0,4);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	
}