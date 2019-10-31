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
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;

int main()
{
    fastio;
    int n;
    cin>>n;
    vlli a(n),sum(n,0);
    cin>>a[0];
    sum[0]=a[0];
    rep(i,n,1)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    // printarray(a,n)
    // printarray(sum,n)

    lli x,y,z,c=0;
    x=y=z=0;

    if(sum[n-1]%3)
    {
        cout<<"0";
        return 0;
    }
    else
    {
        lli pre=0,ans=0,pa=0;
		rep(i,n-1,0)
		{
			pre+=a[i];
			if( pre==(2*sum[n-1])/3)
				ans+=pa;
			if(pre==(sum[n-1])/3)
				pa++;
		}
        cout<<ans;
    }
}