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

int size= 200005;

int main()
{
    fastio;
    char a[size],b[size];
    cin>>a>>b;
    int l1=strlen(a),l2=strlen(b);
    int i=l1-1,j=l2-1;

    int ans=l1+l2;
    for(;;)
    {
        if(i<0 || j<0)
        break;

        if(a[i]==b[j])
        {ans-=2;
        }
        else
        {
            break;
        }
        i--;
        j--;

    }

    cout<<ans;
}