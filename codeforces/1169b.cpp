#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
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



int main()
{
    fastio;
    int n,m,x,y;
    cin>>n>>m;
    vector<ipair> a;
    rep(i,m,0)
    {
        cin>>x>>y;
        a.pb(mp(x,y));
    }
    vi prob;
    prob.pb(a[0].ff);
    prob.pb(a[0].ss);
    rep(i,m,0)
    {
        if(a[i].ff==prob[0] || a[i].ff==prob[1] || a[i].ss==prob[0] || a[i].ss==prob[1])
        {

        }
        else
        {
            prob.pb(a[i].ff);
            prob.pb(a[i].ss);
            break;
        }
    }
    int f=0;
    rep(i,4,0)
    {
        rep(j,4,i+1)
        {
            int c=1;
            rep(k,m,0)
            if(a[k].ff==prob[i] || a[k].ff==prob[j] || a[k].ss==prob[i] || a[k].ss==prob[j])
            {

            }
            else
            {
                c=0;
                break;
            }
            if(c)
            {
                f=1;
                break;
            }
        }
        if(f)
        break;
    }

    if(f)
    cout<<"YES";
    else
    cout<<"NO";
    nl;
            else
        {
            sr=a[i]+x-m;
            if(sr<mine)
            mine=a[i];
        }
}
