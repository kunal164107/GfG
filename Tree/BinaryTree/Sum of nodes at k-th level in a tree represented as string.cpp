#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

int main(){
	
	string str = "(8(3(2()())(6(5()())()))(5(10()())(7(13()())())))" ;
	stack<char> s;
	map<int,int> mymap;
	for(auto itr=str.begin();itr!=str.end();itr++){
		if(*itr=='('){
			s.push(*itr);
		}
		else if(*itr==')'){
			s.pop();
		}
		else{
			int result =  *itr -'0';
			int size = s.size();
			auto it = mymap.find(size-1);
			if(it!=mymap.end()){
				it->second = it->second + result;
			}
			else{
				mymap.insert(pair<int,int> (size-1,result));
			}
		}
	}
	
	int k = 3;
	auto ans = mymap.find(k);
	cout<<ans->second;
	
	return 0;
}

