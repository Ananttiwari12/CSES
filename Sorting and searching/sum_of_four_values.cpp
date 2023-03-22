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

    int n,x; cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    map<int,pair<int,int>>mp;
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		if(mp.count(x-a[i]-a[j])){
    			cout<<i+1<<" "<<j+1<<" "<<mp[x-a[i]-a[j]].first+1<<" "<<mp[x-a[i]-a[j]].second+1;
    			return 0;
    		}
    	}
    	for(int j=0;j<i;j++){
    		mp[a[i]+a[j]]={i,j};
    	}
    }
    cout<<"IMPOSSIBLE";
    return 0;
}