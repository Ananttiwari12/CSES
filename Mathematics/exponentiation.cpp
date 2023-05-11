#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007

int modpwr(int a, int b){
    int res=1;
    while(b){
        if(b&1) res=res*a, res%=mod;
        a=a*a, a%= mod;
        b>>=1;
    }
    return res;
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
    while(n--){

        int a,b; cin>>a>>b;
        if(a==0 and b==0){
            cout<<1<<endl;
            continue;
        }
        if(a==0){
            cout<<0<<endl;
            continue;
        }
        if(b==0){
            cout<<1<<endl;
            continue;
        }
        cout<<modpwr(a,b)<<endl;
    }
    
    return 0;
}