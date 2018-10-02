#include<bits/stdc++.h>
using namespace std;

void erase_punct(string s){
	for(auto itr=s.begin();itr!=s.end();itr++){
		if(ispunct(*itr)) s.erase(itr--);
	}
	cout<<s;
}

int main()
{
	string s("%welcome' to @geeksforgeek<s");
	erase_punct(s);
	
	return 0;
}