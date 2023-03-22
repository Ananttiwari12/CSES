#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int nmax =1000001;

int dp[nmax][8];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif



    memset(dp,0,sizeof(dp));

    for(int i=0;i<8;i++){
        dp[0][i]=1;
    }

    for(int i=1;i<nmax;i++){
        for(int j=0;j<8;j++){
            if(j==0 or j==2 or j==3 or j==4 or j==5){
                dp[i][j]= (dp[i-1][0]+dp[i-1][1]+ dp[i-1][3]+dp[i-1][4]+ dp[i-1][5])%mod;
            }
            else{
                dp[i][j]= (dp[i-1][2]+dp[i-1][6]+ dp[i-1][7])%mod;
            }
        }
    }


    int t; cin>>t;
    while(t--){

    int n; cin>>n;
    cout<<(dp[n-1][2]+dp[n-1][6])%mod<<endl;
    }
    return 0;
}