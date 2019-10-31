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
lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int main()
{
    fastio;
    int l;
    string s;
    cin>>s;
    l=s.length();
    int n=0;
    vector<pair<char,int> > a;
    n++;
    a.pb(mp(s[0],1));
    rep(i,l,1)
    {
        if(s[i]==s[i-1])
        a[n-1].ss++;
        else
        {
            n++;
            a.pb(mp(s[i],1));
        }
    }

    // rep(i,n,0)
    // cout<<"'"<<a[i].ff<<","<<a[i].ss<<"'"<<endl;

    if(a[0].ss>1)
    a[0].ss=2;
    rep(i,n,1)
    {
        if(a[i-1].ss==1)
        {
            if(a[i].ss>=2)
            a[i].ss=2;
        }
        else if(a[i-1].ss==2)
        {
            a[i].ss=1;
        }
        else
        a[i].ss=2;
    }

    // rep(i,n,0)
    // cout<<"'"<<a[i].ff<<","<<a[i].ss<<"'"<<endl;

    rep(i,n,0)
    {
        if(a[i].ss==2)
        cout<<a[i].ff<<a[i].ff;
        else
        cout<<a[i].ff;
    }
}