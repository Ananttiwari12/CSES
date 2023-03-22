#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin>>s;
    int maxi=0;
    int cnt=1;

    for(int i=0; i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
        if(s[i]!=s[i+1]){
        maxi=max(maxi,cnt);
        cnt=1;
        }
        
    }
    maxi=max(maxi,cnt);
    cout<<maxi<<endl;

    return 0;
}