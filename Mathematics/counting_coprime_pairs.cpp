#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<pair<int,int>>v;

        for(int i=0;i<intervals.size();i++){
            v.push_back({intervals[i][0],intervals[i][1]});
        }

        sort(v.begin(),v.end());

        int s=v[0].second;
        int f=v[0].first;
        int i=0;
        int j=1;
        int n=v.size();
        vector<pair<int,int>>a;
        for(int i=0;i<n;){
            while(v[j].first<=s){
                s=v[j].second;
                j++;
            }
            a.push_back({f,s});
            i=j;
            f=v[i].first;
            s=v[i].second;
        }

        vector<vector<int>>ans;

        for(auto x:a){
            ans.push_back({x.first,x.second});
        }

        return ans;
        


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

    

    
    
    return 0;
}