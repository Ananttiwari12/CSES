#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

bool isvalid(int a[], int n, int k, int mx){

	int sum=0;
	int cnt=1;
	for(int i=0;i<n;i++){
		sum+=a[i];

		if(sum<=mx){
			continue;
		}
		else{
			cnt++;
			sum=a[i];
		}
	}
	
	if(cnt<=k){
		return true;
	}
	else{
		return false;
	}
}

int binary_search(int a[], int n,int k,int s, int e){

	int mid;
	int ans;

	while(s<=e){
		mid=(s+e)/2;

		if(isvalid(a,n,k,mid)){
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

    int n,k; cin>>n>>k;
    int a[n];
    int mx=INT_MIN;

    for(int i=0;i<n;i++){
    	cin>>a[i];
    	mx=max(mx,a[i]);
    }

    cout<<binary_search(a,n,k,mx,1e18);
    

    
    
    return 0;
}