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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vlli a(n);
        ainput(a,n);
        SO(a);
        lli ans=a[0]*a[n-1];
        vlli list;
        for(int i=2;i<=sqrt(ans);i++)
        {
            if(ans%i==0)
            {
                if(ans/i==i)
                list.pb(i);
                else
                {
                    list.pb(i);
                    list.pb(ans/i);
                }
            }
        }

        if(list.size()!=a.size())
        cout<<-1<<endl;
        else
        {
            SO(list);
            int f=1;
            rep(i,list.size(),0)
            f&=(list[i]==a[i]);
            if(f)
            cout<<ans<<endl;
            else
            cout<<-1<<endl;
        }
    }
}