#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int n,m;
char s[1001][1001];
int visited[1001][1001];
int dist[1001][1001];
int ex,ey,sx,sy;

char par[1001][1001];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

char path[]={'D','U','R','L'};


bool isvalid(int x, int y){
	if(x<0 or y>=m or x>=n or y<0)return false;
	if(visited[x][y])return false;
	if(s[x][y]=='#')return false;
	return true;
}

void bfs(int x, int y){

	dist[x][y]=0;
	visited[x][y]=1;

	queue<pair<int,int>>q;
	q.push({x,y});

	while(!q.empty()){
		pair<int,int>p=q.front();
		q.pop();
		for(int i=0;i<4;i++){

			int nxt_X=p.first+dx[i];
			int nxt_Y=p.second+dy[i];

			if(isvalid(nxt_X,nxt_Y)){
				visited[nxt_X][nxt_Y]=1;
				q.push({nxt_X,nxt_Y});
				dist[nxt_X][nxt_Y]=dist[p.first][p.second]+1;
				par[nxt_X][nxt_Y]=i;
			}
		}
		if(visited[ex][ey])break;
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

    cin>>n>>m;

    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>s[i][j];
    		if(s[i][j]=='A'){
    			sx=i;sy=j;
    		}    		
    		if(s[i][j]=='B'){
    			ex=i;ey=j;
    		}
    	}
    }

    bfs(sx,sy);

    if(dist[ex][ey]==0){
    	cout<<"NO";
    	return 0;
    }

    cout<<"YES"<<endl;
    int pathlength=dist[ex][ey];
    cout<<dist[ex][ey]<<endl;

    vector<int>ans;

    while(ex!=sx or ey!=sy){
    	ans.push_back(par[ex][ey]);
    	int init_ex=ex-dx[par[ex][ey]];;
    	int init_ey=ey-dy[par[ex][ey]];;
    	ex=init_ex;
    	ey=init_ey;
    }

    reverse(ans.begin(), ans.end());

    for(int i=0;i<ans.size();i++){
    	cout<<path[ans[i]];
    }

    return 0;
}