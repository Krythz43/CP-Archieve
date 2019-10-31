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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}


bool comp(pair<ipair,int> a,pair<ipair,int> b)
{
    return a.ss<b.ss;
}


int main()
{
    fastio;
    int n;
    cin>>n;
    vector<pair<ipair,int> > a(n);

    rep(i,n,0)
    cin>>a[i].ff.ff,a[i].ss=i;

    SO(a);

    int g=0;

    for(int i=0;i<n;)
    {
        int x=(n-a[i].ff.ff)-1;
        int j=i+1;
        a[i].ff.ss=g;
        while(x--)
        {
            if(j>=n || a[i].ff.ff!=a[j].ff.ff)
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
            else
            {
                a[j].ff.ss=g;
                j++;
            }
        }
        i=j;
        g++;
    }

    sort(a.begin(),a.end(),comp);
    cout<<"Possible"<<endl;
    rep(i,n,0)
    cout<<a[i].ff.ss+1<<" ";
    nl;

    
}