#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,x; cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    sort(a,a+n);
    int cnt=0;
    int i=0,j=n-1;

    while(i<=j and i<=n and j>=0){

    	if(a[i]+a[j]<=x){
    		cnt++;
    		i++;
    		j--;
    	}
    	else if(a[i]+a[j]>=x){
    		cnt++;
    		j--;
    	}
    }
    cout<<cnt;
    return 0;
}