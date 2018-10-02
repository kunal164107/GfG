#include <iostream>
#include <queue>
using namespace std;

class stack{
	private:
		queue<int> q;
	public:
		void push(int x){
			if(q.empty()){
				q.push(x);
				return;
			}
			int count = q.size();
			q.push(x);
			while(count>0){
				int z = q.front();
				q.pop();
				q.push(z);
				count--;
			}
		}
		
		void pop(){
			if(q.empty()){
				cout<<"Nothing to POP"<<endl;
				return;
			}
			q.pop();
		}
		int top(){
			if(q.empty()){
				return -1;
			}
			return q.front();
		}
		bool isEmpty(){
			if(q.empty()){
				return true;
			}
			return false;
		}
		
		void display(){
			if(q.empty()){
				cout<<"Stack is Empty"<<endl;
				return;
			}
			
		}
		
}; 

int main(){
		stack s;
		s.push(10);
		s.push(20);
		s.push(30);
		s.push(40);
		
		cout<<"top of stack "<<s.top()<<endl;
		if(!s.isEmpty()) cout<<"Stack is not empty "<<endl;
		else cout<<"Stack is Empty "<<endl;
		
		s.pop();
		s.pop();
		
		cout<<"top of stack "<<s.top()<<endl;
		
		s.pop();
		s.pop();
		
		cout<<"top of stack "<<s.top()<<endl;
		if(!s.isEmpty()) cout<<"Stack is not empty "<<endl;
		else cout<<"Stack is Empty "<<endl;
		
		return 0;
}

