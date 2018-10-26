#include<bits/stdc++.h>

using namespace std;

int main(){
	
	string Pattern,String;
	
	cout<<endl<<"Enter a string"<<endl;
	
	cin>>String;
	
	cout<<endl<<"Enter pattern"<<endl;
	
	cin>>Pattern;
	
	string Z = Pattern+"*"+String;
	
	int n=Z.length();
	
	vector <int> z;
	
	for(int i=0; i<=n; i+=1){
		
		z.push_back(0);
	}
	
	int L = 0, R = 0;
	
	for (int i = 1; i < n; i+=1){
		
    	if (i > R){
    		
        	L = R = i;
        
        	while (R < n && Z[R-L] == Z[R]){
        	
    			R+=1;
        	}
        
        	z[i] = R-L; 
        
        	R-=1;
    	}
    		
    	else{
    		
        	int k = i-L;
        	
        	if (z[k] < R-i+1){
        		
            	z[i] = z[k];
       		}
       		
        	else{
        		
            	L = i;
            	
            	while (R < n && Z[R-L] == Z[R]){
            		
                	R+=1;
            	}
            	
            	z[i] = R-L; 
            	
            	R-=1;
        	}
   		}
	}
	
	int l=z.size();
	
	int count=0;
	
	for(int i=0; i<l; i+=1){
		
		if(z[i]==Pattern.length()){
			
			count+=1;
		}
	}
	
	cout<<endl<<"Pattern found "<<count<<" times"<<endl;
}
