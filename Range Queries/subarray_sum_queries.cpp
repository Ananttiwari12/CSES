#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007

struct Node{
	int sum;
	int prefix;
	int suff;
	int ans;
};

struct segmenttrees{
    vector<Node>st;
    int n;
    void init(int _n){
        this->n=_n;
        st.resize(4*n);
    }

    Node base(int val){
    	Node res;
    	res.sum=val;
    	res.prefix=res.suff=res.ans=max((int)0,val);
    	return res;
    }

    Node combine(Node l, Node r){
    	Node res;
    	res.sum=l.sum+r.sum;
    	res.prefix=max(l.prefix, l.sum+r.prefix);
    	res.suff=max(r.suff, r.sum+l.suff);
    	res.ans=max({l.ans,r.ans,l.suff+r.prefix});
    	return res;
    }

    void build(int start, int ending, int node, vector<int>&v){
        if(start==ending){
            st[node]=base(v[start]);
            return;
        }
        int mid=(start+ending)/2;
        build(start, mid, 2*node+1 ,v);
        build(mid+1, ending, 2*node+2, v);
        st[node]=combine(st[2*node+1], st[2*node+2]);
    }

    Node Query(int start, int ending, int l, int r, int node){
        if(start>r || ending<l){
        	st[node]=base(0);
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid=(start+ending)/2;
        Node q1=Query(start, mid, l ,r,2*node+1);
        Node q2=Query(mid+1, ending, l ,r,2*node+2);

        Node res=combine(q1,q2);
        return res;
    }
    void update(int start, int ending, int node, int index,int value){

        if(start==ending){
        	st[node]=base(value);
        return;
        }

        int mid=(start+ending)/2;
        if(index<=mid){
        	update(start, mid, 2*node+1, index, value);
        }
        else{
        	update(mid+1, ending, 2*node+2, index, value);
        }

		st[node]=combine(st[node*2+1], st[node*2+2]);
    	return;
    }

    void build(vector<int>&v){
        build(0, n-1, 0, v);
        }

    Node query(int l, int r){
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
    vector<int>a(n);
  
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    segmenttrees st;
    st.init(n);
    st.build(a);

    while(q--){

    	int idx,val;
    	cin>>idx>>val;

    	st.update(idx-1,val);
    	Node ans=st.query(0,n-1);
    	cout<<ans.ans<<endl;
    	
    }
    return 0;
}