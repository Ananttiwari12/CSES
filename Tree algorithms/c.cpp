#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int p = 1e9 + 7;
 


int dp[30][30][2];
int solve(string& num,int n,int k,bool tight){
    if(k>3)return 0;
    if(n==0){  // changes made here
        if(k<=3)return 1;
           else return 0;
    }
    if(dp[n][k][tight]!=-1)return dp[n][k][tight];
    int answer=0;
    int ub;
    if(tight==1){
     ub=(num[(num.length()-n)]-'0');
    } else{
        ub=9;
    }
   for(int dig=0;dig<=ub;dig++){
      if(dig!=0){
    answer+=solve(num,n-1,k+1,(tight&(dig==ub)));
      } else{
    answer+=solve(num,n-1,k,(tight&(dig==ub))); 
      }
   }
   return dp[n][k][tight]=answer;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  int t;
  cin>>t;
  while(t--){
    int l,r;
    cin>>l>>r;

    int temp=l;

    if(l!=0)l--;  // changes made here

    string L=to_string(l);
    string R=to_string(r);
    memset(dp,-1,sizeof(dp));

    int ans1=solve(R,R.length(),0,1);

    memset(dp,-1,sizeof(dp));
    int ans2=solve(L,L.length(),0,1);
    if(temp==0)cout<<ans1-ans2+1<<endl;  // changes made here
    else cout<<ans1-ans2<<endl;
}}