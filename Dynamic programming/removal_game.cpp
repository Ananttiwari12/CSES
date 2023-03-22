#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[5001][5001];

int solve(int a[], int n, int i, int j, int state){ 

	if(i==j){
		if(state==1)return a[i];
		else return 0;
	}

	if(dp[i][j]!=-1)return dp[i][j];

	// state 1: player A maxi
	int ans=0;
	if(state==1){ 
		ans+=max(a[i]+solve(a,n,i+1,j,state^1),a[j]+solve(a,n,i,j-1,state^1));

	}
	else{
		ans=min(solve(a,n,i+1,j,state^1),solve(a,n,i,j-1,state^1));
	}

	return dp[i][j]=ans;




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
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(a,n,0,n-1,1);

    
    
    return 0;
}