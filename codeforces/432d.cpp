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
#define printarray(a) for(int i=0;i<a.size();i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    fastio;
    string s;
    cin>>s;
    int n;
    n = s.length();

    vi z = z_function(s);
    vi cnt(n+1,0);
    vi pos(n+1,0);
    pos[n]=1;
    cnt[n]=1;
    for(int i=1;i<n;i++)
        if(z[n-i]==i)   pos[i]=1;

    for(int i=0;i<n;i++)
        cnt[z[i]]++;

    // Anything Bigger has been through all the small

    for(int i=n-1;i>=1;i--)
        cnt[i]+=cnt[i+1];

    vector<ipair> res;
    for(int i=1;i<=n;i++)
        if(pos[i])
            res.pb(mp(i,cnt[i]));

    cout<<res.size()<<endl;
    rep(i,res.size(),0)cout<<res[i].ff<<" "<<res[i].ss<<endl;
}