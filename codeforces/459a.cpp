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
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int size;
    if(x1==x2)
    {
        size=fabs(y2-y1);
        cout<<x1+size<<" "<<y1<<" "<<x2+size<<" "<<y2;
    }
    else if(y1==y2)
    {
        size=fabs(x2-x1);
        cout<<x1<<" "<<y1+size<<" "<<x2<<" "<<y2+size;
    }
    else if(fabs(x2-x1)==fabs(y2-y1))
    {
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
    }
    else
    cout<<"-1";
}