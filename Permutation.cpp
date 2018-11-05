#include<bits/stdc++.h>

using namespace std;

int arr[10],taken[10];

void backtrack(int index,int n){
	
	if(index==n){
		
		cout<<endl;
		
		for(int i=0; i<n; i+=1){
			
			cout<<"\t"<<arr[i];
		}
		
		cout<<endl;
		
		return;
	}
	
	for(int i=0; i<n; i+=1){
		
		if(taken[i]==0){
			
			taken[i]=1;
			
			arr[index]=i;
			
			backtrack(index+1,n);
			
			taken[i]=0;
		}
	}
}

int main(){
	
	int n;
	
	cin>>n;
	
	backtrack(0,n);
}
