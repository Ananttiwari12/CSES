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

    int n,k; cin>>n>>k;
    int a[n];

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    int j=0;
    int ans=0;
    map<int,int>mp;
    
    for(int i=0;i<n;i++){
    	while((j<n and mp.size()<k )|| mp.count(a[j])>0){
    		mp[a[j]]++;
    		j++;
    	}
    	int len=j-i;
    	ans+=len;
    	mp[a[i]]--;
    	if(mp[a[i]]==0){
    		mp.erase(mp.find(a[i]));
    	}
    }
   cout<<ans;

    return 0;
}