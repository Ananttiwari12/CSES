#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int fibo[46];

bool solve(int n, int x, int y){

	if(n==0)return true;

	int w=fibo[n+1];
	int h=fibo[n];
	int nxt_y=x;

	if(y>h or w-h>=y){
		if(w-h>=y){
			x=y;
		}
		else{
			x=y-h;
		}
		return solve(n-1,x,nxt_y);
	}

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

    int t; cin>>t;
    fibo[0]=1;
    fibo[1]=1;

    for(int i=2;i<=45;i++){
    	fibo[i]=fibo[i-1]+fibo[i-2];
    }

    while(t--){

    int n,x,y;
    cin>>n>>x>>y;

    bool ans=solve(n,x,y);

    if(ans){
    	cout<<"YES"<<endl;
    }
    else{
    	cout<<"NO"<<endl;
    }

    }
    return 0;
}