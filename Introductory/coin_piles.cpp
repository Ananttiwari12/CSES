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

    int a,b; cin>>a>>b;
    if(a<b)swap(a,b);

    if((a+b)%3!=0){
    	cout<<"NO"<<endl;
    }
    else{

    	if(a%2!=0){
    		if(b<(a/2)+1) cout<<"NO"<<endl;
    		else cout<<"YES"<<endl;
    	}
    	else{ if(b<(a/2))cout<<"NO"<<endl;
    	else cout<<"YES"<<endl;
}

    }
    }
    return 0;
}