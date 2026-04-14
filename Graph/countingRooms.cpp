#include <bits/stdc++.h>
using namespace std;

// ---------------- PBDS ----------------
//won't compile here,run online or on some other IDE
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ---------------- MACROS ----------------
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll,ll>
#define vll vector<ll>

const int N = 1e5 + 11;
const ll mod = 1e9 + 7;

// ---------------- POWER ----------------
ll power(ll a, ll b, ll m = mod) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// ---------------- PRIORITY QUEUE ----------------
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define maxpq_ll priority_queue<ll>
#define minpq_ll priority_queue<ll, vector<ll>, greater<ll>>

// ---------------- PRIME UTILITIES ----------------
bool isPrime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

vector<ll> primeFactors(ll n) {
    vector<ll> factors;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            factors.pb(i);
            n /= i;
        }
    }
    if(n > 1) factors.pb(n);
    return factors;
}

vector<int> row={0,-1,0,1};
vector<int> col={-1,0,1,0};

bool isValid(int i,int j,int n,int m){
    return (i>=0 && j>=0 && j<m && i<n);
}

void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis,int n,int m)
{
    vis[i][j]=true;
    for(int p=0;p<4;p++){
        int nr=row[p]+i;
        int nc=col[p]+j;
        if(isValid(nr,nc,n,m) && grid[i][j]=='.' && !vis[nr][nc]){
            dfs(nr,nc,grid,vis,n,m);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
        }
    }

    int rooms=0;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]=='.'){
                rooms++;
                dfs(i,j,grid,vis,n,m);
            }
        }
    }
    cout << rooms << endl;


    return 0;
}