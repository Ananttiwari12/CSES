#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

bool compare(pair<int,int>&a, pair<int,int>&b){
    if(a.second>=b.second)return true;
    return false;
    // return a.second>b.second;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
    	int x,y; cin>>x>>y;
    	v.push_back({x,1});
        v.push_back({y,-1});
    }

    sort(v.begin(), v.end());
    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i].second;
        ans=max(sum,ans);
    }
    cout<<ans;
    return 0;
}