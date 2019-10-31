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

lli mod=1e9+7;

// lli multi(lli x,lli y)
// {
//     x%=mod;
//     if(y==0) return 1;
//     if(y==1) return x;
//     if(y%2) return (x*(multi((x*x)%mod)%mod,y/2))%mod;
//     else return multi((x*x)%mod,y/2)%mod;
// }


int main()
{
    fastio;
    string s;
    cin>>s;
    vi a;
    int k=-1;
    int n=s.length();
    rep(i,n,0)
    {
        if(s[i]=='a')
        {
            a.pb(1);
            k=i;
            break;
        }
        else if(s[i]=='b')
        {
            a.pb(0);
            k=i;
            break;
        }
    }


    if(k==-1)
    cout<<0<<endl;
    else
    {
        rep(i,s.length(),k+1)
        {
            if(s[i]=='a')
            a.pb(1);
            if(s[i]=='b')
            {
                if(a[a.size()-1]!=0)
                a.pb(0);
            }
        }

        lli ca=0;
        vlli vans;
        rep(i,n,0)
        {
            if(a[i]==1)
            ca++;
            else
            {
                if(ca)
                {
                    vans.pb(ca+1);
                    ca=0;
                }
            }
        }

        if(ca)
        vans.pb(ca+1);

        lli pro=1;

        if(vans.size()==0)
        cout<<0<<endl;
        else
        {
            lli pro=1;
            rep(i,vans.size(),0)
            {
                pro=(vans[i]*pro)%mod;
            }
            pro--;
            cout<<pro<<endl;
        }
    }
}