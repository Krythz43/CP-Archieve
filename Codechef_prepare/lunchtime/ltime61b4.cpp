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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<int> > a(n,vector<int> (m));

        rep(i,n,0)
        {
            rep(j,m,0)
            cin>>a[i][j];
        }

        int q;
        cin>>q;
        while(q--)
        {
            vector <int> b(m);
            vi temp(m);

            int l,r;
            cin>>l>>r;

            rep(i,m,0)
            b[i]=a[l-1][i];

            for(int i=l;i<r;i++)
            {
                rep(j,m,0)
                {
                    temp[j]=a[i][b[j]-1];
                }

                rep(j,m,0)
                {
                    b[j]=temp[j];
                }
            }

            lli ans=0;


            rep(j,m,0)
            {
                ans+=(j+1)*b[j];
            }
            cout<<ans<<endl;
        }
    }
}