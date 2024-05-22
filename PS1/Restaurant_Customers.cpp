#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb(x) push_back(x)
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vii a(2 * n);
    rep(i, 0, 2 * n)
    {
        cin >> a[i].ff;
        if (i % 2 == 0)
        {
            a[i].ss = 1;
        }
        else
        {
            a[i].ss = -1;
        }
    }
    sort all(a);
    int ans = 0, temp = 0;
    rep(i, 0, 2 * n)
    {
        temp += a[i].ss;
        ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}