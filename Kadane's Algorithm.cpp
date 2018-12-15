#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	
	cin>>n;
	
	int arr[n];
	
	for(int i=0; i<n; i+=1){
		
		cin>>arr[i];
	}
	
	int final_max_sum = arr[0] , current_max_sum = arr[0];
	
	for(int i=1; i<n; i+=1){
		
		current_max_sum = max ( arr[i] , current_max_sum + arr[i] );
		
		final_max_sum 	= max ( final_max_sum , current_max_sum );
	}
	
	cout<<endl<<"Maximum sum = "<<final_max_sum<<endl;
}
