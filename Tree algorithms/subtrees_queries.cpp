#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int n,q;
int tin[200001];
int tout[200001];
int val[200001];
int timer=0;
void update(int idx, int val, vector<int>&bit){
	if(idx==0)return;
	for(;idx<=bit.size();idx+=(idx&(-idx)))bit[idx]+=val;
}
int query(int idx, vector<int>&bit){
	int r=0;
	for(;idx>0;idx-=(idx&(-idx)))r+=bit[idx];
	return r;
}
vector<int>gr[200001];
int visited[200001];
void dfs(int src, int par){
	tin[src]=++timer;
	for(auto child: gr[src]){
		if(child!=par){
			dfs(child,src);
		}
	}
	tout[src]=++timer;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>q;

    for(int i=1;i<=n;i++){
    	cin>>val[i];
    }

    for(int i=1;i<=n-1;i++){
    	int x,y; cin>>x>>y;
    	gr[x].push_back(y);
    	gr[y].push_back(x);
    }
    dfs(1,0);

    vector<int>bit(2*n+(long long)5,0);
    for(int i=1;i<=n;i++){
    	update(tin[i],val[i],bit);
    	update(tout[i],val[i],bit);
    }

    while(q--){
    int type; cin>>type;
    if(type==1){
    	int node,x; cin>>node>>x;
    	int delta=x-val[node];
    	update(tin[node],delta,bit);
    	update(tout[node],delta,bit);
    	val[node]=x;
    }
    else{
    	int node;
    	cin>>node;
    	int r=query(tout[node],bit);
    	int l=query(tin[node]-1,bit);
    	cout<<(r-l)/2<<endl;
    }
	}
    return 0;
}
