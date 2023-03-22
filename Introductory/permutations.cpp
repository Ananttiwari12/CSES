#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;
    if(n==2 or n==3){
        cout<<"NO SOLUTION\n";
    }
    else{
        int a=(n+1)/2;
        cout<<a<<" ";
        int cnt=0;
        int size=1;


        vector<int>res;
        int i=0;int j=n;
        while(i!=a and j!=a){

            if(size==n)break;

            // if(i==a or j==a){
            // i++;j--;
            // continue;
            // }

            else if(cnt%2==0){
                cout<<j<<" ";
                j--;
            }
            else{
                cout<<i+1<<" ";
                i++;
            }
            cnt++;
            size++;
        }
        if(n%2!=0)
        cout<<a-1;
    }


    return 0;
}