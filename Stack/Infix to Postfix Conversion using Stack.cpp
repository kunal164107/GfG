#include <iostream>
#include <stack>
#include <string>
using namespace std;

void convert(string exp);
int prec(char ch);
int main(){
	
	string exp = "A*(B+C)/D";
	convert(exp);
	return 0;
}

// abcd^e-fgh*+^*+i-

void convert(string exp){
	stack<char> s;
	auto itr = exp.begin();
	while(itr!=exp.end()){
			if(*itr=='('){
				// cout<<"chk1"<<endl;
				s.push(*itr);
			}
			else if(*itr=='+' || *itr=='-' || *itr=='*' || *itr=='/' || *itr=='^'){
				// cout<<"chk2"<<endl;
				if(s.empty()){
					s.push(*itr);
				}
				else if(prec(*itr)>prec(s.top())){
					s.push(*itr);
				}
				else if(prec(*itr)<=prec(s.top())){
					while(!s.empty() && prec(*itr)<=prec(s.top())){
						cout<<s.top();
						s.pop();
					}
					s.push(*itr);
				}
			}
			else if(*itr==')'){
				// cout<<"chk3"<<endl;
				while(s.top()!='('){
					cout<<s.top();
					s.pop();
				}
				s.pop();
			}
			else{
				// cout<<"chk4"<<endl;
				cout<<*itr;
			}
			itr++;
	}

	// if(s.empty()) cout<<"Stack empty"<<endl;
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	
}

int prec(char ch){
	switch(ch){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

