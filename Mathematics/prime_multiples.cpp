#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int


#define mod 1000000007


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,k; cin>>n>>k;
    vector<int>prime(k);

    for(int i=0;i<k;i++){
    	cin>>prime[i];
    }

    int ans=0;
    for(int i=1;i<(1<<k);i++){

    	int lcm=1;
    	for(int j=0;j<k;j++){
    		if((i>>j)&1){
    			if(lcm>n/prime[j]){
    				lcm=n+1;
    				break;
    			}
    			lcm*=prime[j];
    		}
    	}

    	if(__builtin_popcountll(i)%2==0){
    		ans-=(n/lcm);
    	}
    	else{
    		ans+=(n/lcm);
    	}
    }

    cout<<ans<<endl;

    return 0;
}