#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007

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
        st[node]=max(st[node*2+1],st[node*2+2]);
    }

    int query(int start, int ending, int l, int r, int node){
        if(start>r || ending<l){
            return -1e18;
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid=(start+ending)/2;
        int q1=query(start, mid, l ,r,2*node+1);
        int q2=query(mid+1, ending, l ,r,2*node+2);
        return max(q1,q2);
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
        st[node]=max(st[node*2+1],st[node*2+2]);
        return;
    }

    void build(vector<int>&v){
        build(0, n-1, 0, v);
        }

    int query(int l, int r){
        return query(0, n-1, l, r, 0);
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

    int n,m; cin>>n>>m;

   	vector<int>a;

    for(int i=0;i<n;i++){
        int x; cin>>x;
    	a.push_back(x);
    }

    segmenttrees tmx;
    tmx.init(n);
    tmx.build(a);


   
   	for(int i=0;i<m;i++){

   		int val; cin>>val;

        int s=0, e=n;
        int mid;

        while(s<e){
            mid=(s+e)/2;
            if(tmx.query(0,mid)>=val){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }

        if(s>=n){
            cout<<0<<" ";
        }
        else{
            cout<<s+1<<" ";
            tmx.update(s,tmx.query(0,s)-val);
        }

   		
   	}

    return 0;
}
