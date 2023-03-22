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
    int n,m; cin>>n>>m;
    int a[n+1];
    
    int pos[n+1];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	pos[a[i]]=i;
    }

    int ans=1;

    for(int i=1;i<=n-1;i++){
    	if(pos[i]>pos[i+1]){
    		ans++;
    	}
    }

    set<pair<int,int>>s;

    for(int i=0;i<m;i++){

    	int x,y; cin>>x>>y;



    	if(a[x]-1>=1){
    		s.insert({a[x]-1,a[x]});
    	}
    	if(a[x]+1<=n){
    		s.insert({a[x],a[x]+1});
    	}
    	if(a[y]-1>=1){
    		s.insert({a[y]-1,a[y]});
    	}
    	if(a[y]+1<=n){
    		s.insert({a[y],a[y]+1});
    	}

    	for(auto val: s){
    		if(pos[val.first]>pos[val.second]){
    			ans--;
    		}
    	}

    	swap(a[x],a[y]);
    	pos[a[x]]=x;
    	pos[a[y]]=y;
    	for(auto val:s){
    		if(pos[val.first]>pos[val.second])ans++;
    	}
    	cout<<ans<<endl;
    	s.clear();
    }




    
    return 0;
}