#include <iostream>
#include <string>
#include <stack>
using namespace std;

string convert(string exp);
int main(){
	
	string exp = "ABC/-AK/L-*";
	cout<<convert(exp)<<endl;
	
	return 0;
}

string convert(string exp){
	stack<string> s2;
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
				string third = *itr + first + second;
				s2.push(third);
		}
		itr++;
	}

	string ans = s2.top();
	s2.pop();
	return ans;
}