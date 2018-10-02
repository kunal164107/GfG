#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

class reverseString{
	public:
		void reverse(char* exp);
		void reverseByStack(char* exp);
};


int main(){
	char str[] = "Geeks for Geeks";
	
	reverseString obj;
	
	obj.reverseByStack(str);
	
	/*
		Second Method to solve this problem
		
		char* pch = strtok(str," ");
		while(pch != NULL){
			obj.reverse(pch);
			cout<<" ";
			pch = strtok(NULL," ");
		}
		cout<<endl;
	*/
	
}

void reverseString :: reverse(char* exp){
	stack<char> s;
	int i=0;
	while(exp[i]!='\0'){
		s.push(exp[i]);
		i++;
	}
	
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	
}

void reverseString :: reverseByStack(char* exp){
	stack<char> s;
	int i=0;
	while(exp[i]!='\0'){
		if(exp[i]==' '){
			while(!s.empty()){
				cout<<s.top();
				s.pop();
			}
			cout<<" ";
		}else{
			s.push(exp[i]);
		}
		i++;
	}
	
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	cout<<endl;
} 

