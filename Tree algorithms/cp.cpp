#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--){
    int n; cin>>n;
    if(n%2!=0){
    	cout<<-1<<endl;
    }

    else if(n==2){
        cout<<2<<" "<<1<<endl;
    }
    else{

        for(int i=1;i<=n;i++){
            if(i%2!=0){
                cout<<i+1<<" ";
            }
            else cout<<i-1<<" ";

        }
        cout<<endl;

    }
    }
    return 0;
}
