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
        int x1,x2,v1,v2,x3;
        float t1,t2;
        cin>>x1>>x2>>x3>>v1>>v2;
        t1=fabs(x3-x1)/((float)v1);
        t2=fabs(x3-x2)/((float)v2);
        if(t1>t2)
        cout<<"Kefa";
        else if(t1<t2)
        cout<<"Chef";
        else
        cout<<"Draw";
        nl;
    }
}