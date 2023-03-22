#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200001;

int sub[N];
vector<int>gr[N];
int solve(int src, int par){
    int ans=0;
    for(auto x:gr[src]){
        if(x!=par){
            solve(x,src);
            ans+=1+sub[x];
        }

    }
    return sub[src]=ans;

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

    for(int i=2;i<=n;i++){
    	int x; cin>>x;
    	gr[i].push_back(x);
    	gr[x].push_back(i);
    }

    memset(sub,0,sizeof(sub));

    solve(1,0);

    for(int i=1;i<=n;i++){
    	cout<<sub[i]<<" ";
    }



    

    
    
    return 0;
}