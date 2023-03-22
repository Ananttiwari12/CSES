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

    int a[n+1];
    map<int,vector<int>>gr;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int u,v;
    cin>>u>>v;

    if(__gcd(a[u], a[v])>1){
        if(u!=v){
            cout<<2<<"\n"<<u<<" "<<v<<"\n";
        }else{
            cout<<1<<"\n"<<u<<"\n";
        }
        return 0;
    }
    
    for(int i=1;i<=n;i++){
        if((__gcd(a[u],a[i])>1 and i!=u)){
            gr[u].push_back(i);
            gr[i].push_back(u);
        }
        if((__gcd(a[v],a[i])>1 and i!=v)){
            gr[v].push_back(i);
            gr[i].push_back(v);
        }
    }

    int dis[n+2];
    memset(dis,-1,sizeof(dis));
    bool visited[n+2];
    memset(visited,0,sizeof(visited));
    int par[n+2]{-2};


    queue<int>q;
    q.push(u);
    visited[u]=1;
    dis[u]=1;
    par[u]=-2;
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto nbr: gr[node]){
            if(!visited[nbr] and nbr!=node){
                q.push(nbr);
                visited[nbr]=1;
                dis[nbr]=dis[node]+1;
                par[nbr]=node;
            }
        }
    }


    cout<<dis[v]<<endl;
    if(dis[v]!=-1){
        vector<int>path;

        while(v!=-2){
            path.push_back(v);
            v=par[v];
        }

    reverse(path.begin(), path.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }


}





    

    
    
    return 0;
}