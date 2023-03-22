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

    int n,k; cin>>n>>k;
    int a[n];

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    if(k==1){
        for(int i=0;i<n;i++){
            cout<<0<<" ";
        }
        return 0;
    }

    if(k==2){
        for(int i=1;i<n;i++){
            cout<<abs(a[i-1]-a[i])<<" ";
        }
        return 0;
    }

    set<pair<int,int>>lf;
    set<pair<int,int>>rt;

    int lsum=0;
    int rsum=0;
    vector<pair<int,int>>st;

    for(int i=0;i<k;i++){
        st.push_back({a[i],i});
    }

    sort(st.begin(), st.end());

    for(int i=0;i<k/2+(k%2);i++){
        lf.insert({st[i].first,st[i].second});
        lsum+=st[i].first;
    }
    for(int i=k/2+(k%2);i<k;i++){
        rt.insert({st[i].first,st[i].second});
        rsum+=st[i].first;
    }

    int median=lf.rbegin()->first;

    cout<<median*lf.size()-lsum+rsum-median*rt.size()<<" ";

    for(int i=1;i<n-k+1;i++){

        if(lf.count({a[i-1],i-1})){
            lf.erase({a[i-1],i-1});
            lsum-=a[i-1];
        }
        else{
            rt.erase({a[i-1],i-1});
            rsum-=a[i-1];
        }

        if(*(lf.rbegin())<make_pair(a[i+k-1],i+k-1)){
            rsum+=a[i+k-1];
            rt.insert({a[i+k-1],i+k-1});
        }
        else{
            lsum+=a[i+k-1];
            lf.insert({a[i+k-1],i+k-1});
        }

        while(lf.size()<k/2+(k%2)){
            pair<int,int>p=(*rt.begin());
            lf.insert(p);
            lsum+=p.first;
            rt.erase(p);
            rsum-=p.first;
        }
        while(lf.size()>k/2+(k%2)){
            pair<int,int>p=*lf.rbegin();
            rt.insert(p);
            rsum+=p.first;
            lf.erase(p);
            lsum-=p.first;
        }

        median=lf.rbegin()->first;
        cout<<median*lf.size()-lsum+rsum-median*rt.size()<<" ";
    }
    return 0;
}