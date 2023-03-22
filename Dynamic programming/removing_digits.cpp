#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[1000001];

int dig_gen(int n){
	vector<int>v;
	while(n){
		
		if(n%10!=0)
		v.push_back(n%10);
		n/=10;
	}
	sort(v.begin(), v.end());
	return v[v.size()-1];
}

int solve(int n){

	if(n==0)return 0;
	if(n<0)return -1;
	if(dp[n]!=-1) return dp[n];
	int b=n;

	int dig=dig_gen(b);
	int ans=n;
	int a2=0;
			
	a2+=1+solve(n-dig);
	
	
	return dp[n]=a2;
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

    memset(dp,-1,sizeof(dp));

    cout<<solve(n);
    
    return 0;
}