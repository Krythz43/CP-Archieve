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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,coM) sort(a.begin(),a.end(),coM)
#define inf INT_MAX
#define endl '\n'



int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b)
        swap(a,b);
        if(c%__gcd(a,b) || (c>a && c>b) )
        cout<<-1<<endl;
        else
        {
            queue<pair<ipair,int>> Q;
            map<ipair,int> M;
            Q.push(mp(mp(0,0),0));
            while(!Q.empty())
            {
                pair<ipair,int> x;
                x=Q.front();
                Q.pop();
                int p,q,r;
                p=x.ff.ff;
                q=x.ff.ss;
                r=x.ss;
                if(M.count(mp(p,q)))
                continue;
                M[mp(p,q)]++;
                if(p==c || q==c)
                {
                    cout<<r<<endl;
                    break;
                }

                ipair t1;
                //emptying
                t1.ff=0;
                t1.ss=q;
                if(M.count(t1)==0)
                Q.push(mp(t1,r+1));

                t1.ff=p;
                t1.ss=0;
                if(M.count(t1)==0)
                Q.push(mp(t1,r+1));

                //filling

                t1.ff=a;
                t1.ss=q;
                if(M.count(t1)==0)
                Q.push(mp(t1,r+1));

                t1.ff=p;
                t1.ss=b;
                if(M.count(t1)==0)
                Q.push(mp(t1,r+1));

                //pouring from a to b;

                if(p+q<=b)
                {
                    t1.ff=0;
                    t1.ss=p+q;
                    if(M.count(t1)==0)
                    Q.push(mp(t1,r+1));
                }
                else
                {
                    t1.ff=p-(b-q);
                    t1.ss=b;
                    if(M.count(t1)==0)
                    Q.push(mp(t1,r+1));
                }

                //pouring from b to a

                if(p+q<=a)
                {
                    t1.ff=p+q;
                    t1.ss=0;
                    if(M.count(t1)==0)
                    Q.push(mp(t1,r+1));
                }
                else
                {
                    t1.ff=a;
                    t1.ss=q-(a-p);
                    if(M.count(t1)==0)
                    Q.push(mp(t1,r+1));
                }
            }
        }
    }
}