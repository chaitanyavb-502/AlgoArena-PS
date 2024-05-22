#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb(x) push_back(x)
#define si set<int>
#define msi multiset<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define vc vector<char>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define all(x) ((x).begin(), (x).end())
#define input(x)      \
    for (auto &i : x) \
    cin >> i

const int N = 1e6 + 2, MOD = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi a(n), dp(N, 0);
    rep(i, 0, n)
    {
        cin >> a[i];
        dp[a[i]]++;
    }

    for (int i = N; i >= 1; i--)
    {
        int cnt = 0;
        for (int j = i; j <= N; j += i)
        {
            cnt += dp[j];
            if (cnt >= 2)
            {
                cout << i << "\n";
                return 0;
            }
        }
    }

    return 0;
}