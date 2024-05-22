#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back()
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

    vii a(n);

    rep(i, 0, n)
    {
        cin >> a[i].ff;
        a[i].ss = i;
    }

    sort all(a);

    int i = 0, ans = 0;
    while (i < n - 1)
    {
        while ((i < n - 1) && (a[i + 1].ss > a[i].ss))
        {
            i++;
        }
        i++;
        ans++;
    }
    if ((n > 1) && (a[n - 1].ss < a[n - 2].ss))
        ans++;

    cout << ans << "\n";

    return 0;
}