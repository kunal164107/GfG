#include <iostream>
#include <vector>
using namespace std;

class pairsum{
	
	public:
		
		void findpair(vector<int> v,int key,int start,int end,int n){
			while(start!=end){
				if(v[start] + v[end] == key){
					cout<<"("<<v[start]<<","<<v[end]<<")"<<endl;
					start = (start+1)%n;
				}
				else if(v[start] + v[end] < key){
					start = (start+1)%n;
				}
				else{
					if(end==0){
						end = n-1;
					}else{
						end--;
					}
				}
			}	
		}
		
		int findpivot(vector<int> arr,int n){
			int start = 0;
			int end = n-1;
			int mid;
		
			while(start<=end){
				mid = (start+end)/2;
				
				if(mid!=0 && mid!= n-1 && arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
					return mid;
				}
				else if(mid==0 && arr[mid]<arr[mid+1]){
					return mid;
				}
				else if(mid==n-1 && arr[mid]<arr[mid-1]){
					return mid;
				}
				
				if(arr[end] < arr[mid]){
					start = mid+1;
				}
				else if(arr[start] > arr[mid]){
					end = mid-1;
				}
				else if(arr[mid] > arr[start] && arr[mid] < arr[end]){
					end = mid-1;
				}
				else if(arr[mid] < arr[start] && arr[mid] > arr[end]){
					start = start + 1;
				}				
			}
			return -1;
		}
	
};

int main(){
	
	vector<int> v = {6, 7, 9, 10};
	int search = 16;
	
	pairsum obj;
	
	int pivot = obj.findpivot(v,v.size());
	
	// cout<<"pivot "<<pivot<<endl;
	
	if(pivot==0){
		obj.findpair(v,search,pivot,v.size()-1,v.size());
	}
	else{
		obj.findpair(v,search,pivot,pivot-1,v.size());
	}
	
	return 0;
}