#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007

struct fenwick{
vector<int> fn;
int n;
void init(int n){this->n=n+1;fn.resize(this->n,0);}
void add(int x, int y){
    x++;
    while(x<n){fn[x]+= y;x+= x& (-x);}
}
int sum(int x){
    x++;
    int ans=0;
    while(x){ans+=fn[x]; x-= x & (-x);}
    return ans;}
int sum(int l, int r){return sum(r)-sum(l-1);}
};



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;
    vector<int>a(n);

    fenwick f;
    f.init(n);
    
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    map<int,int>mp;

    vector<vector<pair<int,int>>>que(n);
    vector<int>ans(q,-1);
    for(int i=0;i<q;i++){
    	int a,b; cin>>a>>b;
    	que[a-1].push_back({b-1,i});
    }

    for(int i=n-1;i>=0;i--){

    	int val=a[i];

    	if(mp.count(val))f.add(mp[val],-1);

    	mp[val]=i;
    	f.add(i,1);

    	for(auto &qr:que[i]){
    		ans[qr.second]=f.sum(qr.first);
    	}
    }

    for(auto qr:ans){
    	cout<<qr<<endl;
    }
    return 0;
}
