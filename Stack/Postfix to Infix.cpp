#include <iostream>
#include <string>
#include <stack>
using namespace std;

string convert(string exp);
int prec(char ch);
int main(){
	
	string exp = "abcd^e-fgh*+^*+i-";
	cout<<convert(exp)<<endl;
	
	return 0;
}

string convert(string exp){
	stack<string> s2;
	stack<char> s1;
	auto itr = exp.begin();
	while(itr!=exp.end()){
		if(isalpha(*itr)){
			string s(1,*itr);
			s2.push(s);
		}
		else if(*itr=='+' || *itr=='-' || *itr=='*' || *itr=='/' || *itr=='^'){
			string second = s2.top();
			s2.pop();
			string first = s2.top();
			s2.pop();
			string third;
			if(s1.empty() || prec(*itr) <= prec(s1.top())){
				string third = first + *itr + second;
				s2.push(third);
				s1.push(*itr);
			}
			else if(prec(*itr) > prec(s1.top())){
				if(first.length()!=1 ){
					third = "(" + first + ")";
				} 
				else{
					third = first;
				}
				
				third = third + *itr;
				
				if(second.length()!=1 ){
					third = third.append("(" + second + ")");				
				} 
				else{
					third = third.append(second);
				}
				s2.push(third);
			}	
		}
		itr++;
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