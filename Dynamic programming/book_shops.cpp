#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int price[10001],pages[10001];

int f(int n, int s){

    int dp[2][s+1];
    memset(dp, 0, sizeof(dp));

    int id=0;

    for(int i=1;i<=n;i++){
        for(int sum=1;sum<=s;sum++){
            if(sum-price[i-1]<0){
                dp[id^1][sum]=dp[id][sum];
            }
            else{
                dp[id^1][sum]=max(dp[id][sum], pages[i-1]+dp[id][sum-price[i-1]]);
            }
        }
        id^=1;
    }
    return dp[id][s];
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

    for(int i=0;i<n;i++){
    	cin>>price[i];
    }

    for(int i=0;i<n;i++){
    	cin>>pages[i];
    }

    cout<<f(n,sum);
    

    return 0;
}