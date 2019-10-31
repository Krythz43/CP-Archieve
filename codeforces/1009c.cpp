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
lli llmax(lli a,lli b){if(a>b)return a; return b;}

int main()
{
    fastio;
    int n,m;
    double ans=0;

    cin>>n>>m;
    while(m--)
    {
        int x,d;
        cin>>x>>d;
        ans+=x;
        if(d>=0)
        {
            double s=0;
            s=d*(n)*(n-1)/2;
            ans+=((double)s)/n;
        }   
        else
        {
            double s=0;
            if(n%2)
            {
                s=2*(d*(n/2)*(n/2-1)/2);
                ans+=((double)s)/n;
            }
            else
            {
                s=2*(d*(n/2)*(n/2-1)/2);
                s-=d*n/2;
                ans+=((double)s)/n;
            }
        }  

        cout<<ans<<endl;  
    }
}