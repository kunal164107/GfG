#include <iostream>
using namespace std;

class hamming_distance{
	public:
		int rotatebyone(int* arr, int* brr, int n){
			int count=0,maxcount=0;
			for(int i=0;i<n;i++){
				int temp = brr[n-1];
				for(int j=n-1;j>=0;j--){
					if(j!=0) brr[j] = brr[j-1];
				}
				brr[0] = temp;
				
				// cout<<"after rotate: ";
				// for(int i=0;i<n;i++){
					// cout<<brr[i]<<" ";
				// }
				// cout<<endl;
				
				for(int i=0;i<n;i++){
					if(arr[i]!=brr[i]) count++;
				}
				// cout<<"count "<<count<<endl;
				
				if(count>maxcount) maxcount = count;
				
				count = 0;
			}
			
			return maxcount;
		}
};

int main(){
	int arr[] = {2, 4, 8, 0};
	int brr[] = {2, 4, 8, 0};
	
	hamming_distance obj;
	cout<<"max hamming distance: "<<obj.rotatebyone(arr,brr,4);
	return 0;
	
}