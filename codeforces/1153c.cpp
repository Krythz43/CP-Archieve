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
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2)
    {
        cout<<":("<<endl;
        return 0;
    }

    vi a(n);
    int q=0,o=0,c=0,lo,lc;
    lo=lc=n/2;
    rep(i,n,0)
    {
        if(s[i]==')')
        c++;
        else if(s[i]=='(')
        o++;
    }
    lo-=o;
    lc-=c;
    rep(i,n,0)
    {
        if(s[i]==')')
        a[i]=-1;
        else if(s[i]=='(')
        a[i]=1;
        else{
            if(lo)
            {a[i]=1;lo--;}
            else
            a[i]=-1;
        }
    }
    int f=1,co=0;
    rep(i,n,0)
    {
        co+=a[i];
        if(co<0 || (co==0 && i!=n-1))
        {
            f=0;
            break;
        }
    }
    if(!co && f)
    {
        rep(i,n,0)
        if(a[i]==1)
        cout<<'(';
        else
        cout<<')';
    }
    else cout<<":(";
    nl;
}
