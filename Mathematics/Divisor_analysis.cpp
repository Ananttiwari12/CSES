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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int sum=1;
    int no=1;

    int prime[n];
    int power[n];

    for(int i=0;i<n;i++){
    	int a,p;
    	cin>>a>>p;

    	prime[i]=a;
    	power[i]=p;

    	
    	no=((no%mod)*((1+p)%mod)%mod)%mod;
    	no%=mod;

    	int num=(modpwr(a,p+1)%mod-1+mod)%mod;
    	int den=modpwr(a-1,mod-2)%mod;

		sum=(((sum%mod)*num)%mod*den)%mod;
		sum%=mod;
    }

    int cnt=0;
    int pos=0;

    for(int i=0;i<n;i++){
    	if(power[i]%2==1){
    		cnt=1;
    		pos=i;
    	}
    }

    int product=1;

    if(cnt){
    	int outer_pwr=1;

	    for(int i=0;i<n;i++){
	    	if(i==pos)
	    		outer_pwr= (outer_pwr*((power[i]+1)/2))%(mod-1);
	    	else
	    		outer_pwr=(outer_pwr*(power[i]+1))%(mod-1);
		}

		for(int i=0;i<n;i++){
			product=(product*modpwr(prime[i],(power[i]*outer_pwr)%(mod-1)))%mod;
		}
    }

    else{
    	int outer_pwr=1;

	    for(int i=0;i<n;i++){
	    	outer_pwr=(outer_pwr*(power[i]+1))%(mod-1);
		}
		for(int i=0;i<n;i++){
			product=(product*modpwr(prime[i],((power[i]/2)*outer_pwr)%(mod-1)))%mod;
		}
    }







    cout<<no<<" "<<sum<<" "<<product;

    
    
    return 0;
}