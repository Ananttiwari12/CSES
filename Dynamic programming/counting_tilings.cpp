#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[1001][1<<11];

void generate_next_mask(int curr_mask, int i, int next_mask,int n, vector<int>&nxt_masks){

	if(i==n+1){
		nxt_masks.push_back(next_mask);
		return;
	}
	if((curr_mask&(1<<i))!=0){
		generate_next_mask(curr_mask,i+1,next_mask,n,nxt_masks);
	}
	if(i!=n){
		if((curr_mask&(1<<i))==0 and (curr_mask&(1<<(i+1)))==0){
			generate_next_mask(curr_mask,i+2,next_mask,n,nxt_masks);
		}
	}
	if( (curr_mask&(1<<i) ) ==0){
		generate_next_mask(curr_mask,i+1,next_mask+(1<<i),n,nxt_masks);
	}

}

int solve(int col,int mask, int n, int m){

	if(col==m+1){
		if(mask==0)return 1;
		else return 0;
	}

	if(dp[col][mask]!=-1)return dp[col][mask];

	int ans=0;
	vector<int>next_masks;
	generate_next_mask(mask,1,0,n,next_masks);

	for(int next_mask:next_masks){
		ans=(ans+solve(col+1,next_mask,n,m))%mod;
		ans%=mod;
	}

	return dp[col][mask]=ans%mod;

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
    memset(dp,-1,sizeof(dp));

    cout<<solve(1,0,n,m);
    

    
    
    return 0;
}