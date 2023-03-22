#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200001;

vector<int>gr[N];
int dp[N][2];

int solve(int src, bool Isincluded, int par){
    if(dp[src][Isincluded]!=-1)return dp[src][Isincluded];
    if(Isincluded){
        int precompute=0;
        for(auto child:gr[src]){
            if(child!=par){
                precompute+=solve(child,1,src);
            }
        }
        int ans=0;
        for(auto child:gr[src]){
            if(child!=par){
                ans=max(ans,precompute-dp[child][1]+solve(child,0,src)+1);
            }
        }
        return dp[src][Isincluded]=ans;
    }
    else{
        int ans=0;
        for(auto child:gr[src]){
            if(child!=par){
                ans+=solve(child,1,src);
            }
        }
        return dp[src][Isincluded]=ans;
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

    int n; cin>>n;

    for(int i=0;i<n-1;i++){
    	int x,y; cin>>x>>y;
        gr[x].push_back(y);
    	gr[y].push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    cout<<max(solve(1,0,0),solve(1,1,0))<<endl;
    return 0;
}