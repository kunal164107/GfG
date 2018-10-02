#include <iostream>
#include <stack>

using namespace std;

class deleteElement{
	public:
		
		void fun(stack<int> &s, int k){
			for(int i=0;i<k;i++){
				del(s);
			}
		}
	
		void del(stack<int> &s){
			
			int x = s.top();
			s.pop();
			
			if(x<s.top()) return;
			
			del(s);
		
			s.push(x);		
		}	
};



int main(){
	int arr[] = { 23, 45, 11, 77, 18};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	
	stack<int> s;
	
	for(int i=n-1;i>=0;i--){
		s.push(arr[i]);
	}
	
	deleteElement obj;
	obj.fun(s,k);
	
	int index=0;
	while(!s.empty()){
		arr[index] = s.top();
		s.pop();
		index++;
	}
	
	for(int i=0;i<index;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}