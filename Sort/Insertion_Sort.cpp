#include<bits/stdc++.h>

using namespace std;

void insertion_sort(){
	
	int n;
	
	cin>>n;
	
	int arr[n];
	
	for(int i=0; i<n; i+=1){
		
		cin>>arr[i];
	}
	
	for(int i=1; i<n; i+=1){
		
		int p=arr[i];
		
		int j;
		
		for(j=i-1; j>=0; j-=1){
			
			if(p<arr[j]){
				
				arr[j+1]=arr[j];
			}
			
			else{
				
				break;
			}
		}
		
		arr[j+1]=p;
	}
	
	cout<<endl;
	
	for(int i=0; i<n; i+=1){
		
		cout<<"\t"<<arr[i];
	}
	
	cout<<endl;
}

int main(){
	
	while(1){
		
		insertion_sort();
	}
}
