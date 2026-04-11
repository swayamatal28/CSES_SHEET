#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &dp,int i,int sum,vector<int>& v)
{
    if(sum==0) return 0;
    if(i<0) return 1e9;
    if(dp[sum][i]!=-1) return dp[sum][i];
    int tk=1e9;
    int ntk=1e9;
    if(v[i]<=sum){
        tk=1+f(dp,v.size()-1,sum-v[i],v);
    }
    ntk=f(dp,i-1,sum,v);
    return dp[sum][i]=min(tk,ntk);
}

int main()
{
    int n,x;cin >> n >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    // vector<vector<int>> dp(x+1,vector<int>(n,-1));
    // int ans=f(dp,n-1,x,v);
    vector<int> dp(x+1,1e9);
    dp[0]=0;
    for(auto coin:v)
    {
        for(int i=1;i<=x;i++)
        {
            if(coin<=i){
                dp[i]=min(dp[i],1+dp[i-coin]);
            }
        }
    }
    if(dp[x]==1e9) cout << -1 << endl;
    else cout << dp[x] << endl;

    return 0;
}