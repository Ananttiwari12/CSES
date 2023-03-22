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
    int a[n];
    int sum=0;

    for(int i=0;i<n;i++){
    	cin>>a[i];
    	sum+=a[i];
    }
    sort(a,a+n);

    int k=1;

    for(int i=0;i<n and k>=a[i];i++){
        k+=a[i];
    }
    cout<<k;
    return 0;
}