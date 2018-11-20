#include<bits/stdc++.h>

using namespace std;

vector <int> arr;

void Kadane1(int n){
	
	int final_max_sum = 0 , current_max_sum = 0;
	
	for(int i=0; i<n; i+=1){
		
		current_max_sum += arr[i];
		
		if(current_max_sum < 0){
			
			current_max_sum = 0;
		}
		
		else if(final_max_sum < current_max_sum){
			
			final_max_sum = current_max_sum;
		}
	}
	
	cout<<endl<<"Maximum sum = "<<final_max_sum<<endl;
}

void Kadane2(int n){
	
	int final_max_sum = arr[0] , current_max_sum = arr[0];
	
	for(int i=1; i<n; i+=1){
		
		current_max_sum = max ( arr[i] , current_max_sum + arr[i] );
		
		final_max_sum 	= max ( final_max_sum , current_max_sum );
	}
	
	cout<<endl<<"Maximum sum = "<<final_max_sum<<endl;
}

int main(){
	
	int n;
	
	cin>>n;
	
	for(int i=0; i<n; i+=1){
		
		int x;
		
		cin>>x;
		
		arr.push_back(x);
	}
	
	Kadane1(n);
	
	Kadane2(n);
}
