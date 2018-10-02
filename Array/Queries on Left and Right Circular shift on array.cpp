#include <iostream>
using namespace std;

class findindex{
	public:
		void rightrotate(int* arr,int count,int size){
			for(int j=1;j<=count;j++){
				int temp = arr[size-1];
				for(int i=size-1;i>=0;i--){
					if(i!=0) arr[i] = arr[i-1];
				}
				arr[0] = temp;	
			}
		}
		
		void leftrotate(int* arr,int count,int size){	
			for(int j=1;j<=count;j++){
				int temp = arr[0];
				for(int i=0;i<size;i++){
					if(i!=size-1) arr[i] = arr[i+1];
				}
				arr[size-1] = temp;
			}
		}
		
		int count(int* arr,int start,int end){
			int sum=0;
			for(int i=start;i<=end;i++){
				sum = sum+arr[i];
			}
			return sum;
		}
};

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int n=5;
	int range[][3] = {{1,3,0},{3,0,2},{2,1,0},{3,1,4}};
	
	int rows = sizeof(range)/sizeof(range[0]);
	int cols = sizeof(range[0])/sizeof(range[0][0]);
	
	// cout<<range[0][1];
	
	findindex obj;
	for(int i=0;i<rows;i++){
		if(range[i][0] == 1){
			obj.rightrotate(arr,range[i][1],n);
		}
		else if(range[i][0] == 2){
			obj.leftrotate(arr,range[i][1],n);
		}
		else if(range[i][0] == 3){
			cout<<"Sum is "<<obj.count(arr,range[i][1],range[i][2])<<endl;
		}
	}
}