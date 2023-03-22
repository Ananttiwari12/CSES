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

    int n,m; cin>>n>>m;
    int ticket[n];
    int cust[m];

    for(int i=0;i<n;i++){
    	cin>>ticket[i];
    }
    for(int i=0;i<m;i++){
    	cin>>cust[i];
    }
    sort(ticket,ticket+n);

   	multiset<int>s;

   	for(int i=0;i<n;i++){
   		s.insert(ticket[i]);
   	}

   	for(int i=0;i<m;i++){
   		auto it=s.lower_bound(cust[i]+1);

   		if(it==s.begin()){
   			cout<<-1<<endl;
   		}
   		else{
   			it--;
   			cout<<*it<<endl;
   			s.erase(it);
   		}
   	}

    
    
    return 0;
}