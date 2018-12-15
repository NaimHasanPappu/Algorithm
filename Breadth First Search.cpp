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

map < int , int > visit,level,parent;

void DFS(int n){
	
	stack < int > s;
	
	visit[n]=1;
	
	parent[n]=n;
	
	s.push(n);
	
	while(!s.empty()){
		
		int u=s.top();
		
		cout<<" "<<u;
		
		visit[u]=1;
		
		int connected=0;
		
		int l=adj[u].size();
		
		for(int i=0; i<l; i+=1){
			
			int v=adj[u][i];
			
			if(visit[v]==0){
				
				connected+=1;
				
				visit[v]=1;
				
				level[v]=level[u]+1;
				
				parent[v]=u;
				
				s.push(v);
				
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
	
	DFS(1);
	
	cout<<endl;
}
