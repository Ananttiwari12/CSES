#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
 
int n,m,k;
 
vector<pair<int,int>>gr[100001];
vector<pair<int,int>>rev_gr[100001];
int dist1[100001];
int dist2[100001];
 
int visited[100001];
 
struct edges
{
	int a,b,w;
};
 
void dijikstra(int src, vector<pair<int,int>>gr[], int dist[]){
 
    for(int i=0;i<100001;i++){
        dist[i]=(int)1e17;
    }
 
	dist[src]=0;
	set<pair<int,int>>s; // weight node
 
	s.insert({0,src});
	visited[src]=1;
 
	while(!s.empty()){
 
		pair<int,int>p=*s.begin();
 
		s.erase(p);
 
		int dist_till_now=p.first;
		int node=p.second;
 
		for(auto nbr_pair: gr[node]){
 
			int w=nbr_pair.second;
			int nbr=nbr_pair.first;
			if(visited[nbr])continue;
			if(dist[nbr]>dist_till_now+w){
				if(s.find({dist[nbr],nbr})!=s.end()){
					s.erase({dist[nbr],nbr});
				}
				dist[nbr]=dist_till_now+w;
				s.insert({dist[nbr],nbr});
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
 
    cin>>n>>m>>k;
 
    vector<edges>v;
 
    for(int i=0;i<m;i++){
    	int x,y,w; cin>>x>>y>>w;
    	gr[x].push_back({y,w});
    	rev_gr[y].push_back({x,w});
    	v.push_back({x,y,w});
    }
 
    memset(visited,0,sizeof(visited));
    dijikstra(1,gr,dist1);
    memset(visited,0,sizeof(visited));
    dijikstra(n,rev_gr,dist2);
 
    vector<int>ans;
 
    // for(int i=2;i<=n-1;i++){
    // 	ans.push_back(dist1[i]+dist2[i]);
    // }
 
    for(auto ed:v){
    	int x=ed.a;
    	int y=ed.b;
    	int wt=ed.w;
    	if(x==1 or y==1)continue;
    	ans.push_back(dist1[x]+dist2[y]+wt);
    }
    sort(ans.begin(), ans.end());
 
    for(int i=0;i<k;i++){
    	cout<<ans[i]<<" ";
    }
 
 
    return 0;
}
