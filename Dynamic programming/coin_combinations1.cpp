#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[1000001];

int solve(int a[], int n,int sum){

    if(sum==0) return 1;
    // if(idx==n-1){
    //     if(sum==0) return 1;
    //     else return 0;
    // }
    if(sum<0) return 0;
    if(dp[sum]!=-1) return dp[sum]%mod;

    int ans=0;

    for(int i=0;i<n;i++){

        ans+=solve(a,n,sum-a[i])%mod;
        ans%=mod;
    }

    return dp[sum]= ans%mod;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,sum; cin>>n>>sum;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    memset(dp,-1,sizeof(dp));

    cout<<solve(a,n,sum)%mod;

    

    
    return 0;
}