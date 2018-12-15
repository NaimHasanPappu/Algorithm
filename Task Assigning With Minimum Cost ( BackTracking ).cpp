#include<bits/stdc++.h>

using namespace std;

map <int,int> work,task;

map < int , map < int , int > > cost;

int Minimum=111111111;

int P=0;

void back_track(int at,int n){
	
	if(at==n){
		
		int c=0;
		
		P+=1;
		
		cout<<"\tPermutation\t\t=\t"<<P<<endl;
		
		cout<<"\tPerson\t\t\t=";
		
		for(int i=0; i<n; i+=1){
			
			cout<<"\t"<<i;
		}
		
		cout<<endl;
		
		cout<<"\tTask\t\t\t=";
		
		for(int i=0; i<n; i+=1){
			
			cout<<"\t"<<task[i];
		}
		
		cout<<endl;
		
		for(int i=0; i<n; i+=1){
			
			c+=cost[i][task[i]];
		}
		
		Minimum=min(Minimum,c);
		
		cout<<"\tCurrent cost\t\t=\t"<<c<<endl;
		
		cout<<"\tMinimum\t\t\t=\t"<<Minimum<<endl<<endl;
		
		return ;
	}
	
	for(int i=0; i<n; i+=1){
		
		if(work[i]==0){
			
			work[i]=1;
			
			task[at]=i;
			
			back_track(at+1,n);
			
			work[i]=0;
		}
	}
}

int main(){
	
	int n;
	
	cin>>n;
	
	for(int i=0; i<n; i+=1){
		
		for(int j=0; j<n; j+=1){
			
			cin>>cost[i][j];
		}
	}
	
	cout<<endl;
	
	back_track(0,n);
	
	cout<<endl<<"\tFinal minimum cost\t=\t"<<Minimum<<endl;
}
