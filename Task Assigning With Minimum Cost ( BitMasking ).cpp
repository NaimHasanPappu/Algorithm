#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int on_bit(int n){
	
	int c=0;
	
	while(n){
		
		if(n&1){
			
			c+=1;
		}
		
		n>>1;
	}
	
	return c;
}

int main(){
	
	int n;
	
	cin>>n;
	
	int cost[n][n];
	
	int N=(1<<n);
	
	int dp[N+1];
	
	for(int i=0; i<=N; i+=1){
		
		dp[i]=100000;
	}
	
	for(int i=0; i<n; i+=1){
		
		for(int j=0; j<n; j+=1){
			
			cin>>cost[i][j];
		}
	}
	
	dp[0]=0;
	
	for(int mask=0; mask<=N; mask+=1){
		
		cout<<endl<<mask;
		
		int k=on_bit(mask);
		
		for(int j=0; j<n; j+=1){
			
			cout<<" "<<j;
			
			if(!(mask&(1<<j))){
				
				cout<<" "<<j;
				
				dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+cost[k][j]);
			}
			
			cout<<endl;
		}
	}
}
