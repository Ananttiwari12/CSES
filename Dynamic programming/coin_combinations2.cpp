#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,sum; cin>>n>>sum;
    int dp[sum+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;

    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j-a[i]>=0){
                dp[j]=(dp[j]+ dp[j-a[i]])%mod;
            }
        }
    }

    cout<<dp[sum];
    
    return 0;
}