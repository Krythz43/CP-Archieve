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

lli GCD(lli A, lli B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}

int main()
{
    fastio;
    lli l,r;
    cin>>l>>r;

    for(lli i=l;i<=r;i++)
    {
        for(lli j=i+1;j<=r;j++)
        {
            for(lli k=j+1;k<=r;k++)
            {
                if(GCD(i,j)==1 && GCD(j,k)==1 && GCD(i,k)!=1)
                {
                    cout<<i<<" "<<j<<" "<<k;
                    return 0;
                }
            }
        }
    }
    cout<<"-1";
}