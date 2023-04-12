#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=100001;
vector<pair<int,int>>gr[N];
vector<pair<int,int>>rev_gr[N];
int visited[N];
int dist1[N], dist2[N];
int n,m;

struct edges{
    int a,b,w;
};

void dijikstra(int src, int dist[],vector<pair<int,int>>gr[]){

    for(int i=0;i<N;i++){
        dist[i]=(int)1e17;
    }

    dist[src]=0;
    set<pair<int,int>>s;
    s.insert({0,src}); // dist node

    visited[src]=1;

    while(!s.empty()){

        auto f=*s.begin();
        s.erase(f);

        int dist_till_now=f.first;
        int node=f.second;

        for(auto nbr_pair: gr[node]){

            int child=nbr_pair.first;
            int nxt_dist=nbr_pair.second;
            if(visited[child])continue;
            if(dist_till_now+nxt_dist<dist[child]){

                if(s.find({dist[child],child})!=s.end()){
                    s.erase({dist[child],child});
                }

                dist[child]=dist_till_now+nxt_dist;
                s.insert({dist[child],child});
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

    cin>>n>>m;
    vector<edges>e;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        gr[x].push_back({y,w});
        rev_gr[y].push_back({x,w});
        e.push_back({x,y,w});
    }

    memset(visited,0,sizeof(visited));
    dijikstra(1,dist1,gr);
    memset(visited,0,sizeof(visited));
    dijikstra(n,dist2,rev_gr);

    int ans=(int)1e17;

    for(auto ed:e){

        int x=ed.a;
        int y=ed.b;
        int wt=ed.w;

        ans=min(ans,dist1[x]+dist2[y]+wt/2);
    }

    cout<<ans<<endl;
    
    return 0;
}