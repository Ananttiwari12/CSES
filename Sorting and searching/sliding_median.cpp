#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
         tree_order_statistics_node_update>
         new_data_set;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,k; cin>>n>>k;
    int z=k;
    if(z%2==0)z--;
    vector<int>a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    new_data_set s;

    for(int i=0;i<k;i++){
        s.insert({a[i],i});
    }
    
    int i=0;
    
    for(int j=k;j<n;j++){

        cout<<s.find_by_order((z/2))->first<<" ";
        s.erase(s.find({a[i],i}));
        i++;
        s.insert({a[j],j});
    }
    
    cout<<s.find_by_order(z/2)->first<<" ";

    return 0;
}