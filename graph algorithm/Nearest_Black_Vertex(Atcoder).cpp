#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
const int N=2000;
vector<int>gr[N+1];
int dist[N+1][N+1];
int visited[N+1];
int node[N+1];
int d[N+1];
int col[N+1];
void bfs(int i){
    dist[i][i]=0;
    queue<int>q;
    q.push(i);
    visited[i]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto x:gr[f]){
            if(!visited[x]){
                visited[x]=1;
                dist[i][x]=dist[i][f]+1;
                q.push(x);
            }
        }
    }
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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=1e9;
        }
    }
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        bfs(i);
    }
    int k; cin>>k;
    for(int i=1;i<=k;i++){
        int u,di; cin>>u>>di;
        node[i]=u;
        d[i]=di;
    }
    // color::  0->white, 1->black
    for(int i=1;i<=n;i++){
        col[i]=1;
    }
    for(int i=1;i<=k;i++){
        int u=node[i];
        int dis=d[i];
        for(int j=1;j<=n;j++){
            if(dist[u][j]<dis){
                col[j]=0;
            }
        }
    }

    int cnt=0;
    for(int i=1;i<=k;i++){
        int u=node[i];
        int dis=d[i];
        int mn=1e9;
        for(int j=1;j<=n;j++){
            if(col[j]){
                mn=min(mn,dist[u][j]);
            }
        }
        if(mn!=dis){
            cnt++;
            break;
        }
    }

    if(cnt){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
        for(int i=1;i<=n;i++){
            cout<<col[i];
        }
    } 
    return 0;
}