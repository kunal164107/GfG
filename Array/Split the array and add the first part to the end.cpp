#include <iostream>
using namespace std;

class split{
	public:
	
		split(int n,int* arr){
			int temp;
			for(int i=0;i<n;i++){
				cin>>temp;
				arr[i] = temp;
			}
		}
		
		void reversal(int* arr,int start,int end){
			while(start<=end){
				swap(arr[start],arr[end]);
				start++;
				end--;
			}
		}
		
};


int main(){
	int n;
	cin>>n;
	int arr[n];
	split obj(n,arr);
	int k;
	cin>>k;
	obj.reversal(arr,0,k-1);
	obj.reversal(arr,k,n-1);
	obj.reversal(arr,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}