#include<bits/stdc++.h>

using namespace std;

int m=10;
	
vector <int> adj[12],euler,level;

int visit[12],index[12],L[12];

void dfs(int u){
	
	visit[u]=1;
	
	euler.push_back(u);
	
	level.push_back(L[u]);
	
	int l=adj[u].size();
	
	for(int i=0; i<l; i+=1){
		
		int v=adj[u][i];
		
		if(visit[v]==0){
			
			L[v]=L[u]+1;
			
			dfs(v);
			
			euler.push_back(u);
			
			level.push_back(L[u]);
		}
	}
}

int main(){
	
	for(int i=0; i<m; i+=1){
		
		int u,v;
		
		cin>>u>>v;
		
		adj[u].push_back(v);
		
		adj[v].push_back(u);
	}
	
	dfs(1);
	
	for(int i=0; i<euler.size(); i+=1){
		
		cout<<" "<<euler[i];
	}
}
