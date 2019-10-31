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
// #define endl '\n'

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        lli n,ty,x,y,z;
        cin>>n>>ty>>x>>y>>z;
        lli den,num;
        den=2*n+1;

        if(ty==2 || ty==4)
        num=den-2*y;
        else if(ty==1)
        {
            if(y>x)
            {
                if(z==y+1)
                num=den-2*y+y-1;
                else
                num=y-1;
            }
            else
            {
                if(x==z)
                num=y+1;
                else
                num=den-2*y+y+1;
            }
        }
        else
        {
            if(z>y)
            {
                if(x==z)
                num=y+1;
                else
                num=den-2*y+y+1;
            }
            else
            {
                if(x==z)
                num=y-1;
                else
                num=den-2*y+y-1;
            }
        }

        lli gcd=__gcd(num,den);
        num/=gcd;
        den/=gcd;
        cout<<num<<" "<<den<<endl;
        // cout<<(num*180)/den<<endl;
    }
}