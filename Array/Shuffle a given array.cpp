#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


int main(){
	int arr[] = {24,17,25,8,22,12};
	int n = sizeof(arr)/sizeof(arr[0]);
 	
	srand(time(NULL));
	
	for(int i=n-1;i>=0;i--){
		int z = rand()%(i+1);
		// cout<<z<<endl;
		swap(arr[i],arr[z]);
	}
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}