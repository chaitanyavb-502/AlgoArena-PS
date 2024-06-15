// Runtime

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

const int N = 1e3 + 2 , MOD = 1e9 + 7;
int n;

bool help(string x , string y)
{
	debug(x)
	debug(y)
	cerr << endl;
	vector<int> cntx(3 , 0) , cnty(3 , 0);
	rep(i , 0 , n)
	{
		if (y[i] == 'C' and x[i] != 'C')
		{
			return false;
		}
		cntx[x[i] - 'A']++;
		cnty[y[i] - 'A']++;
	}
	int diffa = cnty[0] - cntx[0];
	int diffb = cnty[1] - cntx[1];
	rep(i , 0 , n)
	{
		if (x[i] == 'C')
		{
			if (diffa > 0)
			{
				x[i] = 'A';
				diffa--;
			} else if (diffb > 0) {
				x[i] = 'B';
				diffb--;
			}
		}
	}
	if (diffa > 0 || diffb > 0)
	{
		return false;
	}
	vector<int> ax , ay;
	rep(i , 0 , n)
	{
		if (x[i] == 'A')
		{
			ax.pb(i);
		}
		if (y[i] == 'A')
		{
			ay.pb(i);
		}
	}
	rep(i , 0 , ax.size())
	{
		if (ax[i] > ay[i])
		{
			return false;
		}
	}
	return true;
}

void solve()
{
	string x , y;
	cin >> n >> x >> y;

	string currx , curry;

	rep(i , 0 , n)
	{
		if (x[i] == 'C' and y[i] == 'C')
		{
			if (!currx.empty())
			{
				if (!help(currx , curry))
				{
					cout << "No\n";
					return;
				}
			}
			currx.clear();
			curry.clear();
		}
		currx.pb(x[i]);
		curry.pb(y[i]);
	}
	if (!currx.empty())
	{
		if (!help(currx , curry))
		{
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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
	cin >> tt;
	// tt = 1;
	while (tt--)
	{
		solve();
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cerr << "\nTime measured: " << elapsed.count() * 1e-9 << " seconds.\n";
	return 0;
}