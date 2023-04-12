#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=2511;
int n,m;
vector<int>dist;
vector<int>parent;
struct e{
    int f,s,d;
};
vector<e>edges;
void bellman_ford(){

    int x;
    for(int i=1;i<=n;i++){
        x=-1;
        for(auto ed: edges){
            int u=ed.f;
            int v=ed.s;
            int w=ed.d;

            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                x=v;
            }
        }
    }

    if(x==-1){
        cout<<"NO";
        return;
    }

    for(int i=1;i<=n;i++){
        x=parent[x];
    }

    vector<int>cycles;

    for(int v=x; ;v=parent[v]){
        cycles.push_back(v);
        if(v==x and cycles.size()>1)break;
    }

    reverse(cycles.begin(), cycles.end());
    cout<<"YES"<<endl;

    for(auto x: cycles)cout<<x<<" ";
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;

    edges.resize(m);
    dist.resize(n+1);
    parent.resize(n+1);

    for(int i=0;i<m;i++){
        
        e inp;
        cin>>inp.f>>inp.s>>inp.d;
        edges[i]=inp;

    }

    for(int i=1;i<=n;i++){
        parent[i]=-1;
    }
    bellman_ford();

    return 0;
}