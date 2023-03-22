#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long


struct segmenttrees{
    vector<int>st;
    int n;
    void init(int _n){
        this->n=_n;
        st.resize(4*n,0);
    }

    void build(int start, int ending, int node, vector<int>&v){
        if(start==ending){
            st[node]=v[start];
            return;
        }
        int mid=(start+ending)/2;
        build(start, mid, 2*node+1 ,v);
        build(mid+1, ending, 2*node+2, v);
        st[node]=min(st[node*2+1],st[node*2+2]);
    }

    int Query(int start, int ending, int l, int r, int node){
        if(start>r || ending<l){
            return INT_MAX;
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid=(start+ending)/2;
        int q1=Query(start, mid, l ,r,2*node+1);
        int q2=Query(mid+1, ending, l ,r,2*node+2);
        return min(q1,q2);
    }

    void update(int start, int ending, int node, int index,int value){
        if(start==ending){
        st[node]=value;
        return;
        }

        int mid=(start+ending)/2;
        if(index<=mid){
        update(start, mid, 2*node+1, index, value);
        }
        else{
        update(mid+1, ending, 2*node+2, index, value);
        }

    st[node]=min(st[node*2+1],st[node*2+2]);
    return;
    }

    void build(vector<int>&v){
        build(0, n-1, 0, v);
        }

    int Query(int l, int r){
        return Query(0, n-1, l, r, 0);
        }

    void update(int x, int y){
        update(0, n-1, 0, x, y);
        }
    };


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int n,q; cin>>n>>q;
    vector<int>v(n);
 
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    segmenttrees st;
    st.init(n);
    st.build(v);
 
    while(q--){
 
        int x,l,r;
        cin>>x>>l>>r;
        if(x==1){
            st.update(l-1,r);
        }
        else if(x==2){
            cout<<st.Query(l-1,r-1)<<endl;
        }
    }
    
    return 0;
}