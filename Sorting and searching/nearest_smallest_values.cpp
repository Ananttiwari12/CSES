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
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];

    }
    
    stack<pair<int,int>>s;

    for(int i=0;i<n;i++){
    	if(s.empty()){
    		cout<<0<<" ";
    		s.push({a[i],i+1});
    	}
    	else{
    		if(a[i]>s.top().first){
    			cout<<s.top().second<<" ";
    			s.push({a[i],i+1});
    		}
    		else{
                
    			while(a[i]<s.top().first){
    				s.pop();
    				if(s.empty()) break;
    			}
                if(s.empty())
    			cout<<0<<" ";
                else{
                    if(s.top().first<a[i])
                    cout<<s.top().second<<" ";
                    else cout<<0<<" ";
                }


    			s.push({a[i],i+1});
    		}
    	}
    }





    
    
    return 0;
}