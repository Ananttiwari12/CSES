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

    int n,m,k; cin>>n>>m>>k;

    int a[n],b[m];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    for(int i=0;i<m;i++){
    	cin>>b[i];
    }

    vector<pair<int,int>>v;

    for(int i=0;i<n;i++){
    	v.push_back({a[i]-k, a[i]+k});
    }

    sort(v.begin(), v.end());
    sort(b,b+m);

    int cnt=0;
    int i=0;
    int j=0;

    // for(int i=0;i<n;i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    while(i<n and j<m){

    	if(b[j]>=v[i].first and b[j]<=v[i].second){
    		cnt++;
    		i++;
    		j++;
    	}
    	else if(b[j]<=v[i].first){
            j++;
        }
        else if(b[j]>=v[i].second){
            i++;
        }

        }
    

    cout<<cnt;

    

    
    
    return 0;
}