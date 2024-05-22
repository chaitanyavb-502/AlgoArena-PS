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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<pii, int>> a(n);
    vii c(2 * n);
    rep(i, 0, n)
    {
        cin >> a[i].ff.ff >> a[i].ff.ss;
        a[i].ss = i;
        c[2 * i].ff = a[i].ff.ff;
        c[2 * i].ss = 1;
        c[2 * i + 1].ff = a[i].ff.ss;
        c[2 * i + 1].ss = -1;
    }

    sort(c.begin(), c.end(), [&](auto i, auto j)
         { if(i.ff == j.ff) return i.ss > j.ss;
    return i.ff < j.ff; });

    int k = 0, temp = 0;

    rep(i, 0, 2 * n)
    {

        temp += c[i].ss;
        k = max(k, temp);
    }

    cout << k << "\n";

    sort all(a);

    vi ans(n);

    multiset<pair<pii, int>> s;
    s.insert({{a[0].ff.ss, a[0].ff.ff}, 1});
    // cout << "1 " << a[0].ff.ff << " " <<a[0].ff.ss << " " << 1 << "\n";
    ans[a[0].ss] = 1;
    int end = 0, room = 1, p = 1;
    rep(i, 1, n)
    {
        if (a[i].ff.ff > (*(s.begin())).ff.ff)
        {
            ans[a[i].ss] = (*(s.begin())).ss;
            room = (*(s.begin())).ss;
            // int end = (*(s.begin())).ff.ss;
            s.erase(s.begin());
            s.insert({{a[i].ff.ss, a[i].ff.ff}, room});
            // cout << "1 " << a[i].ff.ff << " " <<a[i].ff.ss << " " << room << "\n";
        }
        else
        {
            // room = (*(s.begin())).ss;
            p++;
            s.insert({{a[i].ff.ss, a[i].ff.ff}, p});
            ans[a[i].ss] = p;
            // cout << "2 " << a[i].ff.ff << " " <<a[i].ff.ss << " " << p << "\n";
        }
    }
    rep(i, 0, n)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}