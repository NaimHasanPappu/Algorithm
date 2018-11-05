#include<bits/stdc++.h>

using namespace std;

void LCA(){
	
	cout<<endl<<"How many nodes?"<<endl;
	
	int Nodes;
	
	cin>>Nodes;
	
	vector <int> Graph[Nodes+1];
	
	cout<<endl<<"How many edges?"<<endl;
	
	int Edges;
	
	cin>>Edges;
	
	cout<<endl<<"Enter nodes having edges"<<endl;
	
	for(int i=0; i<Edges; i+=1){
		
		int u,v;
		
		cin>>u>>v;
		
		Graph[u].push_back(v);
		
		Graph[v].push_back(u);
	}
	
	vector <int> Parent,Visit,Level;
	
	for(int i=0; i<=Nodes; i+=1){
		
		Parent.push_back(-1);
		
		Visit.push_back(0);
		
		Level.push_back(0);
	}
	
	queue <int> q;
	
	q.push(1);
	
	Visit[1]=1;
	
	while(!q.empty()){
		
		int u=q.front();
		
		q.pop();
		
		int N=Graph[u].size();
		
		for(int i=0; i<N; i+=1){
			
			int v=Graph[u][i];
			
			if(Visit[v]==0){
				
				Visit[v]=1;
				
				Parent[v]=u;
				
				Level[v]=Level[u]+1;
				
				q.push(v);
			}
		}
	}
	
	int N = 1+(floor)(log2(Nodes));
	
	vector <int> Sparse_Table[Nodes+1];
	
	for(int i=1; i<=Nodes; i+=1){
		
		for(int j=0; j<=N; j+=1){
			
			Sparse_Table[i].push_back(-1);
		}
	}
	
	for(int i=1; i<=Nodes; i+=1){
		
		Sparse_Table[i][0]=Parent[i];
	}
	
	for(int j=1; j<=N; j+=1){
		
		for(int i=1; i<=Nodes; i+=1){
			
			if(Sparse_Table[i][j-1] != -1){
				
				Sparse_Table[i][j] = Sparse_Table [ Sparse_Table[i][j-1] ] [j-1];
			}
		}
	}
	
	while(1){
	
		cout<<endl<<"Enter two nodes whose LCA you want to find"<<endl;
		
		int u,v,U,V;
		
		cin>>U>>V;
		
		u=U;
		
		v=V;
		
		if(Level[u]<Level[v]){
			
			swap(u,v);
		}
		
		int Depth=Level[u]-Level[v];
		
		while(Depth>0){
			
			int Raise = (log2(Depth));
			
			u=Sparse_Table[u][Raise];
			
			Depth-=(1<<Raise);
		}
		
		if(u==v){
			
			cout<<endl<<u<<" is the LCA of "<<U<<" and "<<V<<endl;
		}
		
		else{
		
			for(int j=N; j>=0; j-=1){
				
				if( Sparse_Table[u][j] != -1 && ( Sparse_Table[u][j] != Sparse_Table[v][j] ) ){
					
					u=Sparse_Table[u][j];
					
					v=Sparse_Table[v][j];
				}
			}
			
			cout<<endl<<Parent[u]<<" is the LCA of "<<U<<" and "<<V<<endl;
		}
	}
}

int main(){
	
	LCA();
}
