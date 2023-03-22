#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200001;

vector<int>gr[N];
int depth[N];

int up[N][21];

int prefix[N];

void binary_lifting(int src, int par){
	depth[src]=depth[par]+1;
	up[src][0]=par;

	for(int i=1;i<=20;i++){
		if(up[src][i-1]!=-1){
			up[src][i]=up[up[src][i-1]][i-1];
		}
		else{
			up[src][i]=-1;
		}
	}
	for(auto child: gr[src]){
		if(child!=par){
			binary_lifting(child,src);
		}
	}
}


int jump(int node, int jmp){
	for(int i=20;i>=0;i--){
		if(jmp==0 or node==-1){
			break;
		}
		if(jmp>=(1<<i)){
			jmp-=(1<<i);
			node=up[node][i];
		}
	}
	return node;
}

int LCA(int u, int v){
	if(depth[u]<depth[v]){
		swap(u,v);
	}

	u=jump(u,depth[u]-depth[v]);
	if(u==v)return u;
	for(int i=20;i>=0;i--){
		if(up[u][i]!=up[v][i]){
			u=up[u][i];
			v=up[v][i];
		}
	}
	return jump(u,1);
}

void dfs(int src, int par){

	int x=prefix[src];
	for(auto child: gr[src]){
		if(child!=par){
			dfs(child,src);
			x+=prefix[child];
		}
	}
	prefix[src]=x;
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

    for(int i=0;i<n-1;i++){
    	int x,y; cin>>x>>y;
    	gr[x].push_back(y);
    	gr[y].push_back(x);
    }

    binary_lifting(1,0);
    while(m--){

    	int u,v; cin>>u>>v;

    	prefix[u]+=1;
    	prefix[v]+=1;
    	int x=LCA(u,v);
    	prefix[x]-=1;

    	int y=up[x][0];
   		prefix[y]-=1;
    	
    }
    dfs(1,0);

    for(int i=1;i<=n;i++){
    	cout<<prefix[i]<<" ";
    }
    cout<<endl;

    return 0;
}