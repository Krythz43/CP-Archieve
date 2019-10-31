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
// #define endl '\n'

#define type ff.ff
#define tagCount ff.ss
#define tags ss.ff
#define id ss.ss.ff
#define scor ss.ss.ss


bool comp(pair<pair<char,int>,pair <vector<string>,pair<int,long long int >>> a, pair<pair<char,int>,pair <vector<string>,pair<int,long long int >>> b)
{
    if(a.type==b.type)
    {
        if(a.tagCount==b.tagCount)
        return a.scor<b.scor;
        else
        return a.tagCount<b.tagCount;
    }
    else
    return a.type<b.type;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    vector <pair<pair<char,int>,pair <vector<string>,pair<int,long long int >>>> photos;

    int x;
    char t;
    vector<string> tag;
    string s;

    lli score;

    for(int i=0;i<n;i++)
    {
        score=0;

        tag.clear();
        cin>>t>>x;
        for(int j=0;j<x;j++)
        {
            cin>>s;
            tag.pb(s);

            // for(int k=0;k<s.length();k++)
            // score+=pow(s[i]-96,6);
        }
        photos.push_back(make_pair(mp(t,x),mp(tag,mp(i,0))));
    }

    sort(photos.begin(),photos.end());

    int cons=0;

    vector <int> ans;

    vector<int> vis(n+1,0);

    int i=0;

    while(cons!=n && i<n)
    {

        if(vis[i])
        continue;


        if(photos[i].type=='H')
        {
            cons++;
            ans.pb(1);
            ans.pb(photos[i].id);
            vis[i]=1;
            s=photos[i].tags[0];
            int f=0;
            for(int j=0;j<n;j++)
            {
                if(vis[j]==0 && i!=j && photos[j].type=='H')
                {
                    for(int k=0;k<photos[j].tags.size();k++)
                    {
                        if(photos[j].tags[k]==s)
                        {
                            f=1;
                            ans.pb(1);
                            ans.pb(photos[j].id);
                            cons++;
                            vis[j]=1;
                            break;
                        }
                    }

                    if(f)
                    break;
                }
            }
        }
        else
        {
            if(i==n-1)
            break;

            ans.pb(2);
            ans.pb(photos[i].id);
            ans.pb(photos[i+1].id);
        }
        i++;
    }
    lli count =0;

    
    for(int i=0;i<ans.size();)
    {
        count++;
        i+=ans[i]+1;
    }

    cout<<count<<endl;

    for(int i=0;i<ans.size();)
    {
        int ex=ans[i];

        while(ex)
        {
            cout<<ans[i+ex]<<" ";
            ex--;
        }
        nl;
        i+=ans[i]+1;
    }

}