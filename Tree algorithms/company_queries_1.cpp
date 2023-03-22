#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200001;
vector<int>gr[N];

int up[N][21];

void binary_lifting(int src, int par){

	up[src][0]=par;
	for(int i=1;i<=20;i++){
		if(up[src][i-1]!=-1){
			up[src][i]=up[up[src][i-1]][i-1];
		}
		else up[src][i]=-1;
	}
	for(auto child:gr[src]){
		if(child!=par){
			binary_lifting(child,src);
		}
	}
}

int query(int node, int k){
	if(node==-1 or k==0)return node;

	for(int i=21;i>=0;i--){
		if(k>=(1<<i)){
			return query(up[node][i],k-(1<<i));
		}
	}
	return 0;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;

    for(int i=2;i<=n;i++){
    	int x; cin>>x;
    	gr[i].push_back(x);
    	gr[x].push_back(i);
    }
    binary_lifting(1,-1);
    while(q--){
    	int node,jump;
    	cin>>node>>jump;
    	cout<<query(node,jump)<<endl;
    }

    
    
    return 0;
}