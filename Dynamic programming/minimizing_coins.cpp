#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
#define INF 10000000
int dp[1000001];
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n,sum; cin>>n>>sum;
    int v[n+1];
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=sum;i++){
        dp[i]=INF;
    }
 
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            if(i-v[j]>=0){
                dp[i]= min(1+dp[i-v[j]], dp[i]);
            }
        }
    }
 
    if(dp[sum]==INF) dp[sum]=-1;
    cout<<dp[sum];
    return 0;
}
 