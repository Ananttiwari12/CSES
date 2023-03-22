#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200001;
vector<int>gr[N];

int final_ans[N];
int subTreeAns[N];
int subTreeSize[N];

void precal(int src, int par){

    int numberofNodes=1;
    int subtree_ans=0;

    for(auto child: gr[src]){
        if(child!=par){
            precal(child,src);

            numberofNodes+=subTreeSize[child];
            subtree_ans+=subTreeSize[child]+subTreeAns[child];
        }
   }
   subTreeSize[src]=numberofNodes;
   subTreeAns[src]=subtree_ans;
}


void solve(int src, int par, int par_ans, int totalnodes){
    final_ans[src]=subTreeAns[src]+par_ans+(totalnodes-subTreeSize[src]);
    for(auto child: gr[src]){
        if(child!=par){
            solve(child,src,final_ans[src]-(subTreeSize[child]+subTreeAns[child]) ,totalnodes);
        }
    }
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

    precal(1,-1);
    solve(1,-1,0,n);

    for(int i=1;i<=n;i++){
        cout<<final_ans[i]<<" ";
    }




    
    
    return 0;
}