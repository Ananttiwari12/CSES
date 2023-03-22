#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200001;

vector<int>gr[N];
int depth[N];
int up[N][21];

void binary_lifting(int src,int par){

	depth[src]=1+depth[par];

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
		if(child!=par)
			binary_lifting(child,src);
	}
}

int lift_node(int node, int jump){

	for(int i=20;i>=0;i--){
		if(node==-1 or jump==0){
			break;
		}

		if(jump>=(1<<i)){
			jump-=(1<<i);
			node=up[node][i];
		}
	}

	return node;
}


int LCA(int u, int v){

	if(depth[u]<depth[v]){
		swap(u,v);
	}

	u=lift_node(u,depth[u]-depth[v]);

	if(u==v)return u;

	for(int i=20;i>=0;i--){
		if(up[u][i]!=up[v][i]){
			u=up[u][i];
			v=up[v][i];
		}
	}

	return lift_node(u,1);

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,q;
    cin>>n>>q;

    for(int i=2;i<=n;i++){
    	int x; cin>>x;
    	gr[i].push_back(x);
    	gr[x].push_back(i);
    }

    binary_lifting(1,0);

    while(q--){

    	int u,v; cin>>u>>v;
    	cout<<LCA(u,v)<<endl;




    }


    

    
    
    return 0;
}