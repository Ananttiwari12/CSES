#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;cin>>n;
    int a=(n*(n+1))/2;
    int b=0;
    int an[n-1];
    for(int i=0;i<n-1;i++){
        cin>>an[i];
    }
    for(int i=0; i<n-1;i++){
        b+=an[i];
    }
    cout<<a-b<<endl;
    return 0;
}