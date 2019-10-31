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
    vi a;
    int n=s.length();
    rep(i,n,0)
    {
        a.pb(s[i]-'0');
    }

    int ans1=inf,ans2=inf,ans3=inf,ans2i,ans3i;

    rep(i,n,0)
    {
        if(a[i]%8==0)
        {
            ans1=a[i];
            break;
        }
    }

    if(n>=2)
    {
        rep(i,n,0)
        rep(j,n,i+1)
        if((10*a[i]+a[j])%8==0)
        {
            ans2=n-2;
            ans2i=10*a[i]+a[j];
            break;
        }
    }

    int f=0;

    if(n>=3)
    {
        for(int i=n-3;i>=0;i--)
        {
            rep(j,n,i+1)
            {
                rep(k,n,j+1)
                {
                    ans3i=100*a[i]+10*a[j]+a[k];
                    if(ans3i%8==0)
                    {
                        ans3=i;
                        f=1;
                        break;
                    }
                }

                if(f)
                break;
            }
            if(f)
            break;
        }
    }

    if(ans1==inf && ans2==inf && ans3==inf)
    cout<<"NO"<<endl;
    else if(ans1!=inf)
    cout<<"YES\n"<<ans1<<endl;
    else if(ans2!=inf)
    cout<<"YES\n"<<ans2i<<endl;
    else{
        cout<<"YES"<<endl;
        rep(i,ans3,0)
        cout<<a[i];
        cout<<ans3i<<endl;
    }
}