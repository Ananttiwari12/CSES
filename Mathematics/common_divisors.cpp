#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    int a[n];

    vector<int>mp(1e6+1,0);

    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    int ans=1;

    for(int gcd=1e6;gcd>=1;gcd--){
        int cnt=0;
        for(int j=gcd;j<=1e6;j+=gcd){
                cnt+=mp[j];
            if(cnt>1){
                ans=gcd;
                break;
            }
        }
        if(cnt>1)break;
    }
    cout<<ans<<endl;
    return 0;
}