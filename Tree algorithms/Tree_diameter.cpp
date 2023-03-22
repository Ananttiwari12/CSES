#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int visited[N];
int helper_node;
int distan[N];
int maxdis=-1;

int dfshelper(int src, int dist){
    distan[src]=dist;
    visited[src]=1;
    if(dist>maxdis){
        helper_node=src;
        maxdis=dist;
    }
    for(auto child: gr[src]){
        if(!visited[child]){
            dfshelper(child, distan[src]+1);
        }
    }
    return helper_node;
}

void dfs(int src, int par){
    visited[src]=1;
    distan[src]=par;
    for(auto child: gr[src]){
        if(!visited[child]){
            dfs(child, distan[child]+1);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    for(int i=0; i<n-1;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    int helpernode=dfshelper(1,0);

    for(int i=1;i<=n;i++){
        distan[i]=0;
        visited[i]=0;
    }
    dfs(helpernode,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,distan[i]);
    }
    cout<<ans<<endl;
    
    return 0;
}