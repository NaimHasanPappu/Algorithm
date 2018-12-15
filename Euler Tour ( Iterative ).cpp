/*
	11 10
	
	1 2
	1 3
	2 4
	2 5
	3 6
	3 7
	5 8
	5 9
	5 10
	6 11
*/

#include<bits/stdc++.h>

using namespace std;

map < int , vector < int > > adj;

map < int , int > visit;

vector < int > Euler;

void DFS(int n){
	
	stack <int> s;
	
	s.push(n);
	
	visit[n]=1;
	
	while(!s.empty()){
		
		int u=s.top();
		
		Euler.push_back(u);
		
		int l=adj[u].size();
		
		int connected=0;
		
		for(int i=0; i<l; i+=1){
			
			int v=adj[u][i];
			
			if(visit[v]==0){
				
				visit[v]=1;
				
				s.push(v);
				
				connected+=1;
				
				break;
			}
		}
		
		if(connected==0){
			
			s.pop();
		}
	}
}

int main(){
	
	int n,m;
	
	cin>>n>>m;
	
	for(int i=0; i<m; i+=1){
		
		int u,v;
		
		cin>>u>>v;
		
		adj[u].push_back(v);
		
		adj[v].push_back(u);
	}
	
	for(int i=1; i<=n; i+=1){
		
		if(visit[i]==0){
			
			DFS(i);
		}
	}
	
	int l=Euler.size();
	
	for(int i=0; i<l; i+=1){
		
		cout<<" "<<Euler[i];
	}
}
