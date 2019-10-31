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
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m,k;
        cin>>n>>m>>k;
        lli t;
        t=llmax(n,m);
        lli ans=0;
        if(n<m)
        swap(n,m);
        if(k<t)
        cout<<"-1";
        else
        {
            if((n-m)%2==0)
            {if(n>m)
            {
                k-=n-m;
                ans+=(n-m)+(n-m)%2;
            }
            else
            {
                k-=m-n;
                ans+=(m-n)+(m-n)%2;
            }
            k-=(llmin(m,n)-1);
            ans+=(llmin(m,n)-1);

            if(k%2)
            ans+=k;
            else
            ans+=k-2;
            cout<<ans;}
            else
            {
                ans+=(n-m)-1;
                k-=(ans);
                ans+=k-1;
                cout<<ans;
            }
        }
        nl;
    }
}