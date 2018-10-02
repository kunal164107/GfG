#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class stack{
	private:
		vector<pair<int,int> > v;
		int min;
		int index;
		
	public:
		stack(){
			min = 100000;
			index = -1;
		}
		
		int GetLastElement(){
			if(v.empty()){
				return -1;
			}
			return v.at(index).first;
		}
		void RemoveLastElement(){
			if(v.empty()){
				cout<<"Nothing to POP"<<endl;
				return;
			}
			v.pop_back();
			index--;
		}	
		void AddElement(int x){
			if(x<min) min =x;
			v.push_back(make_pair(x,min));
			index++;
			return;
		}
		int GetMin(){
			if(index==-1){
				return -1;
			}
			return v.at(index).second;
		}
		
		void display(){
			if(v.empty()){
				cout<<"Stack is Empty"<<endl;
				return;
			}
			
			auto it = v.rbegin();
			while(it!=v.rend()){
				cout<<it->first<<" ";
				it++;
			}
			cout<<endl;
		}
	
};

int main(){
	
	stack s;
	
	s.AddElement(10);
	s.AddElement(20);
	s.AddElement(30);
	
	s.display();
	
	cout<<"Top is "<<s.GetLastElement()<<endl;
	cout<<"MIN is "<<s.GetMin()<<endl;
	
	s.AddElement(8);
	
	s.display();
	
	cout<<"Top is "<<s.GetLastElement()<<endl;
	cout<<"MIN is "<<s.GetMin()<<endl;
	
	s.RemoveLastElement();
	s.RemoveLastElement();
	
	s.display();
	
	cout<<"Top is "<<s.GetLastElement()<<endl;
	cout<<"MIN is "<<s.GetMin()<<endl;
	
	s.AddElement(5);
	
	s.display();
	
	cout<<"Top is "<<s.GetLastElement()<<endl;
	cout<<"MIN is "<<s.GetMin()<<endl;
	
	s.RemoveLastElement();
	s.RemoveLastElement();
	s.RemoveLastElement();
	
	s.display();
	
	cout<<"Top is "<<s.GetLastElement()<<endl;
	cout<<"MIN is "<<s.GetMin()<<endl;
	
	return 0;
	
}