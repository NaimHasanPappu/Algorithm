#include<bits/stdc++.h>

using namespace std;

#define P3 pair < int , pair < int , int > >

vector <int> parent;

vector <P3> arr;

int make(int node){
	
	parent.clear();
	
	for(int i=0; i<=node; i+=1){
		
		parent.push_back(i);
	}
}

int root(int n){
	
	while(parent[n]!=n){
		
		parent[n]=parent[parent[n]];
		
		n=parent[n];
	}
	
	return n;
}

void siblings(int p,int q){
	
	int x=root(p);
	
	int y=root(q);
	
	if(parent[x]<parent[y]){
		
		parent[y]=parent[x];
	}
	
	else{
		
		parent[x]=parent[y];
	}
}

void Kruskal(){
	
	//cout<<endl<<"How many nodes?"<<endl;
	
	int node;
	
	cin>>node;
	
	make(node);
	
	//cout<<endl<<"How many edges?"<<endl;
	
	int edges;
	
	cin>>edges;
	
	//cout<<endl<<"Enter nodes and weight"<<endl;
	
	for(int i=0; i<edges; i+=1){
		
		int n1,n2,w;
		
		cin>>n1>>n2>>w;
		
		P3 p=make_pair(w,make_pair(n1,n2));
		
		arr.push_back(p);
	}
	
	sort(arr.begin(),arr.end());
	
	int MinCost=0;
	
	for(int i=0; i<edges; i+=1){
		
		int n1=arr[i].second.first;
		
		int n2=arr[i].second.second;
		
		int w=arr[i].first;
		
		if(root(n1)!=root(n2)){
			
			siblings(n1,n2);
			
			MinCost+=w;
		}
	}
	
	//cout<<endl<<"Minimum cost is = "<<MinCost<<endl;
	
	cout<<MinCost;
}

int main(){
	
	Kruskal();
}
