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

    int n; cin>>n;
    int v[n];
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }

    int pre[n+1];
    pre[0]=0;

    for(int i=0;i<n;i++){
    	pre[i+1]=pre[i]+v[i];
    }
    for(int i=0;i<=n;i++){
    	if(pre[i]>=0){
    		pre[i]%=n;
    	}
    	else{
    		pre[i]= (pre[i]%n+n)%n;
    	}
    }


    map<int,int>mp;

    int cnt=0;
    int i=0;

    while(i<=n){
    	
    	
    	int calc=pre[i];
    	if(mp.count(calc)){
    		cnt+=mp[calc];
    		mp[calc]++;
    	}
    	else{
    		mp[pre[i]]++;
    	}
    	i++;
    }

    cout<<cnt;



    
    
    return 0;
}