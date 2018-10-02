#include<bits/stdc++.h>
using namespace std;

class ugly_num{
	public:
		unsigned int getUgly(int n);
};

unsigned int ugly_num::getUgly(int n){
	unsigned int ugly[n];
	ugly[0] = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	unsigned next_multiple_of_2 = 2;
	unsigned next_multiple_of_3 = 3;
	unsigned next_multiple_of_5 = 5;
	
	unsigned next_ugly_no = 1;
	
	for(int i=1;i<n;i++){
		next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
		ugly[i] = next_ugly_no;
		
		// cout<<next_ugly_no<<endl;
	
		if(next_ugly_no == next_multiple_of_2){
			i2 = i2+1;
			next_multiple_of_2 = ugly[i2]*2;
		}
		
		if(next_ugly_no == next_multiple_of_3){
			i3 = i3+1;
			next_multiple_of_3 = ugly[i3]*3;
		}
		
		if(next_ugly_no == next_multiple_of_5){
			i5 = i5+1;
			next_multiple_of_5 = ugly[i5]*5;
		}
	}
	
	return ugly[n-1];
	
}

int main(){
	
	int n = 15000;
	ugly_num obj;
	cout<<obj.getUgly(n);
	
	return 0;
}