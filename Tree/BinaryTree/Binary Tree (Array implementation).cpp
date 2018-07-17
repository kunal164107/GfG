#include <iostream>

using namespace std;

class tree{
	
	public:
		int arr[100];
		int b=0;
		void setroot(int key){
			arr[1]=key;
			b++;
		}
		
		void setleft(int key,int root){
			arr[2*root] = key;
			b++;
		}
		
		void setright(int key,int root){
			arr[2*root+1] = key;
			b++;
		}
		
		void print(){
			for(int i=1;i<=b;i++){
				cout<<arr[i]<<" ";
			}
		}	
};

int main(){
	
	tree myobj;
	myobj.setroot(1);
	myobj.setleft(2,1);
	myobj.setright(3,1);
	myobj.setleft(4,2);
	myobj.setright(5,2);
	
	myobj.print();
}

