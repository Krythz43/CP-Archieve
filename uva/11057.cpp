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
    int n;
    while(cin>>n)
    {
        vi a(n);
        rep(i,n,0)
        cin>>a[i];
        sort(a.begin(),a.end());
        int x,y;
        cin>>x;
        int a1=INT_MAX,a2=INT_MAX,ans=INT_MAX;

        rep(i,n,0)
        {
            if(x<a[i])
            break;

            y=x-a[i];

            if(2*y==x)
            {
                if(a[i]==a[i+1])
               { a1=a2=a[i];break;
               }
            }
            else
            {
                int in;
                in=lower_bound(a.begin(),a.end(),y)-a.begin();
                if(a[in]==y)
                {
                    if(ans>fabs(y-a[i]))
                    {
                        ans=fabs(y-a[i]);
                        a1=a[i];
                        a2=y;
                    }
                }
            }

        }

        if(a2<a1)
        {
            x=a2;
            a2=a1;
            a1=x;
        }

        cout<<"Peter should buy books whose prices are "<<a1<<" and "<<a2<<"."<<endl<<endl;
    }
}