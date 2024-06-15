#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define pb(x) push_back(x)
#define si set<int>
#define msi multiset<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int , int>>
#define pii pair<int , int>
#define vc vector<char>
#define rep(i , a , b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define all(x) ((x).begin() , (x).end())
#define input(x) for(auto &i : x)cin >> i
 
const int N = 1e3 + 2 , MOD = 1e9 + 7;

 
void solve()
{
	int a , b;
	cin >> a >> b;
 
	vvi dp(501 , vi(501));
	rep(i , 1, a + 1)
	{
		rep(j , 1 , b + 1)
		{
			if (i ^ j)
				dp[i][j] = MOD;
			rep(k , 1 , i)
			{
				dp[i][j] = min(dp[i][j] , dp[k][j] + dp[i - k][j] + 1);
			}
			rep(k , 1 , j)
			{
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[i][j - k] + 1);
			}
		}
	}
	cout << dp[a][b] << "\n";
}
 
 
 
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int t;
	// cin >> t;
	t = 1;
	while (t--)
	{
		solve();
	}
 
	return 0;
}