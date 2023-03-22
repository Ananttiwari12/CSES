#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=50001;
vector<int>gr[N];

int dp1[N][501];
int dp2[N][501];

void dfs(int src, int par, int k){

	for(auto child: gr[src]){
		if(par!=child){
			dfs(child,src,k);
		}
	}

	dp1[src][0]=1;

	for(int dist=1;dist<=k;dist++){
		dp1[src][dist]=0;

		for(auto child: gr[src]){
			if(child!=par){
				dp1[src][dist]+=dp1[child][dist-1];
			}
		}
	}
}


void solve(int src, int par, int k){

	for(int dist=0;dist<=k; dist++){
		dp2[src][dist]=dp1[src][dist];
	}

	if(par!=0){
		dp2[src][1]+=dp2[par][0];
		for(int dist=2;dist<=k;dist++){
			dp2[src][dist]+=dp2[par][dist-1];
			dp2[src][dist]-=dp1[src][dist-2];
		}
	}

	for(auto child: gr[src]){
		if(child!=par){
			solve(child,src,k);
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

    int n,k; cin>>n>>k;

    for(int i=0;i<n-1;i++){
    	int x,y; cin>>x>>y;
    	gr[x].push_back(y);
    	gr[y].push_back(x);
    }

    dfs(1,0,k);
    solve(1,0,k);
    int ans=0;

    for(int i=1;i<=n;i++){
    	ans+=dp2[i][k];
    }

    cout<<ans/2<<endl;

    
    
    return 0;
}