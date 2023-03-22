#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
int cnt=0;
vector<pair<char,char>>v;

void Towerofhanoi(int n, char from, char helper, char to){
    if(n==0) return;
    cnt++;
    Towerofhanoi(n-1,from,to, helper);

    v.push_back({from,to});
    Towerofhanoi(n-1,helper,from,to);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;


    Towerofhanoi(n,'1','2','3');
    cout<<cnt<<endl;
    for(auto x: v){
        cout<<x.first<<" "<<x.second<<endl;
    }

    
    return 0;
}