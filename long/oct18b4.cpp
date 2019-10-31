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


lli dsum(lli x)
{
    lli ans=0;
    while(x)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        lli n,d;
        cin>>n>>d;
        vector <pair<pair<lli,lli>,lli> > a(100000);
        a[0].ff.ff=n;
        a[0].ff.ss=n%9;


        lli hash[10];
        rep(i,10,0)
        hash[i]=inf;



        lli z=0;
        lli z1=n;

        while(z1/10)
        {
            z++;
            z1=dsum(z1);
        }
        a[0].ss=z;


        if(a[0].ff.ss)
        hash[a[0].ff.ss]=min(0+a[0].ss,hash[a[0].ff.ss]);
        else
        hash[9]=min(0+a[0].ss,hash[9]);


        rep(i,100000,1)
        {
            a[i].ff.ff=a[i-1].ff.ff+d;
            a[i].ff.ss=a[i].ff.ff%9;
            z=0;
            z1=a[i].ff.ff;
            while(z1/10)
            {
                z++;
                z1=dsum(z1);
            }
            a[i].ss=z;

            if(a[i].ff.ss)
            hash[a[i].ff.ss]=min(i+a[i].ss,hash[a[i].ff.ss]);
            else
            hash[9]=min(i+a[i].ss,hash[9]);

            // cout<<a[i].ff.ff<<" "<<a[i].ff.ss<<" "<<a[i].ss<<endl;
        }

        rep(i,10,1)
        {
            if(hash[i]!=inf)
            {
                cout<<i<<" "<<hash[i]<<endl;
                break;
            }
        }
    }
}