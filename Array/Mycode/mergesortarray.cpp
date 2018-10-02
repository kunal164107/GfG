#include <iostream>

using namespace std;

void merge(int arr[],int l[],int r[],int n1,int n2){
	
	int i=0,j=0,k=0;
	
	while(i<n1 && j<n2){
		if(l[i]<=r[j]){
			arr[k]=l[i];
			i++;
		}
		else if(r[j]<l[i]){
			arr[k]=r[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		arr[k] = l[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k] = r[j];
		j++;
		k++;
	}
}

void mergesort(int arr[],int n){
	
	if(n==1){
		return;
	}
	
	int mid = n/2;
	int l[mid];
	int r[n-mid];
	
	int k=0;
	for(int i=0;i<mid;i++){
		l[i]=arr[k];
		k++;
	}
	for(int i=0;i<n-mid;i++){
		r[i]=arr[k];
		k++;
	}
	
	mergesort(l,mid);
	mergesort(r,n-mid);
	merge(arr,l,r,mid,n-mid);
	
}


/*

	wrong method of using merge function as it overrides the whole array 

void merge(int* arr,int start1,int end1,int start2,int end2){
	int k = start1;
	while(start1<=end1 && start2<=end2 && k<=end2){
		if(arr[start1]<=arr[start2]){
			arr[k] = arr[start1];
			start1++;
		}
		else{
			arr[k] = arr[start2];
			start2++;
		}
		k++;
	}
	
	while(start1<=end1 && k<=end2){
		arr[k] = arr[start1];
		start1++;
		k++;
	}
	
	while(start2<=end2 && k<=end2){
		arr[k] = arr[start2];
		start2++;
		k++;
	}
	
}

*/

/*

void mergesort(int* arr,int start,int end){

	if(start>=end) return;
	
	int mid = (start+end)/2;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,mid,mid+1,end);
	
}

*/


int main(){
	
	int n=7;
	int arr[] = {2,17,11,1,5,13,27};
	
	mergesort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}