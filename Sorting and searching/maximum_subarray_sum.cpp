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

    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    int i=0;int j=i+1;
    int sum=0;
    int ans=INT_MIN;
    if(sum<0){
    	sum=0;
    }
    for(i=0;i<n;i++){
    	if(a[i]<0){
    		ans=max(ans,a[i]);
    	}
    	if(a[i]>=0){
    		ans=max(ans,a[i]);
    		break;
    	}
    }
    sum+=a[i];
    j=i+1;

    while(i<=j and j<n){
    	if(sum+a[j]>=0){
    		sum+=a[j];
    		ans=max(ans,sum);
    		j++;
    	}
    	else{
    		i=j;
    		j++;
    		sum=0;
    	}

    }

    
    cout<<ans;
    
    
    return 0;
}