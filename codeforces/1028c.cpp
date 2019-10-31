#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define ll long long int
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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX


const ll INF = 2000000000;
const int MAX_N = 200000;
struct name
{
    ll x1, y1, x2, y2;
    int i;
};
name s[MAX_N];
bool f(const name &a, const name &b)
{
    if (a.x2 < b.x1 || b.x2 < a.x1)
        return 0;
    if (a.y2 < b.y1 || b.y2 < a.y1)
        return 0;
    return 1;
}
bool f1(const name &a, pair<ll, ll> b)
{
    if (b.first >= a.x1 && b.first <= a.x2 &&
        b.second >= a.y1 && b.second <= a.y2)
    {
        return true;
    }
    return false;
}
bool full(const name &a, const name &b)
{
    if (a.x1 >= b.x1 && a.x2 <= b.x2 &&
        a.y1 >= b.y1 && a.y2 <= b.y2)
    {
        return 1;
    }
    return 0;
}
name norm(const name &a)
{
    name ans = a;
    ans.x1 = min(a.x1, a.x2);
    ans.x2 = max(a.x1, a.x2);
    ans.y1 = min(a.y1, a.y2);
    ans.y2 = max(a.y1, a.y2);
    return ans;
}
name f2(name a, name b)
{
    pair<ll, ll> t1, t2;
    name ans;
    if (full(a, b))
    {
        return a;
    }
    if (full(b, a))
    {
        return b;
    }
    for (int i = 0; i < 2; i++)
    {
        if (a.x2 >= b.x1 && a.y1 >= b.y1 && a.y2 <= b.y2 && a.x2 <= b.x2)
        {
            ans = a;
            ans.x1 = b.x1;
            return ans;
        }
        if (a.y2 >= b.y1 && a.x1 >= b.x1 && a.x2 <= b.x2 && a.y2 <= b.y2)
        {
            ans = a;
            ans.y1 = b.y1;
            return ans;
        }
        if (a.x1 <= b.x2 && a.y1 >= b.y1 && a.y2 <= b.y2 && a.x1 >= b.x1)
        {
            ans = a;
            ans.x2 = b.x2;
            return ans;
        }
        if (a.y1 <= b.y2 && a.x1 >= b.x1 && a.x2 <= b.x2 && a.y1 >= b.y1)
        {
            ans = a;
            ans.y2 = b.y2;
            return ans;
        }
        swap(a, b);
    }
    if (f1(a, make_pair(b.x1, b.y1)))
    {
        t1 = make_pair(b.x1, b.y1);
    }
    else
    {
        if (f1(a, make_pair(b.x1, b.y2)))
        {
            t1 = make_pair(b.x1, b.y2);
        }
        else
        {
            if (f1(a, make_pair(b.x2, b.y2)))
            {
                t1 = make_pair(b.x2, b.y2);
            }
            else
            {
                if (f1(a, make_pair(b.x2, b.y1)))
                {
                    t1 = make_pair(b.x2, b.y1);
                }
                else
                {
                    t1 = make_pair(INF, INF);
                }
            }
        }
    }
    if (f1(b, make_pair(a.x1, a.y1)))
    {
        t2 = make_pair(a.x1, a.y1);
    }
    else
    {
        if (f1(b, make_pair(a.x1, a.y2)))
        {
            t2 = make_pair(a.x1, a.y2);
        }
        else
        {
            if (f1(b, make_pair(a.x2, a.y2)))
            {
                t2 = make_pair(a.x2, a.y2);
            }
            else
            {
                if (f1(b, make_pair(a.x2, a.y1)))
                {
                    t2 = make_pair(a.x2, a.y1);
                }
                else
                {
                    t2 = make_pair(INF, INF);
                }
            }
        }
    }
    if (t1.first == INF || t2.first == INF)
    {
        ans.x1 = max(a.x1, b.x1);
        ans.x2 = min(a.x2, b.x2);
        ans.y1 = max(a.y1, b.y1);
        ans.y2 = min(a.y2, b.y2);
        if (ans.y1 > ans.y2 || ans.x1 > ans.x2)
        {
            ans.x1 = ans.x2 = ans.y1 = ans.y2 = INF;
        }
        ans = norm(ans);
        return ans;
    }
    ans.x1 = t1.first;
    ans.y1 = t1.second;
    ans.x2 = t2.first;
    ans.y2 = t2.second;
    ans = norm(ans);
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int l, r, u, d;
    l = r = u = d = 0;
    for (int i = 0; i < n; i++)
    {
        s[i].i = i;
        cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
        s[i] = norm(s[i]);
        if (s[i].x1 > s[r].x1)
            r = i;
        if (s[i].x2 < s[l].x2)
            l = i;
        if (s[i].y1 > s[u].y1)
            u = i;
        if (s[i].y2 < s[d].y2)
            d = i;
    }
    name ans;
    int q;
    ans = s[l];
    q = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != l && i != r)
        {
            if (f(ans, s[i]))
            {
                ans = f2(ans, s[i]);
            }
            else
            {
                q = 0;
                break;
            }
        }
    }
    if (q && ans.x2 < INF && ans.y2 < INF)
    {
        cout << ans.x1 << " " << ans.y1;
        return 0;
    }
    ans = s[r];
    q = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != l && i != r)
        {
            if (f(ans, s[i]))
            {
                ans = f2(ans, s[i]);
            }
            else
            {
                q = 0;
                break;
            }
        }
    }
    if (q && ans.x2 < INF && ans.y2 < INF)
    {
        cout << ans.x1 << " " << ans.y1;
        return 0;
    }
    ans = s[u];
    q = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != u && i != d)
        {
            if (f(ans, s[i]))
            {
                ans = f2(ans, s[i]);
            }
            else
            {
                q = 0;
                break;
            }
        }
    }
    if (q && ans.x2 < INF && ans.y2 < INF)
    {
        cout << ans.x1 << " " << ans.y1;
        return 0;
    }
    ans = s[d];
    q = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != u && i != d)
        {
            if (f(ans, s[i]))
            {
                ans = f2(ans, s[i]);
            }
            else
            {
                q = 0;
                break;
            }
        }
    }
    if (q && ans.x2 < INF && ans.y2 < INF)
    {
        cout << ans.x1 << " " << ans.y1;
        return 0;
    }
    do
    {
        for (int i = 0; i < n; i++)
        {
            q = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (f(s[i], s[j]) == 0)
                {
                    q = 1;
                    l = i;
                    r = j;
                    break;
                }
            }
            if (q)
                break;
        }
        ans = s[l];
        q = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != l && i != r)
            {
                if (f(ans, s[i]))
                {
                    ans = f2(ans, s[i]);
                }
                else
                {
                    q = 0;
                    break;
                }
            }
        }
        if (q && ans.x2 < INF && ans.y2 < INF)
        {
            cout << ans.x1 << " " << ans.y1;
            return 0;
        }
    } while (1);
    return 0;
}