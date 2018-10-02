#include<bits/stdc++.h>
using namespace std;

void printMissing(string s){
	bool mark[26] = {false};
	transform(s.begin(),s.end(),s.begin(),::tolower);
	for(auto itr=s.begin();itr!=s.end();itr++){
		int index = *itr - 'a';
		if(mark[index]!=true) mark[index] = true;
	}
	
	string res;
	for(int i=0;i<26;i++){
		if(mark[i] == false){
			res = res + (char)('a' + i);
		}
	}
	cout<<res;
}



int main()
{
	string s("The quick brown fox jumps");
	printMissing(s); 
	return 0;
}