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
    map<int,int>mp;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    
    int i=0;
    int j=i+1;
    mp[a[0]]++;
    int ans=1;
    while(i<=j and j<n){
    	if(!mp.count(a[j]) ||( mp[a[j]]==0)){
    		ans=max(ans,j-i+1);
    		mp[a[j]]++;
    		j++;
    	}
    	else{	
    		mp[a[i]]--;
    		i++;
    	}
    	if(i==j){
    		mp[a[j]]=1;
    		j++;
    	}
    	
    }
    // ans=max(ans,j-i+1);
    cout<<ans<<endl;



    

    
    
    return 0;
}