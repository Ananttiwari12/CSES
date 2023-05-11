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
    string s;
    cin>>s;

    int ans=1;

    for(int i=1;i<s.length();i++){
        if(s[i]=='?'){
                ans*=10;
        }
    }
    if(s[0]=='?')ans*=9;
    if(s[0]=='0')ans=0;

    cout<<ans<<endl;
    }
    return 0;
}