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

bool isind(int y)
{
    vector <int> vis(10,0);
    int flag=1;
    while(y)
    {
        int t=y%10;
        if(vis[t]!=0)
        {
            flag=0;
            break;
        }
        else
        vis[t]++;
        y/=10;
    }
    return flag;
}
int main()
{
    fastio;
    int y;
    cin>>y;

    for(;;)
    {
        y++;
        if(isind(y))
        {
            cout<<y;
            return 0;
        }
    }
}