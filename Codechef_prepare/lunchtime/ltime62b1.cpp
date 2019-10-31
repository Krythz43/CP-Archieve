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
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}
lli a,b,c,x,y,s1,s2;

bool f(lli a, lli b,lli c)
{
    s1=x-a;
    s2=y-b;

    if(s1<0 || s2<0)
    return false;
    else
    {
        if(c==s1+s2)
        {return true;
        }
        else
        return false;
    }

}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>x>>y;

        if(f(a,b,c) || f(b,a,c) || f(a,c,b)|| f(c,a,b) || f(b,c,a) || f(c,b,a))
        cout<<"YES";
        else
        cout<<"NO";
        nl;
    }
}