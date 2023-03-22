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
    int cnt=0;

    for(int i=1;;i++){
    	
    	int ans=n/pow(5,i);
    	
    	cnt+=ans;
    	if(ans==0)break;
    }
    cout<<cnt<<endl;
    
    

    
    
    return 0;
}