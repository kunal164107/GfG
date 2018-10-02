#include<iostream>
#include<limits.h>
using namespace std;

class foo{
	public:
		void largestThree(int* arr,int n);
};

void foo::largestThree(int* arr,int n){
	int first,second,third;
	first = second = third = INT_MIN;
	for(int i=0;i<n;i++){
		int x = arr[i];
		if(x>first){
			third = second;
			second = first;
			first = x;
		}
		else if(x>second){
			third = second;
			second = x;
		}
		else if(x>third){
			third = x;
		}
	}
	
	cout<<first<<" "<<second<<" "<<third<<endl;
}


int main(){
	int arr[] = {12, 13, 1, 10, 34, 1};
 	
	foo obj;
	obj.largestThree(arr,6);
	
	return 0;
}