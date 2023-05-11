#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007

struct Node{

	int sum;
	int prefix;
};

struct segmenttrees{
    vector<Node>st;
    int n;
    void init(int _n){
        this->n=_n;
        st.resize(4*n);
    }
    void build(int start, int ending, int node, vector<int>&v){
        if(start==ending){
            st[node].sum=v[start];
            st[node].prefix=v[start];
            return;
        }
        int mid=(start+ending)/2;
        build(start, mid, 2*node+1 ,v);
        build(mid+1, ending, 2*node+2, v);

		st[node].sum=st[node*2+1].sum+st[node*2+2].sum;
		st[node].prefix=max(st[node*2+1].prefix,st[node*2+1].sum+st[node*2+2].prefix);
    }

    Node Query(int start, int ending, int l, int r, int node){
        if(start>r || ending<l){
        	Node temp;
        	temp.sum=0;
        	temp.prefix=0;
            return temp;
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid=(start+ending)/2;
        Node q1=Query(start, mid, l ,r,2*node+1);
        Node q2=Query(mid+1, ending, l ,r,2*node+2);

        Node res;
        res.sum=q1.sum+q2.sum;
        res.prefix=max(q1.prefix, q1.sum+q2.prefix);
        return res;
    }
    void update(int start, int ending, int node, int index,int value){

        if(start==ending){
        	st[node].sum=value;
        	st[node].prefix=value;
        return;
        }

        int mid=(start+ending)/2;
        if(index<=mid){
        	update(start, mid, 2*node+1, index, value);
        }
        else{
        	update(mid+1, ending, 2*node+2, index, value);
        }

    	st[node].sum=st[node*2+1].sum+st[node*2+2].sum;
		st[node].prefix=max(st[node*2+1].prefix,st[node*2+1].sum+st[node*2+2].prefix);
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

    	int t; cin>>t;
    	if(t==1){
    		int k,u; cin>>k>>u;
    		st.update(k-1,u);
    	}
    	else{
    		int a,b; cin>>a>>b;	
    		Node ans=st.query(a-1,b-1);
    		cout<<max((int)0,ans.prefix)<<endl;
    	}
    }
    return 0;
}