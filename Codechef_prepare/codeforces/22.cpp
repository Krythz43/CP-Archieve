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
#define llpair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

lli n,m;
vector <llpair> a;

int main()
{
    fastio;
    lli t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        lli x,y;
        vector <llpair> a(n);
        rep(i,n,0)
        {
            cin>>x>>y;
            a[i]=mp(x,y);
        }
        sort(a.begin(),a.end());
        while(m--)
        {
            lli p;
            cin>>p;
            lli lo=a[0].ff,hi=a[n-1].ss;

            if(p<=lo)
            {cout<<lo-p<<endl;continue;}
            if(p>=hi)
            {cout<<-1<<endl;continue;}

            lo=0;
            hi=n-1;
            lli mid;
            while(1)
            {
                mid=lo+hi;
                mid>>=1;
                if(a[lo].ff>=p && a[lo].ss<p)
                {cout<<0;break;}
                else if(a[hi].ff>=p && a[hi].ss<p)
                {cout<<0;break;}
                else
                {
                    if(a[lo].ss<p && a[lo+1].ff>p)
                    {cout<<a[lo+1].ff-p;break;}
                    else if(a[hi].ff>p && a[hi-1].ss<=p)
                    {cout<<a[hi].ff-p;break;}
                    else
                    {
                        if(p>=a[mid].ff && p<a[mid].ss)
                        {cout<<0;break;}
                        else
                        {
                            if(a[mid].ff>p)
                            hi=mid;
                            else
                            lo=mid;
                        }

                    }
                }
            }
            nl;
        }
    }
}