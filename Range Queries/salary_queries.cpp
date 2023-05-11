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

    int n,q; cin>>n>>q;
    int a[n];
    new_data_set s;

    for(int i=0;i<n;i++){
    	cin>>a[i];
    	s.insert({a[i],i+1});
    }

    while(q--){

    	char c; cin>>c;
    	if(c=='!'){
    		int k, x; cin>>k>>x;
    		s.erase({a[k-1],k});
    		a[k-1]=x;
    		s.insert({a[k-1],k});
    	}
    	else{
    		int a,b; 
    		cin>>a>>b;
    		int ub=s.order_of_key({b+1,0});
    		int lb=s.order_of_key({a,0});
    		cout<<ub-lb<<endl;
    	}
    }   
    return 0;
}