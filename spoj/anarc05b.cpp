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
#define endl '\n'


int main()
{
    fastio;
    while(1)
    {
        int n,r;
        cin>>n;
        if(n==0)
        break;
        vinput(a,n);
        cin>>r;
        vinput(b,r);

        vi com;
        lli ans=0;
        rep(i,n,0)
        {
            if(binary_search(b.begin(),b.end(),a[i]))
            {
                com.pb(a[i]);
                ans+=a[i];
            }
        }

        int p1=0,p2=0,c=0;
        lli s1=0,s2=0;
        vlli x1,x2;

        while(1)
        {
            if(p1==n && p2==r)
            break;
            if(p1!=n)
            {
                if(c!=com.size())
                {
                    if(a[p1]!=com[c])
                    {
                        s1+=a[p1];
                        p1++;
                    }
                }
                else
                {
                    s1+=a[p1];
                    p1++;
                }
            }

            if(p2!=r)
            {
                if(c!=com.size())
                {
                    if(b[p2]!=com[c])
                    {
                        s2+=b[p2];
                        p2++;
                    }
                }
                else
                {
                    s2+=b[p2];
                    p2++;
                }
            }

            if(c!=com.size())
            {
                if(b[p2]==com[c] && a[p1]==com[c])
                {
                    c++;
                    x1.pb(s1);
                    x2.pb(s2);
                    s1=s2=0;
                    p1++,p2++;
                }
            }

        }

        x1.pb(s1);
        x2.pb(s2);

        rep(i,x1.size(),0)
        {
            // cout<<x1[i]<<" "<<x2[i]<<endl;
            ans+=max(x1[i],x2[i]);
        }
        cout<<ans<<endl;
    }
}