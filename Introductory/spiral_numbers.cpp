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

    int t; cin>>t;
    while(t--){

    int x,y; cin>>x>>y;

    if(x>y){
    	int ans;
    	if(x%2==0){
    		ans=x*x-y+1;
    	}
    	else{
    		ans=(x-1)*(x-1)+y;
    	}
    	cout<<ans<<endl;
    }
    else{
    	int ans;
    	if(y%2==0){
    		ans=(y-1)*(y-1)+x;
    	}
    	else{
    		ans=(y*y)-x+1;
    	}
    	cout<<ans<<endl;
    }
    }
    return 0;
}