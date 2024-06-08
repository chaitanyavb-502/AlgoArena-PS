#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define lld long double
#define pb push_back
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

const int N = 1e3 , MOD = 1e9 + 7;

void solve()
{
	int n , k;
	cin >> n >> k;

	vector<vector<int>> pref(N + 1, vector<int> ( N + 1, 0));

	while (n--)
	{
		int a , b , c , d;
		cin >> a >> b >> c >> d;

		pref[a][b]++;
		pref[a][d]--;
		pref[c][b]--;
		pref[c][d]++;
	}

	int ans = 0;
	rep(i , 0 , N + 1)
	{
		rep(j , 0 , N + 1)
		{
			if (i) pref[i][j] += pref[i - 1][j];
			if (j) pref[i][j] += pref[i][j  - 1];
			if (i && j) pref[i][j] -= pref[i - 1][j - 1];

			ans += (pref[i][j] == k);
		}
	}
	// debug(pref)
	cout << ans << "\n";
}

signed main()
{
	auto begin = std::chrono::high_resolution_clock::now();
#ifndef ONLINE_JUDGE
	freopen("paintbarn.in" , "r" , stdin);
	freopen("paintbarn.out" , "w" , stdout);
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