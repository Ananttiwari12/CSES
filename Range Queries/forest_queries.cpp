#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007
int a[1001][1001];

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
    		char x;cin>>x;
    		if(x=='*'){
    			a[i][j]=1;
    		}
    		else{
    			a[i][j]=0;
    		}
    	}
    }

    int pre[n+1][n+1]{0};
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
    	}
    }

    while(q--){
    	int x1,y1,x2,y2;
    	cin>>x1>>y1>>x2>>y2;
    	cout<<pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]<<endl;
    }

    return 0;
}