#include <iostream>
#include <vector>

using namespace std;

void fillvector(vector<int>&);
void printvector(const vector<int>&);

int main(){
	
	vector<int> myvector;
	fillvector(myvector);
	printvector(myvector);
	return 0;
}

void fillvector(vector<int>& newmyvector){
	cout<<"enter input to vector and -1 to stop ";
	
	int in;
	cin>>in;
	
	while(in!=-1){
		newmyvector.push_back(in);
		cin>>in;
	}
	
}

void printvector(const vector<int>& newmyvector){
	
	cout<<"vector: ";
	
	for(unsigned int i=0;i<newmyvector.size();i++){
		cout<<newmyvector.at(i)<<" ";
	}
	
	cout<<endl;
}