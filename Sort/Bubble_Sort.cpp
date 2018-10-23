#include<bits/stdc++.h>

using namespace std;

void selection_sort(){
	
	int n;
	
	cin >> n;
	
	cout << endl;
	
	int arr[n];
	
	for ( int i = 0 ; i < n ; i += 1 ){
		
		cin >> arr[i];
	}
	
	for ( int i = 0 ; i+1 < n ; i += 1 ){
		
		for ( int j = i+1 ; j < n ; j += 1 ){
			
			if ( arr[i] > arr[j] ){
				
				swap ( arr[i] , arr[j] );
			}
		}
	}
	
	cout << endl;
	
	for ( int i = 0 ; i < n ; i += 1 ){
		
		cout << "\t" << arr[i];
	}
	
	cout << endl << endl;
}

int main(){
	
	while ( 1 ){
		
		selection_sort();
	}
}
