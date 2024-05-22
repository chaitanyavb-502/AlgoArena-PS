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

int solve2(int a, int b, int mod)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % mod;
    }

    int k = (solve2(a, b / 2, mod));
    // if(k >= MOD) cnt += k/MOD;

    k %= mod;

    // cout << k << "\n";

    if (b & 1)
    {
        // if(k*k >= MOD) cnt += (k*k)/MOD;
        // if(a*((k*k)%MOD)  >= MOD) cnt += (a*((k*k)%MOD)) / MOD;
        return (a * ((k * k) % mod)) % mod;
    }
    else
    {
        // if(k*k >= MOD) cnt += (k*k)/MOD;
        return (k * k) % mod;
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
        // cnt = 0;
        int a, b, c;
        cin >> a >> b >> c;

        int k = solve2(b, c, MOD - 1);
        cout << solve2(a, k, MOD) << "\n";
    }

    return 0;
}