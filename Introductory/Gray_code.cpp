#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

vector<int>convert_to_binary(int n){
    vector<int>ans;
    int power_of_10=1;
    while(n>0){
    ans.push_back(n&1);
    n=n>>1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void printgraycode(vector<int>v, int a){
    vector<int>res;
    int ans=0;
    res.push_back(ans^v[0]);
    for(int i=0; i<v.size()-1;i++){
        res.push_back(v[i]^v[i+1]);
    }
    for(int i=0; i<a-(res.size());i++){
        cout<<"0";
    }
    for(int i=0; i<res.size();i++){
        cout<<res[i];
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
int n; cin>>n;
int limit= pow(2,n);
for(int i=0; i<n;i++){
    cout<<"0";
}
cout<<endl;
for(int i=1; i<limit;i++){
    vector<int>aa=convert_to_binary(i);
    printgraycode(aa,n);
    cout<<endl;
}  
    return 0;
}