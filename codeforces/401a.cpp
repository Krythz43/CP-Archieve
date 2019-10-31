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

int main()
{
    fastio;
    int n,x,ans=0;
    cin>>n>>x;
    vi a(n);

    rep(i,n,0)
    cin>>a[i];
    int sum=accumulate(a.begin(),a.end(),0);
    sum=fabs(sum);
    if(sum==0)
    {
        cout<<"0";
    }
    else
    {
        if(sum<=x)
        cout<<"1";
        else
        {
            ans+=sum/x;
            sum%=x;
            if(sum)
            ans++;
            cout<<ans;
        }
    }
}