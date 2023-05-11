#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long

int mod=1000000007;

int modpwr(int a, int b, int mod){
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

        int a,b,c; cin>>a>>b>>c;
        if(b==0 and c>0){
            cout<<1<<endl;
            continue;
        }
        if(c==0){
            if(a==0){
                cout<<0<<endl;
            }
            else{
                cout<<a<<endl;
            }
            continue;
        }
        if(a==0){
            cout<<0<<endl;
            continue; 
        }

        int r=modpwr(b,c,mod-1);
        int ans=modpwr(a,r,mod);

        cout<<ans<<endl;

        
        
    }
    
    return 0;
}