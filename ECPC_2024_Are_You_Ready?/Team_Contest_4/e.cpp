#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 998244353;

using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}


vector<mi> Z;
ll req(vi &X, ll at, ll g) {
    if (at == X.size()) return (0);
    if (Z[at].count(g)) return Z[at][g];
    g = gcd(g, X[at]);
    return (Z[at][g] = g + req(X, at + 1, g));
}

void solve(int tc) {
    ll n;

    cin >> n;
    vi X(n);
    Z.resize(n + 1);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    ll summ = X[1];
    ll g = X[1];
    for (int i = 2; i < n; i++)
    {
        g = gcd(g, X[i]);
        summ += g;
    }

    ll mx = summ;
    g = summ = X[0];

    for (int i = 1; i < n; i++)
    {
        ll re = req(X, i + 1, g);
        mx = max(mx, re + summ);
        g = gcd(g, X[i]);
        summ += g;
    }

    cout << mx << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}