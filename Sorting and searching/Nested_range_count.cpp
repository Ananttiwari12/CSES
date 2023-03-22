#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

struct ranges{
	int left;
	int right;
	int index;
};

bool compare(ranges a, ranges b){
	if(a.left<b.left) return true;
	if(a.left>b.left) return false;
	return a.right>b.right;
}

bool compare2(pair<int,int>&a, pair<int,int>&b){
	if(a.first<b.first) return true;
	if(a.first>b.first) return false;
	return a.second>b.second;
}

void add(vector<int>&tree, int n, int x, int y){
	while(x<=n){
		tree[x]+=y;
		x+=(x&(-x));
	}
}

int query(vector<int>&tree,int x){
	int ans=0;
	
	while(x>0){
		ans+=tree[x];
		x-=(x&(-x));
	}
	return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    vector<ranges>v(n);

    for(int i=0;i<n;i++){
    	int l,r; cin>>l>>r;
        v[i]={l,r,i};
    }

    sort(v.begin(), v.end(), compare);

    vector<pair<int,int>>opening(n);
    vector<pair<int,int>>closing(n);

    for(int i=0;i<n;i++){
    	opening[i]={v[i].left, v[i].index};
    	closing[i]={v[i].right, i};
    }

    sort(closing.begin(), closing.end(),compare2);

    vector<int>fn1(n+1,0);
    vector<int>fn2(n+1,0);

    vector<int>ans(n);
    int i=0; int j=0;

    while(i<n || j<n){
    	if(i<n and opening[i].first<closing[j].first){
    		add(fn1,n,i+1,1);
    		i++;
    	}
    	else{
    		add(fn1,n,closing[j].second+1,-1);
    		int val=query(fn1,closing[j].second+1);
    		int idx=closing[j].second;
    		int actual_index=opening[idx].second;
    		ans[actual_index]=val;
    		j++;
    	}
    }

    vector<int>ans2(n);
    i=0,j=0;

    while(i<n || j<n){
    	if(i<n and opening[i].first<closing[j].first){
    		i++;
    	}
    	else{
    		int val=query(fn2,closing[j].second+1);
    		int idx=closing[j].second;
    		int actual_index= opening[idx].second;
    		ans2[actual_index]=val;
    		add(fn2, n,1,1);

    		if(closing[j].second+2<=n){
    			add(fn2, n,closing[j].second+2,-1);
    		}
            j++;
    	}
    }

    for(int i=0;i<n;i++){
    	cout<<ans2[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}