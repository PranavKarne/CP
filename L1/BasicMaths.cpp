/*
Modular Arithmetic

M = 1e9 + 7

--> Significance of 1e9 + 7 =  very close to int max value , in Multiplicative inverse cannot be calculated for all numbers , 1e9 + 7 is prime number actually so  multiplicative inverse can be calculated easily.

--> In A % M , the result of this operation is always lesser than M 





*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <tuple>
#include <bitset>
#include <numeric>
using namespace std;
using namespace chrono;

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = double;

// Constants
constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244353;

// Macros
#define F first
#define S second
#define fr(i,n) for (ll i=0;i<n;i++)
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define pb push_back
#define MP make_pair
#define endl '\n'

// Modular Operations
ll inv(ll i) { return (i == 1) ? 1 : (MOD - (MOD / i) * inv(MOD % i) % MOD) % MOD; }
ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll ceil_div(ll a, ll b) { return (a % b == 0) ? a / b : a / b + 1; }

ll pwr(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

vector<ll> sieve(int n) {
    vector<ll> primes;
    vector<int> arr(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {
            primes.pb(i);
            for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
        }
    }
    return primes;
}

// Overloading Input/Output for Vectors
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) cin >> it;
    return istream;
}

template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c) cout << it << " ";
    return ostream;
}

// Mathematical Functions
int GCD(int a, int b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

ll LCM(ll a, ll b) {
    return (a * b) / GCD(a, b);
}

// Power and Modular Inverse
ll modpow(ll x, ll n, int m = MOD) {
    if (x == 0 && n == 0) return 0;
    ll res = 1;
    while (n > 0) {
        if (n % 2) res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int modinv(int x, int m = MOD) {
    return modpow(x, m - 2, m);
}

// Random Number Generation (Fix for macOS)
random_device rd;
mt19937 rng(rd());

int getRandomNumber(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

// Binary and Decimal Conversions
ll binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(ll a) { return bitset<64>(a).to_string(); }

// Custom Comparison Class
class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        int diff = a.second - a.first;
        int diff2 = b.second - b.first;
        if (diff == diff2) return a.first > b.first;
        return diff < diff2;
    }
};

// Binary Exponentiation
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Combination (nCr) Calculation
ll nCr(ll n, ll r, vector<ll>& f) {
    if (n < r) return 0;
    ll ans = f[n];
    ans = mod_mul(ans, inv(f[n - r]));
    return ans;
}

// Square Root Calculation using Binary Search
ll mysqrt(ll n) {
    ll ans = 0, low = 1, high = 1e9;
    while (low <= high) {
        ll md = (low + high) / 2;
        if (md * md <= n) {
            ans = md;
            low = md + 1;
        } else {
            high = md - 1;
        }
    }
    return ans;
}

// Custom Comparison Function for Sorting
bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
    return a.second < b.second;
}

void solve() {
    ll n;
    cin >> n;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

