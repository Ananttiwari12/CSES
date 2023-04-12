#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200001;
vector<int>gr[N];

int visited[200001];
int color[200001];
int parent[200001];

bool dfs(int src, int col, int par){

    visited[src]=1;
    color[src]=col+1;
    parent[src]=par;

    for(auto child:gr[src]){
        if(!visited[child]){
            if(dfs(child,col^1,src)==false)return false;
        }
        if(color[child]==color[src])return false;
        
    }
    return true;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    memset(visited,0,sizeof(visited));
    memset(color,-1,sizeof(color));

    int cnt=0;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,0,0)==false){
                cnt++;
                break;
            }
        }
    }

    if(cnt==1){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
    }




   
   


    
    
    return 0;
}