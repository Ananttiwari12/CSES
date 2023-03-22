#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

bool compare(pair<int,int>&a, pair<int,int>&b){
	if(a.second<b.second)return true;
	
	return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int n,k; cin>>n>>k;
    vector<pair<int,int>>v;

    for(int i=0;i<n;i++){
    	int x,y; cin>>x>>y;
    	v.push_back({x,y});
    }

    sort(v.begin(), v.end(),compare);

    set<pair<int,int>>s;

    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){

    	if(s.size()==0){
    		s.insert({v[i].second*-1,i});
    		ans++;
    	}
    	else{
    		auto it=s.lower_bound({v[i].first,-1});
    		if(it!=s.end()){
    			s.erase(it);
    			s.insert({v[i].second*-1,i});
    			ans++;
    		}

    		else if(it==s.end() and s.size()<k){
    			s.insert({v[i].second*-1,i});
    			ans++;
    		}
    	}
    	}
    cout<<ans;

    
    
    return 0;
}