#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1001;

char s[1001][1001];

int n,m;

struct pos{
    int px, py;
};

int mons_step[1001][1001];
int ans_step[1001][1001];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int visited1[1001][1001];
int visited2[1001][1001];

int idx[1001][1001];

bool isvalid1(int x, int y){
    if(x<0 or y<0 or x>=n or y>=m)return false;
    if(s[x][y]=='#')return false;
    if(visited1[x][y]!=0)return false;
    return true;
}
bool isvalid2(int x, int y){
    if(x<0 or y<0 or x>=n or y>=m)return false;
    if(s[x][y]=='#')return false;
    if(visited2[x][y]!=0)return false;
    return true;
}

char path[]={'D','R','U','L'};

void bfs_monster(){

    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='M'){
                q.push({i,j});
                mons_step[i][j]=0;
                visited1[i][j]=1;
            }
        }
    }

    while(!q.empty()){
        pair<int,int>p=q.front();

        int x=p.first;
        int y=p.second;
        q.pop();

        for(int i=0;i<4;i++){

            int nxt_x= x + dx[i];
            int nxt_y= y + dy[i];

            if(isvalid1(nxt_x,nxt_y)){

                q.push({nxt_x,nxt_y});
                visited1[nxt_x][nxt_y]=1;
                mons_step[nxt_x][nxt_y]=1+mons_step[x][y];

            }
        }
    }
}

void bfs(int x, int y){

    queue<pair<int,int>>q;
    q.push({x,y});

    visited2[x][y]=1;
    ans_step[x][y]=0;

    while(!q.empty()){

        pair<int,int>p=q.front();
        q.pop();

        int X=p.first;
        int Y=p.second;


        for(int i=0;i<4;i++){

            int nx=X+dx[i];
            int ny=Y+dy[i];

            if(isvalid2(nx,ny)){
                visited2[nx][ny]=1;
                idx[nx][ny]=i;
                q.push({nx,ny});
                ans_step[nx][ny]=1+ans_step[X][Y];

            }
        }
    }
}

 pos ans_valid(){

    for(int i=0;i<n;i++){
        if(s[i][0]=='.' and visited2[i][0]==1){
            if(ans_step[i][0]<mons_step[i][0])
            return {i,0};
        }
        if(s[i][m-1]=='.' and visited2[i][m-1]==1){
            if(ans_step[i][m-1]<mons_step[i][m-1])
            return {i,m-1};
        }
    }

    for(int i=0;i<m;i++){
        if(s[0][i]=='.' and visited2[0][i]==1){
            if(ans_step[0][i]<mons_step[0][i])
            return {0,i};
        }
        if(s[n-1][i]=='.' and visited2[n-1][i]==1){
            if(ans_step[n-1][i]<mons_step[n-1][i])
            return {n-1,i};
        }
    }

    return {-1,-1};

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
            mons_step[i][j]=INT_MAX;
        }
    }

    int sx,sy;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>s[i][j];
            if(s[i][j]=='A'){
                sx=i;sy=j;
            }
            else if(s[i][j]=='#'){
                visited1[i][j]=1;
                visited2[i][j]=1;
            }
        }
    }


    if(sx==0 or sx==n-1){
        cout<<"YES"<<endl;
        cout<<0;
        return 0;
    }    
    if(sy==0 or sy==m-1){
        cout<<"YES"<<endl;
        cout<<0;
        return 0;

    }

    bfs_monster();


    bfs(sx,sy);

    pos ck=ans_valid();

    if(ck.px==-1 and ck.py==-1){
        cout<<"NO";
        return 0;
    }

    string ans="";

    while(sx!=ck.px or sy!=ck.py){
        ans+=path[idx[ck.px][ck.py]];

        ck={
            ck.px-dx[idx[ck.px][ck.py]],
            ck.py-dy[idx[ck.px][ck.py]]
        };

    }

    reverse(ans.begin(), ans.end());

    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }










    
    
    return 0;
}