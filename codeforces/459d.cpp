#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'


const int MAXN = 1000 * 1000 + 10;

int fen[MAXN];

void add(int x, int val)
{
    for (int i = x + 1; i < MAXN; i += i & (-i)) fen[i] += val;
}

int get(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= i & (-i)) ans += fen[i];
    return ans;
}

int sum(int x, int y)
{
    return get(y) - get(x);
}

int rem[MAXN], cnt[MAXN], a[MAXN], tot[MAXN], sz;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i], tot[sz++] = a[i];

    sort(tot, tot + sz);
    sz = unique(tot, tot + sz) - tot;

    for (int i = 0; i < n; i ++) a[i] = lower_bound(tot, tot + sz, a[i]) - tot;

    for (int i = n - 1; i >= 0; i --)
    {
        cnt[a[i]] ++;
        add(cnt[a[i]], 1);

        rem[i] = cnt[a[i]];
    }

    memset(cnt, 0, sizeof cnt);
    long long ans = 0;
    for (int i = 0; i < n; i ++)
    {
        add(rem[i], -1);
        
        cnt[a[i]] ++;
        ans += sum(1, cnt[a[i]]);
    }

    cout << ans << endl;
    return 0;
}