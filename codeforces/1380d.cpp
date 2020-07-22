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
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

lli n,m,x,y,k;
vlli a,b;

int main()
{
    fastio;
    cin>>n>>m;
    a.resize(n);
    b.resize(m);
    cin>>x>>k>>y;

    rep(i,n,0)cin>>a[i];
    rep(i,m,0)cin>>b[i];

    // Check if the relative ordering is same.

    int p1 = 0,p2 = 0;

    while(p1 < n && p2 < m){
        if(a[p1] == b[p2]){
            p1++;
            p2++;
        }
        else{
            p1++;
        }
    }

    if(p2 != m){
        cout<<-1<<endl;
        return 0;
    }

    // Array if it is possible to berserk or Fireball

    vector<bool> present(n + 1,0),canb(n,0);
    rep(i,m,0)present[b[i]]++;

    rep(i,n,0){
        if(present[a[i]])continue;
        if(i && a[i -1] > a[i])canb[i] = true;
        if(i < n && a[i+1] > a[i])canb[i] = true;
    }

    vector<bool> canf(n,0);

    int curr = 0;
    rep(i,n,0){
        if(present[i]){
            curr = 0;
            if(curr >= k){
                rep(j,i,i - k)canf[j] = true;
            }
            continue;
        }
        curr++;
    }

    if(curr >= k){
        rep(j,n,n - k)canf[j] = true;
    }

    rep(i,n,0){
        if((!present[i]) && !(canb[i] or canf[i])) return cout<<-1<<endl,0;
    }

    lli ans = 0;
    lli comp = 0;
    rep(i,n,0)if(canb[i] && (!canf[i])){
        comp++;
        ans += y;
    }


}