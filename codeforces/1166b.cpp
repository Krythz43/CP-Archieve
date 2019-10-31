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
    int k;
    cin>>k;
    int n,m;
    int f=0;

    for(int i=2;i<=sqrt(k);i++)
    {
        if(k%i==0)
        {
            if(i>=5 && (k/i)>=5)
            {
                f=1;
                n=i;
                m=k/i;
                break;
            }
        }        
    }
    if(f==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    vector<char> a={'a','e','i','o','u'};
    int c1=0,c2=0;
    rep(i,n,0)
    {
        c2=c1;
        c1++;
        c1%=5;
        rep(i,m,0)
        {
            cout<<a[c2];
            c2=(c2+1)%5;
        }
    }
    // cout<<n<<" "<<m<<endl;
    nl;

}
