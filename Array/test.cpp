#include<iostream>
using namespace std;

int f(int *p, int q){
		if(q<=0) return 0;
		else if(*p%2==0) return *p + f(p+1,q-1);
		else return *p - f(p+1,q-1);
}

int main(){
	int arr[] = {24,17,25,8,22,12};
 	cout<<f(arr,6);
	return 0;
}