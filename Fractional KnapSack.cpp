#include<bits/stdc++.h>

using namespace std;

typedef pair <int , int> PII;

vector <PII> arr;

bool comp(PII a , PII b){
	
	return a.second*b.first > a.first*b.second;
}

void Knap_Sack(){
	
	printf("\nNumber of item\n");
	
	int item;
	
	cin>>item;
	
	printf("\nEnter their weight and price\n");
	
	for(int i=0; i<item; i+=1){
		
		int w,p;
		
		cin>>w>>p;
		
		arr.push_back(PII(w,p));
	}
	
	sort(arr.begin(),arr.end());
	
	printf("\nEnter maximum capacity\n");
	
	int W;
	
	cin>>W;
	
	int ans=0;
	
	for(int i=0; i<item; i+=1){
		
		int z = min(W,arr[i].first);
		
		W -= z;
		
		ans+=z*arr[i].second;
	}
	
	printf("Maximum profit is = ");
	
	cout<<ans<<endl;
}

int main(){
	
	Knap_Sack();
}
