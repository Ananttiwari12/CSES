#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
#define INF 1000000000000000

const int N=5000010;
vector<pair<int,int>>gr[N];
	vector<int>dist(N+1, INF);

void dijikstra(int src, int n){
	set<pair<int,int>>s;
	s.insert({0,src}); // weight, node

	dist[src]=0;

	while(!s.empty()){

		auto it=s.begin();

		int nbr= it->second;
		int curr_dist= it->first;

		s.erase(it);
		
		for(auto nbr_pair: gr[nbr]){

			int edge_len=nbr_pair.second;

			int node=nbr_pair.first;

			if(curr_dist+edge_len<dist[node]){
				auto f=s.find({dist[node],node});

				if(f!=s.end()){
					s.erase(f);
				}

				dist[node]=curr_dist+edge_len;
				s.insert({dist[node],node});
			}
		}
	}
	for(int i=1;i<=n;i++){
    	cout<<dist[i]<<" ";
    }
    return ;
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
    	int x,y,w;
    	cin>>x>>y>>w;
    	gr[x].push_back({y,w});
    }

    dijikstra(1,n);

    return 0;
}