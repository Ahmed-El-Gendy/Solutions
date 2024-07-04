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


void req(vi &Y, string &s, ll at) {
    if (at >= s.size()) return;

    ll summ = 0;
    for (int i = 'a'; i <= 'z'; i++)
        summ += (Y[i] > 0);
    
    if (s[at] - 'a' + 1 > summ) {
        Y[s[at]]--;
        req(Y, s, at + 1);
        return;
    }
    
    if (s[at] - 'a' + 1 == summ && at + 1 != s.size() && s[at + 1] - 'a' + 1 >= summ) {
       Y[s[at]]--;
        req(Y, s, at + 1);
        return;
    }

    ll re = 0;
    vi Z(26);

    for (int i = at; i < s.size() && re != summ; i++)
    {
        re += (Z[s[i] - 'a'] == 0);
        Y[s[i]]--;
        Z[s[i] - 'a']++;
        s[i] = 'a' + summ - 1;
        at++;
    }
    
    while (at < s.size() && s[at] - 'a' + 1 <= summ)
    {
        Y[s[at]]--;
        s[at] = 'a' + summ - 1;
        at++;
    }
    
    req(Y, s, at);
}

void solve(int tc) {
    string s;

    cin >> s;

    vi Y(255);
    for (auto c : s) Y[c]++;
    req(Y, s, 0);
    cout << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}