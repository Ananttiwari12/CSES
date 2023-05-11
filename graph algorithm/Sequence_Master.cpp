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
    n*=2;

    int a[n];

    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=abs(a[i]);
    }

    sort(a,a+n);    

    if(n==2){
        ans=min(ans,abs(a[1]-a[0]));
    }

    if(n==4){
        int temp=0;
        for(int i=0;i<n;i++){
            temp+=abs(a[i]-2);
        }

        ans=min(ans,temp);
    }

    if(n%4==0){
        int temp=0;

        for(int i=0;i<n-1;i++){
            temp+=abs(a[i]+1);
        }
        temp+=abs(a[n-1]-(n/2));
        ans=min(ans,temp);
    }

    cout<<ans<<endl;
    }
    return 0;
}