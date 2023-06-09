#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

struct segmenttree{

vector<int>st, lazy;
int n;
void init(int _n){
    this-> n=_n;
st.resize(4*n,0);
lazy.resize(4*n,0);
}

void build(int start, int ending, int node, vector<int>&v){

    if(start==ending){
        st[node]=v[start];
        return;
    }

    int mid=(start+ending)/2;
    build(start, mid, 2*node+1, v);
    build(mid+1, ending, 2*node+2, v);

    st[node]= st[2*node+1] + st[2*node+2];
}

int query(int start, int ending, int node, int l, int r){

    // no overlapping case
    if(start>r || ending <l){
        return 0;
    }

    //pending updates
    if(lazy[node]!=0){
        st[node]+= lazy[node] * (ending-start+1);

        // propagating the updated value
        if(start!=ending){
            lazy[2*node +1]+=lazy[node];
            lazy[2*node +2]+=lazy[node];
        }
        lazy[node]=0;
    }

    // complete overlap case
    if(start>=l && ending<=r){
        return st[node];
    }

    int mid=(start+ending)/2;
    int q1=query(start, mid, node*2 + 1, l,r);
    int q2=query(mid+1, ending, node*2 + 2, l, r);

    return q1+q2;
}

void update(int start, int ending, int node, int l, int r, int value){
     // no overlapping case
    if(start>r || ending <l){
        return;
    }

    //pending updates
    if(lazy[node]!=0){
        st[node]+= lazy[node] * (ending-start+1);

        // propagating the updated value
        if(start!=ending){
            lazy[2*node +1]+=lazy[node];
            lazy[2*node +2]+=lazy[node];
        }
        lazy[node]=0;
    }

    // complete overlap case
    if(start>=l && ending<=r){
        st[node]+=value* (ending -start+1);

        if(start!=ending){
            lazy[2*node+1]+=value;
            lazy[2*node+2]+=value;
        }
        return;
    }

    // partial overlap case
    int mid=(start+ending)/2;
    update(start, mid, 2*node+1, l, r, value);
    update(mid+1, ending, 2*node+2, l, r, value);

    st[node]=st[2*node+1] + st[2*node+2];
    return;

}

void build(vector<int>&v){
    build(0, n-1, 0, v);
}

int query(int l, int r){
    return query(0, n-1, 0, l, r);
}

void update(int l, int r, int y){

    update(0, n-1, 0, l, r, y);
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
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

        segmenttree st;
        st.init(n);
        st.build(a);

    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int a,b,c; cin>>a>>b>>c;
            st.update(a-1,b-1,c);
        }
        else{
            int a; cin>>a;
            cout<<st.query(a-1,a-1)<<endl;
        }
    }



    return 0;
}




