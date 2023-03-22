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

    int pre[n+1];
    int cnt=0;

    pre[0]=0;

    for(int i=0;i<n;i++){
    	pre[i+1]=pre[i]+a[i];
    }

    map<int,int>mp;

    int i=0;
   	

    while(i<=n){

    	int a=pre[i];

    	int b=a-x;
    	if(mp.count(b)){
    		cnt+=mp[b];
    		mp[a]++;
    	}
    	else{
    		mp[a]++;
    	}
    	i++;
    }
    cout<<cnt;



    return 0;
}