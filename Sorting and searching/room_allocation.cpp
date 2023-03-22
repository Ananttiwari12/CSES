#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
using namespace std;
// using namespace __gnu_pbds;
#define mod 1000000007
#define int long long

// typedef tree<pair<int,pair<int,int>>,null_type,less<pair<int,pair<int,int>>>,rb_tree_tag,
// 		tree_order_statistics_node_update>
// 		new_data_set;

struct ranges{
	int in;
	int out;
	int index;
};

bool compare(ranges r1, ranges r2){
	if(r1.in<r2.in) return true;
	if(r1.in>r2.in) return false;
	return r1.out<r2.out;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    vector<ranges>v(n);

    for(int i=0;i<n;i++){
    	int x,y; cin>>x>>y;
    	v[i]={x,y,i};
    }

    sort(v.begin(), v.end(),compare);
    vector<int>ans(n+1);

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int k=0;

    for(int i=0;i<n;i++){
    	if(pq.empty()){
    		k++;
    		pq.push({v[i].out,k});
    		ans[v[i].index]=k;
    		continue;
    	}

    	if(v[i].in>pq.top().first){
    		int y=pq.top().second;
    		ans[v[i].index]=pq.top().second;
    		pq.pop();
    		pq.push({v[i].out,y});
    	}
    	else{
    		k++;
    		ans[v[i].index]=k; 
    		pq.push({v[i].out,k});
    	}
    	k=max(k,(int)pq.size());
    }
    cout<<k<<endl;
    for(int i=0;i<n;i++){
    	cout<<ans[i]<<" ";
    }

    return 0;
}