#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int visited[1001][1001];
int n;
int m;
char s[1001][1001];

bool isvalid(int x, int y){
	if(x<0 or y>=m or x>=n or y<0)return false;
	if(visited[x][y])return false;
	if(s[x][y]=='#')return false;
	return true;
}

void dfs(int x, int y){

	visited[x][y]=1;

	if(isvalid(x-1,y))dfs(x-1,y);
	if(isvalid(x+1,y))dfs(x+1,y);
	if(isvalid(x,y-1))dfs(x,y-1);
	if(isvalid(x,y+1))dfs(x,y+1);

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    for(int i=0;i<n;i++){ 
    	for(int j=0;j<m;j++){
    		cin>>s[i][j];
    	}
    }    

    memset(visited,0,sizeof(visited));
    int cnt=0;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(!visited[i][j] and s[i][j]=='.'){
    			dfs(i,j);
    			cnt++;
    		}
    	}
    }

    cout<<cnt;


   	



    
    
    return 0;
}