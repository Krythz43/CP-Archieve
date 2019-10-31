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
    int b[110];
    while(cin>>b[0])
    {
        int size=1,nc=0;
        rep(i,size,0)
        {
            cin>>b[i];
            if(b[i]== -999999)
            {
                break;
            }
            size++;
            if(b[i]<0)
            nc++;
        }

        vi a(size);
        lli pro=1;
        rep(i,size,0)
        a[i]=b[i];
        sort(a.begin(),a.end());
        if(nc%2)
        nc--;

        rep(i,size,0)
        {
            if(a[i]>0)
            pro*=a[i];

            if(a[i]<0)
            {
                if(nc)
                {
                    pro*=a[i];
                    nc--;
                }
            }
        }
        cout<<pro<<endl;
    }
}