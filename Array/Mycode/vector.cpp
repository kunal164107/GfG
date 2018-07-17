#include <iostream>
#include <vector>

using namespace std;



int main(){
	
	vector<int> myvector;
	myvector.push_back(5);
	myvector.push_back(10);
	myvector.push_back(15);
	
	cout<<"vector: ";
	
	for(unsigned int i=0;i<myvector.size();i++){
		cout<<myvector.at(i)<<" ";
	}
	
	cout<<endl;
	
	myvector.insert(myvector.begin(),20);
	
	cout<<"vector: ";
	
	for(unsigned int i=0;i<myvector.size();i++){
		cout<<myvector.at(i)<<" ";
	}
	
	cout<<endl;
	
	myvector.erase(myvector.begin()+2);
	
	cout<<"vector: ";
	
	for(unsigned int i=0;i<myvector.size();i++){
		cout<<myvector.at(i)<<" ";
	}
	
	cout<<endl;
	
	if(myvector.empty()){
		cout<<"vector is empty"<<endl;
	}
	else{
		cout<<"vector is not empty"<<endl;
	}
	
	myvector.clear();
	
	if(myvector.empty()){
		cout<<"vector is empty"<<endl;
	}
	else{
		cout<<"vector is not empty"<<endl;
	}
	
	return 0;
}