#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007
const int mx=1000001;


int divi[mx];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t; cin>>t;

    memset(divi,0,sizeof(divi));

    for(int i=1;i<mx;i++){
    	for(int j=i;j<mx;j+=i){
    		divi[j]+=1;
    	}
    }

    while(t--){
    	int n; cin>>n;
    	cout<<divi[n]<<endl;
    }


    return 0;
}