// #include<bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// #define int long long


// #define mod 1000000007

// struct segmenttrees{
//     vector<int>st;
//     int n;
//     void init(int _n){
//         this->n=_n;
//         st.resize(4*n,0);
//     }
//     void build(int start, int ending, int node, vector<int>&v){
//         if(start==ending){
//             st[node]=v[start];
//             return;
//         }
//         int mid=(start+ending)/2;
//         build(start, mid, 2*node+1 ,v);
//         build(mid+1, ending, 2*node+2, v);
// 		st[node]=st[node*2+1]+st[node*2+2];
//     }

//     int Query(int start, int ending, int l, int r, int node){
//         if(start>r || ending<l){
//             return 0;
//         }
//         if(start>=l && ending<=r){
//             return st[node];
//         }
//         int mid=(start+ending)/2;
//         int q1=Query(start, mid, l ,r,2*node+1);
//         int q2=Query(mid+1, ending, l ,r,2*node+2);
//         return q1+q2;
//     }
//     void update(int start, int ending, int node, int index,int value){
//         if(start==ending){
//         st[node]=value;
//         return;
//         }
//         int mid=(start+ending)/2;
//         if(index<=mid){
//         update(start, mid, 2*node+1, index, value);
//         }
//         else{
//         update(mid+1, ending, 2*node+2, index, value);
//         }
//     	st[node]=st[node*2+1]+st[node*2+2];
//     	return;
//     }

//     void build(vector<int>&v){
//         build(0, n-1, 0, v);
//         }

//     int Query(int l, int r){
//         return Query(0, n-1, l, r, 0);
//         }

//     void update(int x, int y){
//         update(0, n-1, 0, x, y);
//         }
//    	};


// #include<bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// #define int long long


// #define mod 1000000007




// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif

//     int t; cin>>t;
//     while(t--){

//     int n; cin>>n;

//     vector<int>a(n);



//     for(int i=0;i<n;i++){
//     	cin>>a[i];
//     }

//     if(a[0]==1){
//     	cout<<n-1<<endl;
//     	continue;
//     }

    

//     segmenttrees st;
//     st.init(n);
//     st.build(a);
//     int ans=INT_MIN;

//     for(int i=0;i<n;i++){
//     	int len=i+1;

//     	int reqsum=(len*(len+1))/2;

//     	int sm1=st.Query(0,i);
//     	int sm2=st.Query(i,n-1);

//     	if(sm2==reqsum){
//     		ans=max(ans,i+1);
//     	}
//     	if(sm1==reqsum){
//     		ans=max(ans,n-i-1);
//     	}

//     	int rem1=(n*(n+1))/2-(len*(len+1))/2;

//     	int s=i+1;
//     	int e=n-1;

//     	while(s<=e){
//     		int pre=st.Query(i,e);
//     		if(pre==rem1){
//     			ans=max(ans,e-s);
//     			break;
//     		}
//     		else e--;
//     	}
//     }

//     cout<<ans<<endl;



    




//     }
//     return 0;

// }


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
		st[node]=st[node*2+1]+st[node*2+2];
    }

    int Query(int start, int ending, int l, int r, int node){
        if(start>r || ending<l){
            return 0;
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid=(start+ending)/2;
        int q1=Query(start, mid, l ,r,2*node+1);
        int q2=Query(mid+1, ending, l ,r,2*node+2);
        return q1+q2;
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
    	st[node]=st[node*2+1]+st[node*2+2];
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

    int t; cin>>t;
    while(t--){

    int n; cin>>n;

    vector<int>a(n);



    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    if(a[0]==1){
    	cout<<n-1<<endl;
    	continue;
    }

    

    segmenttrees st;
    st.init(n);
    st.build(a);
    int ans=INT_MIN;

    for(int i=0;i<n;i++){
    	int len=i+1;

    	int reqsum=(len*(len+1))/2;

    	int sm1=st.Query(0,i);
    	int sm2=st.Query(i,n-1);

    	if(sm2==reqsum){
    		ans=max(ans,i+1);
    	}
    	if(sm1==reqsum){
    		ans=max(ans,n-i-1);
    	}
	}
    	ans=1;

   		map<int,int>mp;

   		for(int i=0;i<n;i++){
   			mp[a[i]]=i+1;
   		}

   		int mx_pos=mp[n];
   		int mn_pos=mp[n];

   		for(int i=n;i>=2;i--){

   			mx_pos=max(mp[i],mx_pos);
   			mn_pos=min(mp[i],mn_pos);

   			int avail=mx_pos-mn_pos+1;
   			int rq=n-i+1;

   			if(avail==rq){
   				ans=max(ans,avail);
   			}
   		}

   		cout<<ans<<endl;


    




    }
    return 0;

}

