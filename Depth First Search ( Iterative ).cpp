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

map < int , vector < int > > adj,Time;

map < int , int > visit,level,parent;

int Timer;

void DFS(int n){
	
	Timer+=1;
	
	Time[n].push_back(Timer);
	
	stack < int > s;
	
	visit[n]=1;
	
	parent[n]=n;
	
	s.push(n);
	
	while(!s.empty()){
		
		int u=s.top();
		
		int connected=0;
		
		int l=adj[u].size();
		
		for(int i=0; i<l; i+=1){
			
			int v=adj[u][i];
			
			if(visit[v]==0){
				
				connected+=1;
				
				visit[v]=1;
				
				level[v]=level[u]+1;
				
				parent[v]=u;
				
				Timer+=1;
	
				Time[v].push_back(Timer);
				
				s.push(v);
				
				break;
			}
		}
		
		if(connected==0){
			
			Timer+=1;
			
			Time[u].push_back(Timer);
			
			s.pop();
		}
	}
}

int main(){
	
	Timer=0;
	
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
	
	for(int i=1; i<=n; i+=1){
		
		cout<<endl<<"Node\t=\t"<<i;
		
		cout<<endl<<"Start\t=\t"<<Time[i][0];
		
		cout<<endl<<"End\t=\t"<<Time[i][1]<<endl;
	}
}
