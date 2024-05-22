#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb(x) push_back(x)
#define si set<int>
#define msi multiset<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int , int>>
#define pii pair<int , int>
#define vc vector<char>
#define rep(i , a , b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define all(x) ((x).begin() , (x).end())
#define input(x) for(auto &i : x)cin >> i

const int N = 1e3 + 2 , MOD = 1e9 + 7;

int power(int a , int b)
{
    if(b == 0) return 1;
    if(b == 1) return a%MOD;

    int k = power(a , b/2);
    if(b&1)
    {
        return (a*((k*k)%MOD))%MOD;
    }
    return (k*k)%MOD;
}

void solve()
{
    int n;
    cin >> n;

    vii a(n);
    rep(i , 0 , n)
    {
        cin >> a[i].ff >> a[i].ss;
    }

    int ans1 = 1;
    rep(i , 0 , n)
    {
        ans1 *= (a[i].ss + 1);
        ans1 %= MOD;
    }
    cout << ans1 << " ";

    int ans2 = 1;
    rep(i , 0 , n)
    {
        int num = (power(a[i].ff , a[i].ss + 1 ) - 1 + MOD) % MOD;
        int den = power(a[i].ff - 1 , MOD - 2);
        int temp = num * den % MOD;
        ans2 = (ans2 * temp) % MOD;
    }
    cout << ans2 << " ";

    int ans3 = 1;
    int p = 1;

    rep(i , 0 , n)
    {
        int temp = power(a[i].ff , (a[i].ss * (a[i].ss + 1) / 2));
        ans3 = power(ans3 , a[i].ss + 1) * power(temp , p) % MOD;
        p = (p * (a[i].ss + 1)) % (MOD - 1);
    }
    cout << ans3 ;
}

signed main()
{
  ios::sync_with_stdio(false);
    cin.tie(nullptr);

   int t;
//    cin >> t;
    t = 1;
   while(t--)
   {
       solve();
   }

   return 0;
}