#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[1000001];

int solve(int n){
	if(n==0) return 1;
	if(n<0) return 0;

	if(dp[n]!=-1) return dp[n];
	
	int ans=(((solve(n-1)%mod+solve(n-2)%mod)%mod+(solve(n-3)%mod+solve(n-4)%mod)%mod)%mod+ (solve(n-5)%mod+solve(n-6)%mod)%mod)%mod;
	ans%=mod;
	
	return dp[n]=ans;

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
    memset(dp,-1,sizeof(dp));

    cout<<solve(n);
    

    
    
    return 0;
}