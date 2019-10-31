#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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
// #define endl '\n'

bool comp(pair<pair<int,char>,string> a,pair<pair<int,char>,string> b)
{
    if(a.ff.ff==b.ff.ff)
    return a.ff.ss<b.ff.ss;
    return a.ff.ff<b.ff.ff;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    string s;
    int c=0;
    char lastvo;
    vector<char> vow={'a','e','i','o','u'};

    vector<pair<pair<int,char>,string> >a;

    rep(i,n,0)
    {
        cin>>s;
        c=0;
        for(int j=s.length()-1;j>=0;j--)
        {
            rep(k,5,0)
            {
                if(vow[k]==s[j])
                {
                    if(c)
                    c++;
                    else
                    {
                        c++;
                        lastvo=vow[k];
                    }
                }
            }
        }
        a.pb(mp(mp(c,lastvo),s));
    }
    vector<pair<string,string>> imp,cor,ans;
    SOP(a,comp);
    int co[5],sa,start[5];

    map<char,int> M;
    M['a']=0;
    M['e']=1;
    M['i']=2;
    M['o']=3;
    M['u']=4;

    // rep(i,n,0)
    // cout<<a[i].ff.ff<<" "<<a[i].ff.ss<<" "<<a[i].ss<<endl;

    for(int i=0;i<n-1;)
    {
        // cout<<"her1"<<endl;
        if(a[i].ff.ff!=a[i+1].ff.ff)
        {
            i++;
        }
        else
        {
            memset(co,0,sizeof co);
            memset(start,-1,sizeof start);
            int j=i,temp=i;
            while(j<n && a[j].ff.ff==a[temp].ff.ff)
            {
                if(start[M[a[j].ff.ss]]==-1)
                {
                    start[M[a[j].ff.ss]]=j;
                }
                co[M[a[j].ff.ss]]++;
                j++;
            }
            i=j;
            vector<int> tro;

            rep(z,5,0)
            {
                if(co[z]%2)
                tro.pb(start[z]);
            }
            for(int z=0;z<2*(tro.size()/2);z+=2)
            {
                imp.pb(mp(a[tro[z]].ss,a[tro[z+1]].ss));
                // cout<<"pushing back tro:"<<a[tro[z]].ss<<" "<<a[tro[z+1]].ss<<" at "<<tro[z]<<" and "<<tro[z+1]<<endl;
            }
            int itz;
            for(int z=0;z<5;z++)
            {
                if(co[z])
                {
                    if(co[z]%2)
                    {
                        itz=start[z]+1;
                        co[z]--;
                    }
                    else
                    itz=start[z];
                    while(co[z]>=2)
                    {
                        cor.pb(mp(a[itz].ss,a[itz+1].ss));
                        // cout<<"pushing back cor:"<<a[itz].ss<<" "<<a[itz+1].ss<<" at "<<itz<<endl;
                        co[z]-=2;
                        itz+=2;
                    }
                }
            }
        }
    }

    int p1=imp.size()-1,p2=cor.size()-1;
    while(p1>=0 && p2>=0)
    {
        ans.pb(imp[p1]);
        ans.pb(cor[p2]);
        p1--;
        p2--;
    }
    while(p2>=1)
    {
        ans.pb(cor[p2]);
        ans.pb(cor[p2-1]);
        p2-=2;
    }

    // cout<<"bug "<<imp.size()<<" "<<cor.size()<<endl;

    cout<<ans.size()/2<<endl;
    for(int i=0;i<ans.size();i+=2)
    {
        cout<<ans[i].ff<<" "<<ans[i+1].ff<<endl;
        cout<<ans[i].ss<<" "<<ans[i+1].ss<<endl;
    }

}