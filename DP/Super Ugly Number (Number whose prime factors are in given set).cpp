#include<bits/stdc++.h>
using namespace std;

unsigned int minimum(unsigned int* arr,int n){
	unsigned int min = INT_MAX;
	for(int i=0;i<n;i++){
		if(arr[i]<min) min = arr[i];
	}
	return min;
}


unsigned int getUgly(int* prime,int n,int prime_size){
	unsigned int ugly[n];
	ugly[0] = 1;
	
	unsigned int next_multiple_iterator[prime_size] = {0};
	unsigned int next_multiple[prime_size];
	for(int i=0;i<prime_size;i++){
		next_multiple[i] = prime[i];
		// cout<<next_multiple[i]<<endl;
	}
	
	unsigned int next_ugly_no = 1;
	
	for(int i=1;i<n;i++){
		next_ugly_no = minimum(next_multiple,prime_size);
		ugly[i] = next_ugly_no;
		
		for(int j=0;j<prime_size;j++){
			if(next_ugly_no == next_multiple[j]){
				next_multiple_iterator[j] += 1;
				next_multiple[j] = ugly[next_multiple_iterator[j]]*prime[j];
			}
		}
		
		// cout<<next_ugly_no<<endl;
	}
	
	return ugly[n-1];
}

int main(){
	int prime[] = {3,5,7,11,13};
	int n = 9;
	cout<<getUgly(prime,n,5)<<endl;
	
	return 0;
}