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
    vector<int>v(n);

    for(int i=1;i<=n;i++){
        v[i-1]=i;
    }

    while(v.size()>1){
        vector<int>child;
        for(int i=0;i<v.size();i++){
            if(i%2==1){
                cout<<v[i]<<" ";
            }
            else{
                child.push_back(v[i]);
            }
        }
        if(v.size()%2!=0){
            int front=child.back();
            child.pop_back();
            v.clear();
            v.push_back(front);
            for(int j=0;j<child.size();j++){
                v.push_back(child[j]);
            }
        }
        else{
            v=child;
        }
    }
    cout<<v[0];
    return 0;
}