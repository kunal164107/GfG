#include <iostream>
#include <stack>
#include <string>
using namespace std;

string convert(string exp);
string reverse(string exp);
int prec(char ch);

int main(){
	
	string exp = "(A-B/C)*(A/K-L)";
	string s1 = reverse(exp);
	string s2 = convert(s1);
	string s3 = reverse(s2);
	// cout<<"exp "<<exp<<endl;
	// cout<<"s1 "<<s1<<endl;
	// cout<<"s2 "<<s2<<endl;
	cout<<s3<<endl;
	return 0;
}

string reverse(string exp){
	auto itr = exp.rbegin();
	string s;
	while(itr!=exp.rend()){
		if(*itr==')'){
			s.append("(");
		}
		else if(*itr=='('){
			s.append(")");
		}
		else{
			string temp(1,*itr);
			s = s.append(temp);
		}
		itr++;
	}
	return s;
}

string convert(string exp){
	stack<char> s1;
	stack<string> s2;
	auto itr = exp.begin();
	while(itr!=exp.end()){
			if(*itr=='('){
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
						string third = second+first+s1.top();
						s2.push(third);
						s1.pop();
					}
					s1.push(*itr);
				}
			}
			else if(*itr==')'){
				while(s1.top()!='('){
					string first = s2.top();
					s2.pop();
					string second = s2.top();
					s2.pop();
					string third = second+first+s1.top();
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
		string third = second+first+s1.top();
		s2.push(third);
		s1.pop();
	}
	string ans = s2.top();
	s2.pop();
	return ans;
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

