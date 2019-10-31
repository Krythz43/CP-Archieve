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
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int main()
{
    fastio;
    string s1,s2;
    s1=s2="";
    int n,m;
    cin>>n;
    m=n;

    while(1)
    {
        if(m%7)
        {
            s2+='4';
            m-=4;
        }
        else
        {
            rep(i,m/7,0)
            s2+='7';
            cout<<s2;
            return 0;
        }
        if(m<=0)
        break;
    }
    
    while(1)
    {
        if(n%4)
        {
            s1+='7';
            n-=7;
        }
        else
        {
            rep(i,n/4,0)
            s1+='4';
            cout<<s1;
            return 0;
        }
        if(n<=0)
        break;
    }

    cout<<"-1";
}