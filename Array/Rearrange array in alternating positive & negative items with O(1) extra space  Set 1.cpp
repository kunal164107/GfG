#include<iostream>

using namespace std;

void rotateright(int* arr,int start,int end);
int main(){
	int n = 9;
	int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
	
	int outofindex=-1,k=0;
	
	while(k<n){
		
		if(outofindex>=0){
			int next = outofindex + 1;
			while(next<n){
				if(arr[outofindex]>=0){
					if(arr[next]<0){
						break;
					}
				}
				else{
					if(arr[next]>=0){
						break;
					}
				}
				next++;
			}
			
			// cout<<"outofindex "<<outofindex<<" next "<<next<<endl;
			
			if(outofindex<n && next<n){
				rotateright(arr,outofindex,next);
				outofindex = -1;
			}
			
		}
	
		else{
			if((k%2==0 && arr[k]>=0) || (k%2!=0 && arr[k]<0)){
				outofindex = k;
			}
		}
		
		
		// for(int i=0;i<n;i++){
			// cout<<arr[i]<<" ";
		// }
		// cout<<endl;
		
		
		k++;
	}
	
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

void rotateright(int* arr,int start,int end){
	int temp=arr[end];
	for(int i=end;i>=start;i--){
		if(i!=start) arr[i] = arr[i-1];
	}
	arr[start] = temp;
}