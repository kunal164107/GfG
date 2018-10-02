#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n = 7;
	int arr[n] = {7, 6, 5, 4, 3, 2, 1};
	int brr[n];
	for(int i=0;i<n;i++){
		brr[i] = arr[i];
	}
	sort(brr,brr+n);
	int start=0,end=n-1,k=n-1;
	
	while(start<=end && k>=0){
		if((k+1)%2==0){
			arr[k] = brr[end];
			arr[k-1] = brr[start];
		} 
		else{
			arr[k] = brr[start];
			arr[k-1] = brr[end];
		}
		start++;
		end--;
		k=k-2;
	}
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}