#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int LIS(int a[], int n){
    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>ans.back()){
            ans.push_back(a[i]);
        }
        else{
            int idx=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
            ans[idx]=a[i];
        }
    }
    return ans.size();
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
    cout<<LIS(a,n);
    return 0;
}