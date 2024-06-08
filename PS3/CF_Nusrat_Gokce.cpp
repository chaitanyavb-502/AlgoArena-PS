#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define lld long double
#define pb(x) push_back(x)
#define pii pair<int , int>
#define si set<int>
#define msi multiset<int>
#define rep(i , a , b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define all(x) ((x).begin() , (x).end())
#define input(x) for(auto &i : x)cin >> i

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " : "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int N = 1e3 + 2 , MOD = 1e9 + 7;

void solve()
{
	int n , m;
	cin >> n >> m;

	vector<pii> a(n);
	rep(i , 0  , n)
	{
		cin >> a[i].ff;
		a[i].ss = i;
	}
	vector<vector<int>> adj(n);
	if (n > 1)
	{
		adj[0].pb(1);
	}
	rep(i , 1 , n - 1)
	{
		adj[i].pb(i - 1);
		adj[i].pb(i + 1);
	}
	if (n > 1)
	{
		adj[n - 1].pb(n - 2);
	}
	priority_queue<pii , vector<pii> ,  greater<pii>> s;
	rep(i , 0 , n)
	{
		s.push(a[i]);
	}
	// map<pii , int> mp;
	while (!s.empty())
	{
		pii temp = s.top();
		debug(a);
		s.pop();
		for (auto j : adj[temp.ss])
		{
			if (a[j].ff < temp.ff - m)
			{
				// mp[ {a[j].ff , j}] = 1;
				// s.erase({a[j].ff , j});
				a[j].ff = temp.ff - m;
				s.push({a[j].ff , j});
			}
		}
	}
	rep(i , 0 , n)
	{
		cout << a[i].ff << " ";
	} cout << "\n";
}

signed main()
{
	auto begin = std::chrono::high_resolution_clock::now();
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	freopen("error.txt" , "w" , stderr);
#endif

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	// cin >> tt;
	tt = 1;
	while (tt--)
	{
		solve();
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cerr << "\nTime measured: " << elapsed.count() * 1e-9 << " seconds.\n";
	return 0;
}