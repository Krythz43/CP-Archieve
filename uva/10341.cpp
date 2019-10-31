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
double epl=1e-8;
int p,q,r,s,t,u;

double f(double x){
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    fastio;
    while(cin>>p)
    {
        cin>>q>>r>>s>>t>>u;
        double high=1,low=0,mid;

        if(f(high)*f(low)<=0)
        {while(high-low>epl)
        {
            // cout<<high<<" "<<low<<endl;
            mid=(high+low)/2;
            if (f(low)*f(mid)<=0)
            high=mid;
            else low=mid;
        }

        cout<<std::fixed<<setprecision(4)<<low<<endl;}
        else
        cout<<"No solution"<<endl;
    }
}