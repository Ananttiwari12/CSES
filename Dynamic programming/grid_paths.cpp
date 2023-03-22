#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[1001][1001];


int solve(string s[], int n, int x, int y){

	if(x==n-1 and y==n-1 and s[n-1][n-1]!='*') return 1;
	if(x>=n or y>=n) return 0;
    if(s[n-1][n-1]=='*') return 0;
	if(dp[x][y]!=-1)return dp[x][y]%mod;
	int ans=0;
	if(y<n-1 and s[x][y+1]!='*')ans+=solve(s,n,x,y+1)%mod,ans%=mod;
	if(x<n-1 and s[x+1][y]!='*')ans+=solve(s,n,x+1,y)%mod,ans%=mod;
	
	return dp[x][y]=ans%mod;
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
    string s[n];
    
    for(int i=0;i<n;i++){
    	cin>>s[i];
    }
    memset(dp,-1,sizeof(dp));
    if(s[0][0]=='*')cout<<0;
    else
    cout<<solve(s,n,0,0)%mod;

    
    
    return 0;
}