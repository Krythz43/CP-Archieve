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

bool comp(pair<int,pair<string,char>> a, pair<int,pair<string,char>> b)
{
    return a.ss.ff.length()<b.ss.ff.length();
}

int main()
{
    fastio;
    int n;
    cin>>n;
    vector<pair<int,pair<string,char> > > a;
    string s;
    rep(i,2*n-2,0)
    {
        cin>>s;
        a.pb(mp(i,mp(s,'0')));
    }

    sort(a.begin(),a.end(),comp);

    // rep(i,2*n-2,0)
    // cout<<a[i].ss.ff<<endl;

    if((a[0].ss.ff+a[a.size()-1].ss.ff).compare(a[a.size()-2].ss.ff+a[1].ss.ff)==0)
    {   //P+S                           //
        s=a[0].ss.ff+a[a.size()-1].ss.ff;
    }
    else if((a[1].ss.ff+a[a.size()-1].ss.ff).compare(a[a.size()-2].ss.ff+a[0].ss.ff)==0)
    {
        s=a[1].ss.ff+a[a.size()-1].ss.ff;
    }
    else if((a[0].ss.ff+a[a.size()-2].ss.ff).compare(a[a.size()-1].ss.ff+a[1].ss.ff)==0)
    {
        s=a[0].ss.ff+a[a.size()-2].ss.ff;
    }
    else
    {
        s=a[1].ss.ff+a[a.size()-2].ss.ff;
    }

    for(int i=0;i<2*n-2;i+=2)
    {
        int l=a[i].ss.ff.length();
        string z=a[i].ss.ff;
        int c=0,f1=0,f2=0;
        rep(j,l,0)
        {
            if(z[j]!=s[j])
            break;
            else
            c++;
        }
        if(c==l)
        f1=1;
        c=0;

        z=a[i+1].ss.ff;
        for(int j=0;j<l;j++)
        {
            if(z[l-1-j]!=s[s.length()-1-j])
            break;
            else
            c++;
        }

        if(c==l)
        f2=1;

        if(f1 && f2)
        {
            a[i].ss.ss='P';
            a[i+1].ss.ss='S';
        }
        else
        {
            a[i].ss.ss='S';
            a[i+1].ss.ss='P';
        }
    }
    SO(a);
    rep(i,2*n-2,0)
    cout<<a[i].ss.ss;
    nl;
}