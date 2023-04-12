#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=2501;

vector<pair<int,int>>gr1[N];
vector<pair<int,int>>gr2[N];

int visited1[N];
int visited2[N];

void dfs1(int src){
	visited1[src]=1;
	for(auto x:gr1[src]){
		if(!visited1[x.first]){
			dfs1(x.first);
		}
	}
	return;
}

void dfs2(int src){
	visited2[src]=1;
	for(auto x:gr2[src]){
		if(!visited2[x.first]){
			dfs2(x.first);
		}
	}
	return;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges;

    memset(visited1,0,sizeof(visited1));
    memset(visited2,0,sizeof(visited2));

    for(int i=0;i<m;i++){
    	int x,y,w;
    	cin>>x>>y>>w;
    	
    	edges.push_back({x,y,-w});
    	gr1[x].push_back({y,w});
    	gr2[y].push_back({x,w});

    }

    dfs1(1);
    dfs2(n);

	vector<int>dist(n+1,1e18);

	dist[1]=0;

	for(int i=0;i<n-1;i++){
		for(auto edge: edges){
			int u=edge[0];
			int v=edge[1];
			int wt=edge[2];

			if(dist[u]!=1e18 and dist[v]>dist[u]+wt){
				dist[v]=dist[u]+wt;
			}
		}
	}

	int cnt=0;
	for(auto edge: edges){
		int u=edge[0];
		int v=edge[1];
		int w=edge[2];

		if(visited1[u] and visited2[v] and dist[v]>dist[u]+w){
			cnt++;
			break;
		}
	}

	if(cnt==1){
		cout<<-1;
	}
	else{
		cout<<-dist[n];
	}
    
    return 0;
}