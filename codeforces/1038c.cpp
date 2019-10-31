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
    int n;
    cin>>n;
    vinput(a,n);
    vinput(b,n);
    SO(a);
    SO(b);
    int p1=a.size()-1;
    int p2=b.size()-1;

    int t=1;
    lli as=0,bs=0;
    while(p1!=-1  ||  p2 !=-1)
    {
        if(t%2)
        {
            if(p1==-1)
            p2--;
            else  if(p2==-1)
            {
                as+=a[p1];
                p1--;
            }
            else
            {
                if(a[p1]>b[p2])
                {
                    as+=a[p1];
                    p1--;
                }
                else
                p2--;

            }
        }
        else
        {
            if(p2==-1)
            p1--;
            else  if(p1==-1)
            {
                bs+=b[p2];
                p2--;
            }
            else
            {
                if(b[p2]>a[p1])
                {
                    bs+=b[p2];
                    p2--;
                }
                else
                p1--;

            }
        }
        t++;
        // cout<<as<<" "<<bs<<endl;
    }
    cout<<as-bs;

}