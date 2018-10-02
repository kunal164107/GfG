#include <iostream>
#include <stack>
#include <string>
using namespace std;

void convert(string exp);
int prec(char ch);
int main(){
	
	string exp = "((A+B)*(C-D))";
	convert(exp);
	return 0;
}


void convert(string exp){
	stack<char> s1;
	stack<string> s2;
	auto itr = exp.rbegin();
	while(itr!=exp.rend()){
			if(*itr==')'){
				s1.push(*itr);
			}
			else if(*itr=='+' || *itr=='-' || *itr=='*' || *itr=='/' || *itr=='^'){
				if(s1.empty()){
					s1.push(*itr);
				}
				else if(prec(*itr)>prec(s1.top())){
					s1.push(*itr);
				}
				else if(prec(*itr)<=prec(s1.top())){
					while(!s1.empty() && prec(*itr)<=prec(s1.top())){
						string first = s2.top();
						s2.pop();
						string second = s2.top();
						s2.pop();
						string third = s1.top()+first+second;
						s2.push(third);
						s1.pop();
					}
					s1.push(*itr);
				}
			}
			else if(*itr=='('){
				while(s1.top()!=')'){
					string first = s2.top();
					s2.pop();
					string second = s2.top();
					s2.pop();
					string third = s1.top()+first+second;
					s2.push(third);
					s1.pop();
				}
				s1.pop();
			}
			else{
				string temp(1,*itr);
				s2.push(temp);
			}
			itr++;
	}

	while(!s1.empty()){
		string first = s2.top();
		s2.pop();
		string second = s2.top();
		s2.pop();
		string third = s1.top()+first+second;
		s2.push(third);
		s1.pop();
	}
	
	string ans = s2.top();
	s2.pop();
	cout<<ans<<endl;
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

