#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[501][501];

int solve(int a, int b){
   

    if(a==b)return 0;
    if(a==1 and b==1) return 0;
    if(a<=0 or b<=0) return 0;

    if(dp[a][b]!=-1)return dp[a][b];
    if(dp[b][a]!=-1)return dp[b][a];

    int ans1=1e18;
    int ans2=1e18;
    for(int i=1;i<a;i++){
        ans1=min(ans1,1+solve(i,b)+ solve(a-i,b));        
    }
    for(int i=1;i<b;i++){
        ans2=min(ans2,1+solve(a,i)+solve(a,b-i));
    }
    return dp[a][b]=dp[b][a]=min(ans1,ans2);
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int a,b;
    cin>>a>>b;

    memset(dp,-1,sizeof(dp));

    cout<<solve(a,b);
    

    
    
    return 0;
}