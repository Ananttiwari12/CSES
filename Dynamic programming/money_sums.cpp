#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[101][100001];
set<int>s;

int solve(int a[], int n, int sum){
	
    if(n==0)return 0;
    if(dp[n][sum]!=-1)return dp[n][sum];

	int ans=0;
    s.insert(sum);
    ans+=solve(a,n-1,sum);
    s.insert(sum);
    ans+=solve(a,n-1,sum+a[n-1]);
    s.insert(sum+a[n-1]);

    return dp[n][sum]=ans;
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
    	s.insert(a[i]);
    }
    memset(dp,-1,sizeof(dp));
    solve(a,n,0);
    s.erase(0);
    cout<<s.size()<<endl;
    for(auto x:s){
    	cout<<x<<" ";
    }
    return 0;
}