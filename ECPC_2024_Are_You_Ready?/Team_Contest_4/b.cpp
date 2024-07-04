#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll int
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

ll req(vii &Z, vii &Y, ll l, ll r) {
    vi X(26);
    vp M(26);
    for (int i = 0; i < 26; i++)
    {
        X[i] = Y[i][r] - Y[i][l - 1];
        if (!X[i]) continue;
        ll re = lower_bound(all(Z[i]), l) - Z[i].begin();
        M[i].first = Z[i][re];
        re = upper_bound(all(Z[i]), r) - Z[i].begin();
        M[i].second = Z[i][re - 1];
    }

    for (int i = 0; i < 26; i++)
    {
        if (!X[i]) continue;
        for (int j = 0; j < 26; j++)
        {
            if (!X[j] || i == j) continue;
            if (X[i] > X[j] && M[i].first < M[j].second) return (1);
        }
    }

    return (0);
}

void solve(int tc) {
    ll n, q;
    string s;

    cin >> n >> s;
    vii Y(26, vi(n + 1));
    vii Z(26);

    for (int i = 0; i < n; i++)
    {
        Y[s[i] - 'a'][i + 1] = 1;
        Z[s[i] - 'a'].push_back(i + 1);
        for (int j = 0; j < 26; j++)
            Y[j][i + 1] += Y[j][i];        
    }

    cin >> q;
    while (q--)
    {
        ll l, r; cin >> l >> r;
        if (req(Z, Y, l, r)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}