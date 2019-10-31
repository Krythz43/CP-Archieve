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

#define mod 1000003


int main()
{
    fastio;
    char a[101];
    cin>>a;
    int l=strlen(a);
    rep(i,l,0)
    {
        if(a[i]=='a' || a[i]=='e'|| a[i]=='i'|| a[i]=='o'|| a[i]=='u'|| a[i]=='y'|| a[i]=='A'|| a[i]=='E'|| a[i]=='I'|| a[i]=='O'||a[i]=='U'||a[i]=='Y')
        {

        }
        else 
        {
            cout<<".";
            if(a[i]<96)
            cout<<(char)(a[i]+32);
            else
            cout<<a[i];
        }
    }
}