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

    int n,x; cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    pair<int,int>dp[1<<n];

    dp[0]={1,0};

    for(int mask=1;mask<(1<<n);mask++){
        pair<int,int>best_res={INT_MAX,INT_MAX};
        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0)continue;

            auto res=dp[mask^(1<<i)];

            if(res.second+a[i]<=x){
                res.second+=a[i];
            }
            else{
                res.first+=1;
                res.second=a[i];
            }
            best_res=min(best_res,res);
        }
        dp[mask]=best_res;
    }

    cout<<dp[(1<<n)-1].first;

    
    
    return 0;
}