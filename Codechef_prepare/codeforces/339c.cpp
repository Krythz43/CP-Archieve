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

int main()
{
    fastio;
    string s;
    cin>>s;
    vi a,ans;
    int f=1;

    rep(i,10,0)
    if(s[i]=='1')
    a.pb(i+1);

    int na=a.size(),w=0,lw,cw;
    if(na==0)
    {
        cout<<"NO";
        return 0;
    }
    w+=a[0];
    lw=0;
    ans.pb(w);
    int n;cin>>n;
    n--;
    while(n--)
    {
        cw=upper_bound(a.begin(),a.end(),w)-a.begin();
        if(cw==na)
        {
            f=0;
            break;
        }
        else if(cw==lw)
        {
            if(cw==na-1)
            {
                f=0;break;
            }
            else
            {
                lw=cw+1;
                cw++;
                ans.pb(a[lw]);
            }
        }
        else
        {
            lw=cw;
            ans.pb(a[cw]);
        }
        w=fabs(w-a[cw]);
        // cout<<w<<a[cw]<<" "<<endl;
    }

    if(f)
    {
        cout<<"YES"<<endl;
        rep(i,ans.size(),0)
        cout<<ans[i]<<" ";
    }
    else
    cout<<"NO";
}