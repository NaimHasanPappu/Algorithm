#include<bits/stdc++.h>

using namespace std;

#define wn pair < int , int >

void Prim(){
	
	cout<<endl<<"How many nodes?"<<endl;
	
	int node;
	
	cin>>node;
	
	vector <wn> adj[node+1];
	
	vector <int> visit;
	
	for(int i=0; i<=node; i+=1){
		
		visit.push_back(0);
	}
	
	cout<<endl<<"How many edges?"<<endl;
	
	int edges;
	
	cin>>edges;
	
	cout<<endl<<"Enter nodes and weight"<<endl;
	
	for(int i=0; i<edges; i+=1){
		
		int u,v,w;
		
		cin>>u>>v>>w;
		
		adj[u].push_back(make_pair(w,v));
		
		adj[v].push_back(make_pair(w,u));
	}
	
	cout<<endl<<"Enter starting node"<<endl;
	
	int n;
	
	cin>>n;
	
	int MinCost=0;
	
	priority_queue < wn , vector <wn> , greater <wn> > Q;
	
	Q.push(make_pair(0,n));
	
	while(!Q.empty()){
		
		wn p=Q.top();
		
		Q.pop();
		
		int u=p.second;
		
		if(visit[u]==1){
			
			continue;
		}
		
		visit[u]=1;
		
		MinCost+=p.first;
		
		int l=adj[u].size();
		
		for(int i=0; i<l; i+=1){
			
			int v=adj[u][i].second;
			
			if(!visit[v]){
				
				Q.push(adj[u][i]);
			}
		}
	}
	
	cout<<endl<<"Minimum cost = "<<MinCost<<endl;
}

int main(){
	
	Prim();
}
