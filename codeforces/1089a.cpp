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
        int n;
        cin>>n;
        vi a(7);
        rep(i,7,0)
        cin>>a[i];
        int ans=0;

        lli sum=accumulate(a.begin(),a.end(),0);
        if(n%sum)
        {
            ans+=(7*(n/sum));
            n%=sum;
        }
        else
        {
            ans+=(7*(n/sum-1));
            n%=sum; 
            n+=sum;
        }

        int f;
            rep(i,7,0)
            {
                if(a[i])
                {
                    f=i;
                    break;
                }
            }

            while(n)
            {
                if(a[f]==1)
                n--;

                f=(f+1)%7;
                ans++;
            }

            cout<<ans<<endl;
    }

}