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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'



int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        ipair start,end;
        cin>>s1;
        start.ff=s1[0]-96;
        start.ss=s1[1]-48;
        cin>>s1;
        end.ff=s1[0]-96;
        end.ss=s1[1]-48;
        // cout<<start.ff<<start.ss<<" to "<<end.ff<<end.ss<<endl;
        vector<ipair> moves={{2,1},{1,2},{-2,1},{1,-2},{2,-1},{-1,2},{-2,-1},{-1,-2}};

        queue<pair<ipair,int>> Q;
        Q.push(mp(start,0));
        map<ipair,int> M;
        pair<ipair,int> t1;
        ipair t2;

        while(!Q.empty())
        {
            t1=Q.front();
            Q.pop();
            if(t1.ff==end)
            {
                cout<<t1.ss<<endl;
                break;
            }

            if(M.count(t1.ff))
            continue;
            M[t1.ff]++;

            for(auto x:moves)
            {
                t2.ff=t1.ff.ff+x.ff;
                t2.ss=t1.ff.ss+x.ss;
                if(t2.ff>0 && t2.ff<9 && t2.ss>0 && t2.ss<9)
                {
                    if(M.count(t2)==0)
                    Q.push(mp(t2,t1.ss+1));
                }
            }
        }
    }
}
