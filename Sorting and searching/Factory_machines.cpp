#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

bool isvalid(int a[], int n, int k, int t){
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=(k/a[i]);
	}
	if(cnt>=t)return true;
	return false;
}

int binary_search(int a[],int n,int s, int e,int mx, int t){

	int mid;
	int ans=mx;
	while(s<=e){
		mid=(s+e)/2;

		if(isvalid(a,n,mid,t)){
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

    int n,t; cin>>n>>t;
    int a[n];

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    sort(a,a+n);
    int mx=a[0]*t;

    cout<<binary_search(a,n,0,mx,mx,t);

    return 0;
}