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
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	v.push_back({a[i],i+1});
    }

    sort(v.begin(), v.end());

    int cnt=1;

    int round=v[0].second;
    for(int i=1;i<n;i++){
    	if(v[i].second<round){
    		cnt++;
    	}
		round=v[i].second;
    }
    cout<<cnt;
    return 0;
}