#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int binary_search(vector<pair<int,int>>&a, int n, int s, int e,int key){

	int mid;
	int ans=-1;
    
	while(s<=e){

		mid=(s+e)/2;	
		if(s>e)break;
		if(a[mid].first>key){
			e=mid-1;
		}
		else if(a[mid].first<key){
			s=mid+1;
		}
		else if(key==a[mid].first){
			ans=mid;
			return ans;
		}
        if(s>e)break;
	}


return ans;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,x; cin>>n>>x;

    vector<pair<int,int>>a;

    for(int i=0;i<n;i++){
        int u; cin>>u;
        a.push_back({u,i+1});
    }

    int cnt=0;
    int ans1=-1; int ans2;
    sort(a.begin(), a.end());
    for(int i=0;i<n-1;i++){

    	int cc=binary_search(a,n,i+1,n-1,x-a[i].first);

    	if(cc!=-1){
    		ans1=a[i].second;
    		ans2=a[cc].second;
    		break;
    	}
    }

    if(ans1==-1){
    	cout<<"IMPOSSIBLE";
    }
    else{
    	cout<<ans1<<" "<<ans2;
    }
    
    return 0;
}