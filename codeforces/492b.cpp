#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}


double maxi (double a, double b)
{
    if(a>b)
    return a;
    else
    return b;
}


int main()
{
    fastio;
    int n;
    double l;
    cin>>n>>l;
    vi a(n);

    rep(i,n,0)
    cin>>a[i];

    sort(a.begin(),a.end());

    double maxe=maxi(a[0]-0,l-a[n-1]);

    rep(i,n-1,0)
    {
        double t=(double(a[i]+a[i+1]))/2 - a[i];
        maxe=maxi(t,maxe);
    }

    cout<<std::fixed<<setprecision(10)<<maxe;

}