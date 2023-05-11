#include<bits/stdc++.h>
#define endl "\n"
using namespace std;


#define mod 1000000007

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
         tree_order_statistics_node_update>
         new_data_set;

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
    new_data_set s;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert({i+1,a[i]});
    }

    for(int i=0;i<n;i++){
        int x; cin>>x;
        x--;
        if(s.find_by_order(x)==s.end()){
            cout<<0<<" ";
        }
        else{
            cout<<s.find_by_order(x)->second<<" ";
            s.erase({s.find_by_order(x)->first, s.find_by_order(x)->second});
        }
    }
    return 0;
}