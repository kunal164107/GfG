#include<iostream>
#include<math.h>
using namespace std;

void printEgyptian(int nr,int dr){
	
	if(dr%nr == 0){
		cout<<"1"<<"/"<<dr/nr<<endl;
		return;
	} 
	
	int next_unit_fraction_nr = 1;
	int next_unit_fraction_dr = (int)ceil((float)dr/nr);
	
	nr = nr*next_unit_fraction_dr - dr*next_unit_fraction_nr;
	dr = dr*next_unit_fraction_dr;
	
	cout<<next_unit_fraction_nr<<"/"<<next_unit_fraction_dr<<" + ";
	printEgyptian(nr,dr);
	
}

int main(){
	int nr = 12, dr = 13;
	printEgyptian(nr, dr);
	
	return 0;
}