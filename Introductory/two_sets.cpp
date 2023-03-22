#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;

    if((n*(n+1)/2)%2!=0){
    	cout<<"NO"<<endl;
    }
    else{

    	int a[n];
    	int sum=0;
    	for(int i=0;i<n;i++){
    		a[i]=i+1;
    		sum+=a[i];
    	}
    	sum/=2;

    	
    	
    	int ans=0;

    		vector<int>v,v2;
    		for(int i=n;i>=1;i--){
    			if(ans+i<sum){
    				v.push_back(i);
    				ans+=i;
    			}
    			else if(ans+i>sum){
    				v2.push_back(i);
    			}

    			else if(ans+i==sum){
    				v.push_back(i);
    				ans+=i;
    			}


    		}

    		if(ans==sum){
    			cout<<"YES"<<endl;
    		
    		cout<<v.size()<<endl;
    		for(int i=0;i<v.size();i++){
    			cout<<v[i]<<" ";
    		}
    		cout<<endl;

    		cout<<v2.size()<<endl;
    		for(int i=0;i<v2.size();i++){
    			cout<<v2[i]<<" ";
    		}
    		cout<<endl;

    	}


    	
    	else cout<<"NO"<<endl;












    }


    

    
    
    return 0;
}