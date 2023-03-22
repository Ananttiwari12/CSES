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
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x]++;
    }
    cout<<mp.size()<<endl;
    
    return 0;
}