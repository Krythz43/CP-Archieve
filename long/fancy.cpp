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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        getline(cin>>ws,s);
        int f=0,l=s.length();
        if(l==3)
        {
            if(s[0]=='n' && s[1]=='o' && s[2]=='t')
            f=1;
        }
        else if(l>3)
        {
            if(s[0]=='n' && s[1]=='o' && s[2]=='t' && s[3]==' ')
            f=1;

            if(s[l-4]==' ' && s[l-3]=='n' && s[l-2]=='o' && s[l-1]=='t')
            f=1;

            if(l>4)
            {
                rep(i,l-4,0)
                {
                    if(s[i]==' ' && s[i+1]=='n' && s[i+2]=='o' && s[i+3]=='t' && s[i+4]==' ')
                    f=1;
                }
            }
        }

        if(f)
        {
            cout<<"Real Fancy";
        }
        else
        cout<<"regularly fancy";
        nl;

    }
}