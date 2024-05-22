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

    int n, x;
    cin >> n >> x;

    vi a(n);
    input(a);

    // vi freq(MOD , 0);

    multiset<int> ms;
    set<int> s;

    rep(i, 0, n)
    {
        ms.insert(a[i]);
        // freq[a[i]]
    }

    int temp1 = -1, temp2;

    if ((x % 2 == 0) && (ms.count(x / 2) > 1))
    {
        int cnt = 0;
        rep(i, 0, n)
        {
            if ((a[i] == x / 2) && (cnt < 2))
            {
                cout << i + 1 << " ";
                cnt++;
            }
        }
        cout << endl;
        return 0;
    }

    rep(i, 0, n)
    {
        if ((ms.find(x - a[i]) != ms.end()) && (ms.find(x - a[i]) != ms.find(a[i])))
        {
            temp1 = i;
            break;
        }
    }

    if (temp1 == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    rep(i, temp1 + 1, n)
    {
        if (a[i] == (x - a[temp1]))
        {
            cout << temp1 + 1 << " " << i + 1 << endl;
            break;
        }
    }

    return 0;
}