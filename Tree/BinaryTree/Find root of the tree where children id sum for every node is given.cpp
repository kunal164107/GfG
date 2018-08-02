#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <utility>

using namespace std;

int main(){
	map<int, int> mymap;
	mymap.insert(pair<int,int> (1,5));
	mymap.insert(pair<int,int> (2,0));
	mymap.insert(pair<int,int> (3,0));
	mymap.insert(pair<int,int> (5,5));
	mymap.insert(pair<int,int> (6,5));
	mymap.insert(pair<int,int> (4,0));
	int sum1=0,sum2=0;
	for(auto it=mymap.begin();it!=mymap.end();it++){
		sum1=sum1+it->first;
		sum2=sum2+it->second;
	}
	
	cout<<"root is "<<sum1-sum2<<endl;
	return 0;
}

