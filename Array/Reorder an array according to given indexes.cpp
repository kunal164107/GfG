#include <iostream>

using namespace std;

int main(){
	int arr[] = {10, 11, 12};
	int index[] = {1,2,0};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0;i<n;i++){
		if(index[i]!=i){
			swap(arr[i],arr[index[i]]);
			swap(index[i],index[index[i]]);
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	for(int i=0;i<n;i++){
		cout<<index[i]<<" ";
	}
	cout<<endl;
}