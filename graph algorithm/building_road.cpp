#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

vector<int>gr[200001];

bool visited[100001];

void dfs(int src){
	visited[src]=true;
	for(auto node: gr[src]){
		if(!visited[node]){
			dfs(src);
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

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
    	int x,y; cin>>x>>y;
    	gr[x].push_back(y);
    	gr[y].push_back(x);
    }
    int cnt=0;
    vector<int>v;
    for(int i=1;i<=n;i++){
    	if(!visited[i]){
    		cnt++;
    		v.push_back(i);
    		dfs(i);
    	}
    }

    if(cnt==1){
    	cout<<0<<endl;
    }
    else{
    	cout<<cnt-1<<endl;
    	for(int i=0;i<v.size()-1;i++){
    		cout<<v[i]<<" "<<v[i+1]<<endl;
    	}



    }

    

    
    
    return 0;
}