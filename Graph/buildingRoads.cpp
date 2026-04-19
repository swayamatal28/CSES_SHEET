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

class DSU{
    private:
    vector<int> size;
    vector<int> parent;
    public:
    DSU(int n)
    {
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int u)
    {
        if(parent[u]==u) return u;
        else return parent[u]=find(parent[u]);
    }
    void unionBySize(int u,int v)
    {
        int ulpu=find(u);
        int ulpv=find(v);
        if(ulpu==ulpv) return;
        if(size[ulpu]>size[ulpv]){
            size[ulpu]+=size[ulpv];
            parent[ulpv]=ulpu;
        }
        else{
            size[ulpv]+size[ulpu];
            parent[ulpu]=ulpv;
        }
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin >> n >> m;
    DSU dsu(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        dsu.unionBySize(a,b);
    }
    vector<pair<int,int>> ans;
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        int ulpa=dsu.find(i-1);
        int ulpb=dsu.find(i);
        if(ulpa==ulpb){
            continue;
        }
        cnt++;
        ans.push_back({ulpa,ulpb});
        dsu.unionBySize(ulpa,ulpb);

    }
    cout << cnt << endl;
    for(auto val:ans)
    {
        cout << val.first << " " << val.second << endl;
    }
    cout << endl;


    return 0;
}