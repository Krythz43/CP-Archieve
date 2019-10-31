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


int n;
char a[101][101];
bool isvalid(int i,int j)
{
    return i>=0 && j>=0 && i<n && j<n;
}


bool check(int i,int j)
{
    int c=0;
    if(isvalid(i+1,j))
    if(a[i+1][j]=='o')
    c++;
    if(isvalid(i-1,j))
    if(a[i-1][j]=='o')
    c++;
    if(isvalid(i,j+1))
    if(a[i][j+1]=='o')
    c++;
    if(isvalid(i,j-1))
    if(a[i][j-1]=='o')
    c++;

    return c%2;
}

int main()
{
    fastio;
    cin>>n;

    rep(i,n,0)
    cin>>a[i];

    rep(i,n,0)
    rep(j,n,0)
    if(check(i,j))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}