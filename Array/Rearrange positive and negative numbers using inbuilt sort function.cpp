#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a,int b){
		if(a<0 && b<0 || a>=0 && b>=0 || a>=0 && b<0) return false;
		
		if(a<0 && b>=0) return true;
		
}

int main(){
	int n = 9;
	int arr[] = {12, 11, -13, 0, 6, -7, 5, -3, -6};

	
	
	sort(arr,arr+n,comp);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}

