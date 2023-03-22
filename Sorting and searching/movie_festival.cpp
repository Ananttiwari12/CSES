#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

bool compare(pair<int,int>&a, pair<int,int>&b){
	return a.second<b.second;
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
    	v.push_back({x,y});
    }

    sort(v.begin(),v.end(),compare);

    int end=v[0].second;
    int cnt=1;

    for(int i=1;i<n;i++){
    	if(v[i].first>=end){
    		cnt++;
    		end=max(end,v[i].second);
    	}
    }
    cout<<cnt;
    

    
    
    return 0;
}