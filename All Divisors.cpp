#include<bits/stdc++.h>

using namespace std;

int main(){
	
	vector <int> v[1000];
	
	for(int i=1; i<=25; i+=1){
		
		for(int j=i; j<=25; j+=i){
			
			v[j].push_back(i);
		}
	}
	
	for(int i=1; i<=25; i+=1){
		
		int l=v[i].size();
		
		cout<<endl<<i<<"\t";
		
		for(int j=0; j<l; j+=1){
			
			cout<<" "<<v[i][j];
		}
		
		cout<<endl;
	}
}
