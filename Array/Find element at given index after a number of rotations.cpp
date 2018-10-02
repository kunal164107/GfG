#include <iostream>
using namespace std;

class findindex{
	public:
		int findelement(int arr[], int range[][2], int index, int rows, int cols){
			for(int i=0;i<rows;i++){
				arr = rotatebyone(arr, range[i][0], range[i][1]);
				for(int i=0;i<5;i++){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
			}
			
			return arr[index];
		}
		
		int* rotatebyone(int* arr, int start, int end){	
			int temp = arr[end];
			for(int i=end;i>=start;i--){
				if(i!=start) arr[i] = arr[i-1];
			}
			arr[start] = temp;
			return arr;
		}
};

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int range[][2] = {{0,2},{0,3}};
	int index = 1;
	
	int rows = sizeof(range)/sizeof(range[0]);
	int cols = sizeof(range[0])/sizeof(range[0][0]);
	
	findindex obj;
	int x = obj.findelement(arr,range,index,rows,cols);
	cout<<x;
}