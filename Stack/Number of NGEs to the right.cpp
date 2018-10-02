#include<iostream>
#include <stack>

using namespace std;

int* converttongf(int* arr,int n, stack<pair<int,int>>  &s);
int main(){
	int n = 8;
	int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};
	
	int query = 2;
	while(query--){
		int index;
		cin >> index;
		// count the elemnts from index to end and don't count -1 and repetative elements
	}
	
	stack<pair<int,int>> s;
	int* brr = converttongf(arr,n,s);
	for(int i=0;i<n;i++){
		cout<<brr[i]<<" ";
	}
	cout<<endl;
	return 0;
}


int* converttongf(int* arr,int n, stack<pair<int,int>>  &s){
	s.push(make_pair(0,arr[0]));
	int *brr = new int[n];
	for(int i=1;i<n;i++){
		int next = arr[i];
		if(next > s.top().second){
			while(!s.empty() && next > s.top().second){
				brr[s.top().first] = next;
				s.pop();
			}
			s.push(make_pair(i,next));
		}
		else{
			s.push(make_pair(i,next));
		}
	}
	
	while(!s.empty()){
		brr[s.top().first] = -1;
		s.pop();
	}
	return brr;
} 