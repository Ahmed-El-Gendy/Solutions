// Problem: H. Hot Cappuccino
// Contest: Codeforces - Game of Coders 3.0
// URL: https://codeforces.com/gym/105262/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//================================ بسم الله الرحمن الرحيم ==================================//
#include <bits/stdc++.h>
#include<unordered_map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
//==================================================================//bits//==========================================================
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("aes,pclmul,rdrnd")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast,inline")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("popcnt")
#pragma GCC target("movbe")
#pragma GCC optimize("O3")

#undef _GLIBCXX_DEBUG
//==================================================================//ordered_set//=====================================================
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

//==================================================================//
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j]; j++);
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cins(arr,n) for(long     long i=0; i<n; i++){cin>>arr[i];} sort(all(arr));
#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";
#define cout(arr,n) for(long long i=0; i<n; i++){cout<<arr[i]<<" ";}
#define remove2(v)v.erase(unique(v.begin(), v.end()), v.end());
#define cin(arr,n) for(long long i=0; i<n; i++){cin>>arr[i];}
#define tt int tc; cin>>tc; for(int klm=1; klm<=tc; klm++)
#define ceill(n,m) (((n)/(m))+((n)%(m)?1:0))
#define FOR(a,b,c) for(ll a=b ; a<c; a++)
#define allr(x) (x).rbegin(),(x).rend()
#define all(x) (x).begin(), (x).end()
#define fx(n) fixed<<setprecision(n)
#define mine(v) min_element(all(v))
#define maxe(v) max_element(all(v))
#define OO 0x3f3f3f3f3f3f3f3fLL
#define sz(x) int(x.size())
#define prq priority_queue
#define vll vector<ll>v(n)
#define itt :: iterator
#define MOD 1000000007
#define pb push_back
#define con continue
#define sqrt sqrtl
#define se second
#define fi first
#define el "\n"
//==================================================================//
#define AHMEDHESHAM ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//==================================================================//
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//==================================================================//
ll  GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a % b); }
ll  LCM(ll a, ll b) { return (a / GCD(a, b)) * b; }
//==================================================================//
ll sub( ll a , ll b , int m = 0 ){return ( ( 0LL + a - b ) % m + m ) % m; }
//==================================================================//
ll fPow(ll base, ll exp,ll mod)
{
    ll res = 1;
    while(exp>0){
        if(exp % 2 == 1) res = (res%mod * base%mod) % mod;
        base = (base%mod * base%mod) % mod;
        exp /= 2;
    }
    return res%mod;
}
//==================================================================//
/*__int128 read() {__int128 x = 0, f = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') f = -1;ch = getchar();}while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
void print(__int128 x) {if (x < 0) {putchar('-');x = -x;}if (x > 9) print(x / 10); putchar(x % 10 + '0');}
//==================================================================//*/
ll sum_square(ll n)//????? ?????? ??????? ?? 1 ? n
{
    return n*(n-1)*(2*n-1)/6;
}
ll sum(ll n)
{
    return n*(n+1)/2;
}
//==================================================================//
const int dx[] = { 0, 1, 0, -1};
const int dy[] = { 1, 0, -1, 0};
bool valid(int x, int y,int n,int m) {return (x >= 0 && y >= 0 && x < n&& y <m);}
//==================================================================//
string YS="YES\n",Ys="Yes\n", ys="yes\n",NO="NO\n",no="no\n",No="No\n";
int const N =2e5 + 10;
const long long mod = 1e9 + 7;
const int oo = 0x3f3f3f3f;
const ld pi=acos(-1);
class Dijkstra
{
public:
	ll size=0,st=0,n2,m2;
	prq<pair<ll,pair<ll,ll>>> pq,pq2;
	vector<vector<ll>> v,d,d2;
	Dijkstra(ll n,ll m)
	{
		n2=n; m2=m; 
		v.resize(n,vector<ll>(m));
		d.resize(n,vector<ll>(m));
		d2.resize(n,vector<ll>(m));
		FOR(i,0,n) FOR(j,0,m) d[i][j]=1e18,d2[i][j]=1e18;
	}
	void dijkstra()
	{
		pq.push({0,{0,0}});
		d[0][0]=0;
		while(!pq.empty())
		{
			ll cost=-pq.top().fi;
			ll x=pq.top().se.fi,y=pq.top().se.se; pq.pop();
			if(cost>d[x][y])con;
			FOR(i,0,4)
			{
				ll x2=dx[i]+x,y2=dy[i]+y;
				if(valid(x2,y2,n2,m2))
				{
					ll newcost=d[x][y]+1;
					if(v[x][y]==2||v[x][y]==3)newcost--;
					
					if(d[x2][y2]>newcost)
					d[x2][y2]=newcost,
					pq.push({-newcost,{x2,y2}});
				}
			}
		}
	}
	
	void dijkstra2()
	{
		pq2.push({0,{n2-1,m2-1}});
		d2[n2-1][m2-1]=0;
		while(!pq2.empty())
		{
			ll cost=-pq2.top().fi;
			ll x=pq2.top().se.fi,y=pq2.top().se.se; pq2.pop();
			if(cost>d2[x][y])con;
			FOR(i,0,4)
			{
				ll x2=dx[i]+x,y2=dy[i]+y;
				if(valid(x2,y2,n2,m2))
				{
					ll newcost=d2[x][y]+1;
					if(v[x][y]==1||v[x][y]==3)newcost--;
					
					if(d2[x2][y2]>newcost)
					d2[x2][y2]=newcost,
					pq2.push({-newcost,{x2,y2}});
				}
			}
		}
	}
};
void ITcharDo()
{
     ll n,m,minn=1e18; cin>>n>>m;
     Dijkstra dij(n,m); cin_2d(dij.v,n,m); 
	 dij.dijkstra(); dij.dijkstra2();
	 FOR(i,0,n)
	 	FOR(j,0,m)	
	 		minn=min(minn,dij.d[i][j]+dij.d2[i][j]);
	 		
	 cout<<minn<<el;
}
int main()
{
    AHMEDHESHAM;
#ifdef ITCH
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    tt
    ITcharDo();
}
