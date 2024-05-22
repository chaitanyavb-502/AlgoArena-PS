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

    vi dp(N, 0);
    rep(i, 1, N)
    {
        for (int j = i; j < N; j += i)
        {
            dp[j]++;
        }
    }

    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        cout << dp[x] << endl;
    }

    return 0;
}