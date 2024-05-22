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

    int n, m;
    cin >> n >> m;

    int temp;
    multiset<int> ms;

    while (n--)
    {
        cin >> temp;
        ms.insert(-temp);
    }

    while (m--)
    {
        int t;
        cin >> t;

        if ((ms.lower_bound(-t)) == ms.end())
        {
            cout << "-1\n";
        }
        else
        {
            cout << -*(ms.lower_bound(-t)) << endl;
            ms.erase(ms.lower_bound(-t));
        }
    }

    return 0;
}