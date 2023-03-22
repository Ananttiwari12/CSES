#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int ans=INT_MAX;

int solve(int s[], int i,int n,int a, int b){
    if(i==n){
        return abs(a-b);
    }
    int ans1=solve(s,i+1,n,a+s[i],b);
    int ans2=solve(s,i+1,n,a,b+s[i]);
    ans=min(ans1,ans2);
    return ans;
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
    int s[n];
    int sum_a=0, sum_b=0;
    for(int i=0;i<n;i++){
    	cin>>s[i];
    }
    cout<<solve(s,0,n,sum_a,sum_b);
    return 0;
}