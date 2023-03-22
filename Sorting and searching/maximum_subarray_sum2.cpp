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

    int n,a,b;
    cin>>n>>a>>b;

    int ar[n];

    for(int i=0;i<n;i++){
    	cin>>ar[i];
    }

    int pre[n+1];
    pre[0]=0;

    for(int i=0;i<n;i++){
    	pre[i+1]=pre[i]+ar[i];
    }

    set<pair<int,int>>s;

    for(int i=a;i<=b;i++){
    	s.insert({pre[i],i});
    }

    int maxi=-1e18;
    for(int i=1;i<=n-a+1;i++){
    	maxi= max(maxi, s.rbegin()->first-pre[i-1]);
        s.erase({pre[i+a-1],i+a-1});
        if(i+b<=n){
            s.insert({pre[i+b],i+b});
        }
    }

    cout<<maxi;


    
    return 0;
}