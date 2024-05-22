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

const int N = 1e3 + 2, MOD = 1e9 + 7;

int solve(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % MOD;
    }

    int k = (solve(a, b / 2)) % MOD;

    if (b & 1)
    {
        return (a * ((k * k) % MOD)) % MOD;
    }
    else
    {
        return (k * k) % MOD;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        cout << solve(a, b) << "\n";
    }

    return 0;
}