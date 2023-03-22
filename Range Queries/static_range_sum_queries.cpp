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


    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int psum[n+1];
    psum[0]=0;
    psum[1]=a[0];
    for(int i=2;i<=n;i++) psum[i]=psum[i-1]+a[i-1];

    

    while(q--){
        int l,r; cin>>l>>r;
    
        cout<<psum[r]-psum[l-1]<<endl;
    }
    
    return 0;
}