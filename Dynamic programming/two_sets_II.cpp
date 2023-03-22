#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[501][70000];

int solve(int a[], int n, int sum){
    if(sum==0)return 1;
    if(n==1){
        if(sum==0)return 1;
        else{
            return 0;
        }
    }
    if(dp[n][sum]!=-1)return dp[n][sum]%mod;
    int ans=0;
    if(sum-a[n-1]<0){
        ans=(ans+solve(a,n-1,sum))%mod;
        ans%=mod;
    }
    else{
        ans=(ans+solve(a,n-1,sum)+solve(a,n-1,sum-a[n-1]))%mod;
        ans%=mod;
    }
    return dp[n][sum]=ans%mod;
} 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
    	a[i]=i+1;
        sum+=(i+1);
    }

    if(sum%2!=0)cout<<0;
    else{
        sum/=2;
        memset(dp,-1,sizeof(dp));

        cout<<solve(a,n,sum);

    }
    return 0;
}