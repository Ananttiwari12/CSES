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
    vector<pair<int,int>>v;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    int ans=0;
    int curtime=0;

    sort(v.begin(), v.end());

    for(int i=0;i<n;i++){
        curtime+=v[i].first;
        ans+=(v[i].second-curtime);

    }

    cout<<ans<<endl;
    return 0;
}