#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int f(vector<vector<int>> &dp,int i,int sum,vector<int>& v)
{
    if(sum==0) return 1;
    if(i<0) return 0;
    if(dp[sum][i]!=-1) return dp[sum][i];
    int tk=0;
    int ntk=0;
    if(v[i]<=sum){
        tk=f(dp,v.size()-1,sum-v[i],v);
    }
    ntk=f(dp,i-1,sum,v);
    return dp[sum][i]=(tk+ntk)%mod;
}


int main()
{
    vector<int> v;
    for(int i=1;i<=6;i++) v.push_back(i);
    int sum;cin >> sum;
    vector<int> dp(sum+1);
    dp[0]=1;
    for(int i=1;i<=sum;i++){
    for(auto dice:v)
        {
            if(i>=dice)
            dp[i]=(dp[i]+dp[i-dice])%mod;
        }
    }

    cout << dp[sum] << endl;
    
}