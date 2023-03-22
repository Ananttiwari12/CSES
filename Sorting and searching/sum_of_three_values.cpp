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

    int n,x; cin>>n>>x;
    int a[n];
    int idx1,idx2,idx3;


    map<int,int>mp;
	int cnt=0;

    set<int>s;

    for(int i=0;i<n;i++){
    	cin>>a[i];
    	mp[a[i]]++;
    	s.insert(a[i]);
    }
     if(n<=2){
     	cout<<"IMPOSSIBLE";
     	return 0;
     }
  

	set<int>st;

    for(int i=0;i<n;i++){
    	if(cnt==1)break;
    	if(st.count(a[i])) continue;
    	int a1=a[i];
    	int rem=x-a1;
    	st.insert(a[i]);

    	for(int j=0;j<n;j++){
    		int a2=a[j];
    		int a3=rem-a2;

    		if(i==j) continue;
    		if(!s.count(a3)){
    			continue;
    		}
    		else{
    			if(a1==a2 and a2==a3){
    				if(mp[a1]>=3){
    					cnt++;
    					idx1=i;
    					idx2=j;
    					for(int k=0;k<n;k++){
    						if(k==idx1) continue;
    						if(k==idx2) continue;
    						if(a[k]==a3){
    							idx3=k;
    							break;
    						}
    					}
    				}

    				else{
    					continue;
    				}
    			}

    			else if(a1==a2 and a2!=a3){
    				if(mp[a1]>=2){
    					cnt++;
    					idx1=i;
    					idx2=j;

    					for(int k=0;k<n;k++){
    						if(k==idx2) continue;
    						if(k==idx1) continue;

    						if(a[k]==a3){
    							idx3=k;
    							break;
    						}
    					}
    				}

    				else{
    					continue;
    				}
    			}

    			else if(a1!=a2 and a2==a3){
    				if(mp[a2]<2)continue;

    				idx1=i;
    				idx2=j;
    				cnt++;

    				for(int k=0;k<n;k++){
    					if(k==idx2) continue;
    					if(k==idx1) continue;

    					if(a[k]==a3){
    						idx3=k;
    						break;
    					}
    				}
    			}

    			else if(a1!=a2 and a1==a3){
    				if(mp[a1]>=2){
    					idx1=i;
    					idx2=j;

    					for(int k=0;k<n;k++){
    						if(k==idx2) continue;
    						if(k==idx1) continue;

    						if(a[k]==a3){
    							idx3=k;
    							break;
    						}
    					}
    				}
    				else{
    					continue;
    				}
    			}
    			else if(a1!=a2 and a2!=a3){
    				idx1=i;
    				idx2=j;
    				cnt++;

    				for(int k=0;k<n;k++){
    					if(k==idx1) continue;
    					if(k==idx2) continue;

    					if(a[k]==a3){
    				// cout<<"YES";
    						idx3=k;
    						break;
    					}
    				}
    			}
    			else{
    				continue;
    			}
    		}
    		if(cnt==1) break;
    	}
}
    if(cnt==1){
    	cout<<idx1+1<<" "<<idx2+1<<" "<<idx3+1;
    }
    else{
    	cout<<"IMPOSSIBLE";
    }
    return 0;
}