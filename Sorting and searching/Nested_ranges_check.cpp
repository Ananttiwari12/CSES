#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

bool compare(pair<int,pair<int,int>>&a, pair<int,pair<int,int>>&b){
    
    if(a.first==b.first){
        return a.second.first>b.second.first;
    }
    return a.first<b.first;
}

bool compare2(pair<int,int>&a, pair<int,int>&b){
    return a.second<b.second;
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
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,{y,i}});
    }

    sort(v.begin(), v.end(), compare);

    vector<pair<int,int>>contained(n);
    vector<pair<int,int>>contains(n);

    int mx=INT_MIN;

    for(int i=0;i<n;i++){
        if(v[i].second.first<=mx){
            contained[i].first=1;
            contained[i].second=v[i].second.second;
            mx=max(mx,v[i].second.first);
        }
        else{
            contained[i].first=0;
            contained[i].second=v[i].second.second;
            mx=max(mx,v[i].second.first);
        }
    }

    int mini=INT_MAX;

    for(int i=n-1;i>=0;i--){

        if(v[i].second.first>=mini){
            contains[i].first=1;
            contains[i].second=v[i].second.second;

        }
        else{
            contains[i].first=0;
            contains[i].second=v[i].second.second;
            mini=min(mini,v[i].second.first);
        }
    }
    sort(contains.begin(),contains.end(),compare2);
    sort(contained.begin(),contained.end(),compare2);


    for(int i=0;i<n;i++){
        cout<<contains[i].first<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<contained[i].first<<" ";
    }
    cout<<endl;

    return 0;
}