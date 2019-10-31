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
    string s;
    vi neg(100005,0),pos(100005,0);
    int zc=0;
    rep(i,n,0)
    {
        cin>>s;
        int csum=0;
        rep(j,s.length(),0)
        {
            if(s[j]=='(')
            csum++;
            else
            csum--;
        }
        int f=1;
        if(csum==0 && s[0]=='(' && s[s.length()-1]==')')
        {
            csum=0;
            rep(j,s.length(),0)
            {
                if(s[j]=='(')
                csum++;
                else
                csum--;

                if(csum<0)
                {
                    f=0;
                    break;
                }
            }
            if(f)
            zc++;
        }
        if(csum<0 && s[s.length()-1]==')')
        {
            int lsum=0;
            for(int j=s.length()-1;j>=0;j--)
            {
                if(s[j]=='(')
                lsum++;
                else
                lsum--;

                if(lsum>0)
                {
                    f=0;
                    break;
                }
            }


            if(f)
            neg[-csum]++;
        }
        else if (csum>0 && s[0]=='(')
        {
            int lsum=0;
            rep(j,s.length(),0)
            {
                if(s[j]=='(')
                lsum++;
                else
                lsum--;

                if(lsum<0)
                {
                    f=0;
                    break;
                }
            }

            if(f)
            pos[csum]++;
        }
    }

    int ans=zc/2;
    rep(i,100005,1)
    ans+=min(neg[i],pos[i]);
    cout<<ans<<endl;

}