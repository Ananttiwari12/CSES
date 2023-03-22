#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]<0){
            ans+=abs(a[i]-a[i-1]);
            a[i]=a[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}