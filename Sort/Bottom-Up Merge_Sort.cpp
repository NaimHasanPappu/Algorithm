#include<bits/stdc++.h>
 
using namespace std;
 
vector <int> vec;
 
void merge ( int fi , int li ){
 
	vector <int> arr1, arr2;
 
	int mi = ( fi + li ) / 2;
 
 
	// Making 1st sub array.
 
	for ( int i = fi; i <= mi; i += 1 ){
 
		arr1.push_back ( vec[i] );
	}
 
 
	// Making 2nd sub array.
 
	for ( int i = mi+1; i <= li; i += 1 ){
 
		arr2.push_back ( vec[i] );
	}
 
 
	int l1 = arr1.size();
 
	int l2 = arr2.size();
 
	//	Here both sub-array index started from 0, but orginal array index started from fi.
	//	Let assume that we are merging 2 sub array whose starting index are 5 & 10.
	//	So when we merge them to their orginal array then orginal array index will be started from 5.
 
	int i = 0, j = 0, k = fi;
 
	//	Merging 2 sub-arrays.
 
	while ( i < l1 && j < l2 ){
 
		if ( arr1[i] < arr2[j] ){
 
			vec[k] = arr1[i];
 
			i += 1;
		}
 
		else{
 
			vec[k] = arr2[j];
 
			j += 1;
		}
 
		k += 1;
	}
 
	while ( i < l1 ){
 
		vec[k] = arr1[i];
		
		i += 1;
		
		k += 1;
	}
 
	while ( j < l2 ){
 
		vec[k] = arr2[j];
		
		j += 1;
		
		k += 1;
	}
}

void mergesort ( int fi , int li ){
	
	if ( fi < li ){
		
		int mi = ( fi + li ) / 2;
		
		mergesort ( fi , mi );
		
		mergesort ( mi + 1 , li );
		
		merge ( fi , li );
	}
}
 
int main(){
 
	int n;
 
	cin>>n;
 
	for ( int i = 0; i < n; i += 1 ){
 
		int y;
 
		cin>>y;
 
		vec.push_back( y );
	}
 
	mergesort ( 0 , n-1 );
 
	for ( int i = 0; i < n; i += 1 ){
 
		cout<<"\t"<<vec[i];
	}
}
