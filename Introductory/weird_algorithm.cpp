#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){

    int n; cin>>n;
    cout<<n<<" ";

    while((n&(n-1))){
        if(n%2==0){
            n/=2;
            cout<<n<<" ";
        }
        else{
        n=(3*n)+1;
        cout<<n<<" ";
        }
    }
    while(n!=1){
        n/=2;
        cout<<n<<" ";
    }
    return 0;
}