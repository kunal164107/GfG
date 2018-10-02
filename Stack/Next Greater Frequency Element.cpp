#include<iostream>
#include <stack>
#include <map>

using namespace std;

void frequencyofelements(int* arr, int n, map<int, int> &m);
int* converttongf(int* arr,int n, map<int, int> &m, stack<pair<int,int>>  &s);
int main(){
	int n = 7;
	int arr[] = {1, 1, 2, 3, 4, 2, 1};
	map<int, int> m;
	frequencyofelements(arr,n,m);
	
/*	
	for(auto itr=m.begin();itr!=m.end();itr++){
		cout<<itr->first<<"  ";
		cout<<itr->second<<"  ";
		cout<<endl;
	}
*/
	stack<pair<int,int>> s;
	int* brr = converttongf(arr,n,m,s);
	
	for(int i=0;i<n;i++){
		cout<<brr[i]<<" ";
	}
	cout<<endl;
	return 0;
}

void frequencyofelements(int* arr, int n, map<int, int> &m){
	for(int i=0;i<n;i++){
		auto itr = m.find(arr[i]);
		if(itr == m.end()){
			m.insert(pair<int, int> (arr[i],1));
		}
		else{
			itr->second++;
		}
	}
}

int* converttongf(int* arr,int n, map<int, int> &m, stack<pair<int,int>>  &s){
	s.push(make_pair(0,arr[0]));
	int *brr = new int[n];
	for(int i=1;i<n;i++){
		int next = arr[i];
		if(m.find(next)->second > m.find(s.top().second)->second){
			while(!s.empty() && m.find(next)->second > m.find(s.top().second)->second){
				brr[s.top().first] = next;
				s.pop();
			}
			s.push(make_pair(i,next));
		}
		else{
			s.push(make_pair(i,arr[i]));
		}
	}
	
	while(!s.empty()){
		brr[s.top().first] = -1;
		s.pop();
	}
	return brr;
} 