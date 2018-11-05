#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int phi[101],mark[101];
	
	for(int i=0; i<=100; i+=1){
		
		phi[i]=i;
		
		mark[i]=1;
	}
	
	for(int i=2; i<=100; i+=1){
		
		if(mark[i]==1){
			
			for(int j=i; j<=100; j+=i){
				
				mark[j]=0;
				
				phi[j]/=i;
				
				phi[j]*=(i-1);
			}
		}
	}
	
	for(int i=1; i<=100; i+=1){
		
		cout<<endl<<"Number="<<i<<endl<<"Number's of co-prime="<<phi[i]<<endl;
	}
}
