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

    vi p(n);
    input(p);
    sort all(p);

    int ans = 0;

    int start = 0, end = n - 1;

    while (start <= end)
    {
        if ((start < end) && ((p[start] + p[end]) <= x))
        {
            ans++;
            start++;
            end--;
        }
        else if ((start < end) && ((p[start] + p[end]) > x))
        {
            ans++;
            end--;
        }
        else
        {
            ans++;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}