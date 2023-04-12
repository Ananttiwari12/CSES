#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=200001;
vector<int>gr[N];

int node;

int visited[200001];
int parent[200001];

vector< int > v;

bool dfs(int src, int par){

	visited[src]=1;
	v.push_back(src);

	for(auto child: gr[src]){
		if(!visited[child]){
			if(dfs(child,src)==true)return true;
		}
		else{
		if(child!=par){
			v.push_back(child);
			return true;
		}
	}
	}
	v.pop_back();
	return false;
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

    memset(visited,0,sizeof(visited));
  
    int cnt=0;

	vector<int>ans;
    for(int i=1;i<=n;i++){
    	if(!visited[i]){
    		if((dfs(i,0))==true){
    			cnt++;
    			ans.push_back(v[v.size()-1]);
    			for(int i=v.size()-2;i>=0;i--){
    				ans.push_back(v[i]);
    				if(v[i]==v[v.size()-1]){
    					break;
    				}
    			}
    			break;
    		}
    	}
    }

   	
   	if(cnt==0){
   		cout<<"IMPOSSIBLE";
   	}
   	else{
   		cout<<ans.size()<<endl;
   		for(int i=0;i<ans.size();i++){
   			cout<<ans[i]<<" ";
   		}
   	}

    


   
   


    
    
    return 0;
}