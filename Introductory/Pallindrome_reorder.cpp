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
 
 
    string s;
    cin>>s;
    string ans="";
 
    int a[26]{0};

 
    char cc;
    int fre=0;
 
    int cnt=0;
    for(int i=0;i<s.length();i++){
        a[s[i]-'A']++;
    }
    for(int i=0;i<26;i++){
        if(a[i]%2!=0){
            fre=a[i];
            cc=i+'A';
            cnt++;
        }
        if(s.length()%2==0 and cnt==1)break;
        if(cnt==2)break;
    }
 
    if(s.length()%2==0 and cnt!=0){
            cout<<"NO SOLUTION";
    }
 
    else if(cnt>1){
        cout<<"NO SOLUTION";
    }
    else{
 
        for(int i=0;i<26;i++){
            if((a[i]%2)==0){
                for(int j=0;j<(a[i])/2;j++){
                    ans.push_back(i+'A');
                    
                }
            }
        }

        if(fre!=0){
            for (int i = 0; i < fre; ++i)
            {
                ans.push_back(cc);
            }
        }

for(int i=25;i>=0;i--){
            if((a[i]%2)==0){
                for(int j=0;j<(a[i])/2;j++){
                    ans.push_back(i+'A');
                    
                }
            }
        }
        cout<<ans;
    }
    return 0;
}