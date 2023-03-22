#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

struct projects{
    int s,e,r;
};
bool compare(projects &p1, projects &p2){
    return p1.e<p2.e;
}
int valid_End_point(vector<int>&End,int key){
    auto it=lower_bound(End.begin(), End.end(),key);
    if(it==End.begin())return 0;
    it--;
    return 1+it-End.begin();
     
}


int solve(vector<projects>&v, int n){
    int dp[n+1];
    dp[0]=0;
    vector<int>endpts;
    for(int i=0;i<n;i++){
        endpts.push_back(v[i].e);
    }

    for(int i=0;i<n;i++){
        int ans1=dp[i];
        int ans2=v[i].r;
        int j=valid_End_point(endpts,v[i].s);
        ans2+=dp[j];
        dp[i+1]=max(ans1,ans2);
    }

    return dp[n];


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
    
    vector<projects>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].s>>v[i].e>>v[i].r;
    }
    sort(v.begin(), v.end(),compare);

    cout<<solve(v,n);
    return 0;
}
