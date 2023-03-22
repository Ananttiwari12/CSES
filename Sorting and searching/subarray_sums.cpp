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

    int i=0;
    int j=0;

    int sum=0; int cnt=0;
    sum+=a[i];

    while(i<=j and j<n){

    	if(sum<x){
    		j++;
    		sum+=a[j];
    	}
    	else if(sum>x){
    		sum-=a[i];
    		i++;
    	}
    	else{
    		cnt+=1;
    		sum-=a[i];
    		i++;
    		j++;
    		sum+=a[j];
    	}
    	
    }

    cout<<cnt;
    return 0;
}