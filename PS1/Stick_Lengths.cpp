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

    vector<int> p(n);
    int median = 0;

    rep(i, 0, n)
    {
        cin >> p[i];
        // avgsum += p[i];
    }
    sort all(p);
    median = p[(n - 1) / 2];
    // cout << avgsum << endl;

    int ans = 0;
    // sort(all)

    rep(i, 0, n)
    {
        ans += abs(p[i] - median);
    }

    cout << ans << endl;

    return 0;
}