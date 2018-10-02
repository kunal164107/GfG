#include <iostream>

using namespace std;

void merge(int arr[],int start,int end,int mid);
void mergesort(int* arr,int start,int end);

int main(){
	int n = 8;
	int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};

	mergesort(arr,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}

void mergesort(int* arr,int start,int end){

	if(start>=end) return;
	
	int mid = (start+end)/2;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,end,mid);
	
	// cout<<"whole array ";
	// for(int i=0;i<=8;i++){
		// cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	
	// cout<<"after merge ";
	// for(int i=start;i<=end;i++){
		// cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	
	// cout<<"start "<<start<<" end "<<end <<" mid "<<mid<<endl;
	
}

void merge(int* arr,int start,int end,int mid){
	
	// cout<<"start "<<start<<" end "<<end <<" mid "<<mid<<endl;
	
	// for(int i=start;i<=end;i++){
		// cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	
	int n1 = mid - start +1;
	int n2 = end - mid;
	
	int l[n1];
	int r[n2];

	int ptr1 = start,itr1=0;
	while(ptr1<=mid){
		l[itr1] = arr[ptr1];
		ptr1++;
		itr1++;
	}

	int ptr2 = mid+1,itr2=0;
	while(ptr2<=end){
		r[itr2] = arr[ptr2];
		ptr2++;
		itr2++;
	}
	
	
	// cout<<"left ";
	// for(int i=0;i<n1;i++){
		// cout<<l[i]<<" ";
	// }
	// cout<<endl;
	
	// cout<<"right ";
	// for(int i=0;i<n2;i++){
		// cout<<r[i]<<" ";
	// }
	// cout<<endl;
	
	
	int i=0,j=0,k=start;
	
	while(i<n1){
		if(l[i]<0){
			arr[k] = l[i];
			k++;
		} 
		i++;
		
	}
	i=0;
	
	while(j<n2){
		if(r[j]<0){
			arr[k] = r[j];
			k++;
		} 
		j++;
	}
	j=0;
	
	while(i<n1){
		if(l[i]>=0){
			arr[k] = l[i];
			k++;
		} 
		i++;
	}
	
	while(j<n2){
		if(r[j]>=0){
			arr[k] = r[j];
			k++;
		} 
		j++;
	}
	
	// cout<<"whole array in merge ";
	// for(int i=0;i<=8;i++){
		// cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	
	// cout<<"before merge end ";
	// for(int itr=start;itr<=end;itr++){
		// cout<<arr[itr]<<" ";
	// }
	// cout<<endl;
}