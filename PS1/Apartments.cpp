#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define pb push_back()
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
 
signed main()
{
  ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n , m , k;
    cin >> n >> m >> k;
 
    vi appl(n) , appart(m);
    input(appl);
    input(appart);
    sort all(appl);
    sort all(appart);
    int i1 = 0 , i2 = 0 , ans = 0;
 
    while(i1 < n && i2 < m)
    {
        if((abs(appl[i1] - appart[i2]))  <=  k)
        {
            ans++;
            i1++;
            i2++;
        }
        else if(appl[i1] < appart[i2])
        {
            i1++;
        }
        else
        {
            i2++;
        }
    }
 
    cout << ans << endl;
 
   return 0;
}