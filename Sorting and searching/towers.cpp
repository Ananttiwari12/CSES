#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int binary_search(vector<int>&v, int n, int s, int e, int key){

	int mid;
	int ans=-1;
	while(s<=e){
		mid=(s+e)/2;
		if(v[mid]>key){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
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

    int n; cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    vector<int>v;

    for(int i=0;i<n;i++){
    	if(v.size()==0){
    		v.push_back(a[i]);
    		continue;
    	}

    	int cc=binary_search(v,v.size(),0,v.size()-1,a[i]);
    	if(cc==-1){
    		v.push_back(a[i]);
    	}
    	else{
    		v[cc]=a[i];
    	}
    }
    
    cout<<v.size();

    
    
    return 0;
}