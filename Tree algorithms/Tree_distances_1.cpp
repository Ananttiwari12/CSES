#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200010;
vector<int>gr[N];
int depth[N];
int final_ans[N];

void precompute_depth(int src, int par){
    int ans=0;
    for(auto child: gr[src]){
        if(child!=par){
            precompute_depth(child,src);
            ans=max(ans,1+depth[child]);  
        } 
    }
    depth[src]=ans;
}

void solve(int src, int par, int par_ans){

    vector<int>prefixMax;
    vector<int>suffixMax;

    for(auto child: gr[src]){
        if(child!=par){
            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }

    for(int i=1;i<prefixMax.size();i++){
        prefixMax[i]=max(prefixMax[i],prefixMax[i-1]);
    }

    for(int i=(int)suffixMax.size()-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i],suffixMax[i+1]);
    }

    int child_no=0;

    for(auto child: gr[src]){
        if(child!=par){
            int op1,op2,partial_ans;

            if(child_no==0) op1=INT_MIN;
            else op1=prefixMax[child_no-1];

            if(child_no==(int)suffixMax.size()-1) op2=INT_MIN;
            else op2=suffixMax[child_no+1];

            partial_ans=1+max(par_ans, max(op1,op2));
            solve(child,src,partial_ans);
            child_no++;
        }
    }
    final_ans[src]=1+max(par_ans, (prefixMax.empty()?-1:prefixMax.back()));
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

    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    precompute_depth(1,0);

    solve(1,0,-1);

    for(int i=1;i<=n;i++){
        cout<<final_ans[i]<<" ";
    }

    
    
    return 0;
}