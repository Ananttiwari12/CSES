#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[5001][5001];

int solve(string &s1, string &s2, int n, int m){
	if(n<0)return m+1;
	if(m<0) return n+1;

	if(dp[n][m]!=-1)return dp[n][m];

	if(s1[n-1]==s2[m-1]) return dp[n][m]=solve(s1,s2,n-1,m-1);

	else{


		return dp[n][m]=1+min(solve(s1,s2,n-1,m),min(solve(s1,s2,n,m-1),solve(s1,s2,n-1,m-1)));
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

    string s1;
    string s2;

    cin>>s1>>s2;

    int n=s1.length();
    int m=s2.length();

    memset(dp,-1,sizeof(dp));

    cout<<solve(s1,s2,n,m);



    
    
    return 0;
}