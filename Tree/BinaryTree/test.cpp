#include <iostream>
#include <vector>
 
using namespace std;

int main(){
	
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	for(int i=0;i<v.size();i++){
		cout<<v.at(i)<<" ";
	}
	cout<<endl;		
	cout<<"v.begin--> "<<v.front()<<endl;
	cout<<"v.end--> "<<v.back()<<endl;
	

	for(int i=0;i<v.size();i++){
		cout<<v.at(i)<<" ";
	}
	
	return 0;

}
