#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007

int modpwr(int a, int b){
    int res=1;
    while(b){
        if(b&1) res=res*a, res%=mod;
        a=a*a, a%= mod;
        b>>=1;
    }
    return res;
}

int multiply(int a, int b){
	return ((a%mod)*(b%mod))%mod;
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
    int ans=0;

    int next;
    for(int i=1;i<=n;i=next){

    	int q=n/i;
    	next=n/q+1;

    	int sum_till_i_minus1=(multiply(i,i-1)*modpwr(2,mod-2))%mod;
    	int sum_till_next_minus1=(multiply(next,next-1)*modpwr(2,mod-2))%mod;

    	int sum_from_q_to_next=(sum_till_next_minus1-sum_till_i_minus1+mod)%mod;

    	int calc=multiply(sum_from_q_to_next, q);
    	ans=(ans+calc)%mod;
    	ans%=mod;
    }

    cout<<ans<<endl;
    
    return 0;
}
