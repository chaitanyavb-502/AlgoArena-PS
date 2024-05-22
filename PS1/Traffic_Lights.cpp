#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
// #define push_back(x) push_back(x)
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

    int x, n;
    cin >> x >> n;

    vi p(n);
    input(p);

    // pii anspair = {0 , x};
    // int ans = x;

    multiset<pair<int, pii>> ms;
    set<int> s;
    ms.insert({x, {0, x}});
    s.insert(0);
    s.insert(x);

    rep(i, 0, n)
    {
        auto it = ms.end();
        it--;

        // cout << (*it).ff << " " << (*it).ss.ff << " " << (*it).ss.ss << endl;
        // cout << p[i] << endl;

        auto less = s.lower_bound(p[i]);
        less--;
        auto more = s.upper_bound(p[i]);

        ms.insert({p[i] - *less, {*less, p[i]}});
        ms.insert({*more - p[i], {p[i], *more}});

        ms.erase({*more - *less, {*less, *more}});

        s.insert(p[i]);

        it = ms.end();
        it--;

        cout << (*it).ff << " ";
    }

    return 0;
}