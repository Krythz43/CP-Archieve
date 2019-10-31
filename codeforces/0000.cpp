#include <bits/stdc++.h>
using namespace std;
 
#define IOS                               \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0)
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 300009
#define M 509
#define mod 998244353
#define debug cout << "There There\n";
#define debug1(x) cout << "\nValue is " << x << endl
#define debug2(x, y) cout << "\nValue is " << x << " " << y << endl
#define debug3(x, y, z) cout << "\nValue is " << x << " " << y << " " << z << endl
#define pq priority_queue<int>
#define mpq priority_queue<int, vector<int>, greater<int>>
#define pr pair<int, int>
#define mx INT_MAX
#define lmx LLONG_MAX
#define err return 0
#define all(a) a.begin(), a.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n;
pr p[N];
map<int, int> fir;
map<int, int> sec;
int fac[N];
map<pr, int> par;
 
void init()
{
        fac[0] = 1;
        for (int i = 1; i < N; i++)
        {
                fac[i] = fac[i - 1] * (i);
                fac[i] %= mod;
        }
}
 
int32_t main()
{
        IOS;
 
        init();
 
        cin >> n;
 
        for (int i = 0; i < n; i++)
        {
                cin >> p[i].first >> p[i].second;
                fir[p[i].first]++;
                sec[p[i].second]++;
                par[p[i]]++;
        }
 
        int ans = 1;
        int ans2 = 1;
 
        for (auto i : fir)
        {
                ans *= fac[i.second];
                ans %= mod;
        }
 
        for (auto i : sec)
        {
                ans2 *= fac[i.second];
                ans2 %= mod;
        }

        cout<<ans<<" "<<ans2<<endl;
 
        ans += ans2;
        ans %= mod;
 
        sort(p, p + n);
 
        bool is = 1;
 
        for (int i = 1; i < n; i++)
        {
                if (p[i].first < p[i - 1].first || p[i].second < p[i - 1].second)
                        is = 0;
        }
 
        ans2 = 1;
 
        for (auto i : par)
        {
                ans2 *= fac[i.second];
                ans2 %= mod;
        }
        cout<<ans<<' '<<ans2<<endl;
 
        if (is)
        {
                ans -= ans2;
                ans %= mod;
        }
 
        ans = fac[n] - ans;
        ans += mod;
        ans %= mod;
 
        cout << ans << endl;
 
        return 0;
}