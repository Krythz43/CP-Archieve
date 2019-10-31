#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false)
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
#define priority_queue pq;
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i];} cout<<endl

#define mod 1000000007
int main()
{
    int t;
    fastio;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;

        vi a(n+1);

        rep(i,n+1,1)
        cin>>a[i];

        while(q--)
        {
            int x;
            cin>>x;
            int swape=0;
            int low=1;
            int high=n;
            int mid,pos;

            rep(i,n+1,1)
            {
                if(x==a[i])
                {
                    pos=i;
                    break;
                }
            }
            while(low<=high)
            {
                mid=(low+high)/2;
                if(mid==pos)
                break;
                
                if(mid<pos)
                {
                    low=mid+1;
                    if(!(x>a[mid]))
                    {
                        swape++;
                    }
                }
                else
                {
                    high=mid-1;
                    if(x>a[mid])
                    swape++;
                }
            }
            cout<<swape<<endl;
        }
    }
}