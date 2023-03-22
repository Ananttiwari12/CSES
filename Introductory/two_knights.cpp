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

    int n; cin>>n;

    for(int i=1;i<=n;i++){
        cout<<(((i*i)*(i*i-1)) - 8- 24-((i-4)*4*4)- 16-((i-4)*24)-((i-4)*(i-4)*8))/2<<endl;
    }



    

    

    
    
    return 0;
}