#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ii pair<int,int>
#define iii pair<ii,int>
#define vii vector<pair<int,string> >
#define vi vector<int>
#define vvi vector<vector<int> >
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define nu 100001
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
int a[27];
vi v[27];
 
int main()
{
    fastio;
    int n;
    cin>>n;
    string s[101];
    s[0]="{";
    
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i]+='{';
        int j=0;
        while(s[i-1][j] && s[i][j])
        {
            if(s[i-1][j]!=s[i][j])
            {
                
                v[s[i-1][j]-'a'].pb(s[i][j]-'a');
                a[s[i][j]-'a']++;
                break;
            }
            j++;
        }
        //cout<<s[i]<<'\n';
    }
    
    set<int> p;
    queue<int> q;
    
    if(a[26]==0)
    {
        p.insert(26);
        q.push(26);
        for(auto it=v[26].begin();it!=v[26].end();++it)
        {
            a[*it]--;
        }
    }
    else
    {
        cout<<"Impossible";
        exit(0);
    }
    
    while(q.size()<=26)
    {
        int x=q.size();
        for(int i=0;i<26;++i)
        {
            if(p.find(i)==p.end())
            {
                if(a[i]==0)
                {
                    p.insert(i);
                    q.push(i);
                    for(auto it=v[i].begin();it!=v[i].end();++it)
                    {
                        a[*it]--;
                    }
                }
            }    
        }
        if(x==q.size())
        {
            cout<<"Impossible";
            exit(0);
        }
    }
    
    while(!q.empty())
    {
        if(q.front()!=26)
        cout<<char('a'+q.front());
        q.pop();
    }    
}