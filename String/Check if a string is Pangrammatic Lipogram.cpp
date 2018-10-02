#include<bits/stdc++.h>
using namespace std;

void pangram_lipogram(string s){
	bool mark[26] = {false};
	transform(s.begin(),s.end(),s.begin(),::tolower);
	for(auto itr=s.begin();itr!=s.end();itr++){
		int index = *itr - 'a';
		if(mark[index]==false) mark[index] = true;
	}
	
	int count = 0;
	for(int i=0;i<26;i++){
		if(mark[i]==false) count++;
	}
	
	if(count == 0) cout<<"Pangram"<<endl;
	else if(count == 1) cout<<"Pangrammatic Lipogram"<<endl;
	else cout<<"Lipogram"<<endl;
}

int main()
{
	string s("The quick brown fox jum over the lazy dog");
	pangram_lipogram(s);
	
	return 0;
}