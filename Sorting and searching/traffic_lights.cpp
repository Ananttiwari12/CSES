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

    int x,n; cin>>x>>n;

    set<int>pos;
    multiset<int>len;

    pos.insert(0);
    pos.insert(x-0);

    len.insert(x);

    for(int i=0;i<n;i++){
        int add;cin>>add;

        pos.insert(add);
        auto it=pos.find(add);
        int prv= *prev(it);
        int nxt= *next(it);

        len.erase(len.find(nxt-prv));
        len.insert(nxt-add);
        len.insert(add-prv);

        cout<<*len.rbegin()<<" ";

    }
    return 0;
}