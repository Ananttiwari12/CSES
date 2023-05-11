#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007

int a[1001][1001];

vector<vector<int>>bit(1001,vector<int>(1024,0));

void update(int x, int y, int val){
	
	for(int i=x;i<1001;i+=(i&(-i))){
		for(int j=y;j<1001;j+=(j&(-j))){
			bit[i][j]+=val;
		}
	}
}
int query(int x, int y){
	int r=0;
	for(int i=x;i>0;i-=(i&(-i))){
		for(int j=y;j>0;j-=(j&(-j))){
			r+=bit[i][j];
		}
	}
	return r;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;
    
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		char x; cin>>x;
    		if(x=='.')a[i][j]=0;
    		else{
    			a[i][j]=1;
    			update(i,j,1);
    		}
    	}
    }

    while(q--){
    	int t; cin>>t;
    	if(t==1){

    		int x,y; cin>>x>>y;
    		if(a[x][y]==1){
    			update(x,y,-1);
    		}
    		else{
    			update(x,y,1);
    		}
    		a[x][y]^=1;
    	}
    	else{
    		int x1,y1,x2,y2;
    		cin>>x1>>y1>>x2>>y2;

    		int ans=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
    		cout<<ans<<endl;
    	}
    }

    return 0;
}