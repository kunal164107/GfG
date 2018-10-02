#include<iostream>
using namespace std;


int main(){
	int arr[] = {24,17,25,8,22,12};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int store = arr[0],store_next;
	
	for(int i=0;i<n;i++){
		if(i==0){
			arr[0] = store*arr[1];
		}
		else if(i==n-1){
			arr[n-1] = store*arr[n-1];
		}
		else{
			store_next = arr[i];
			arr[i] = store*arr[i+1];
			store = store_next;
		}
	}
	
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}