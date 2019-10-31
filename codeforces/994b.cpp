#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

struct knight
{
    lli i;
    lli p;
    lli c;
    lli ec;
};

bool comp1(knight a, knight b)
{
    return a.p<b.p;
}

bool comp2(knight a, knight b)
{
    return a.i<b.i;
}


int main()
{
    fastio;
    lli n,k;
    cin>>n>>k;
    vector <knight> a(n);

    rep(i,n,0)
    {
        cin>>a[i].p;
        a[i].i=i;
    }

    rep(i,n,0)
    {
        cin>>a[i].c;
        a[i].ec=a[i].c;
    }

    sort(a.begin(),a.end(),comp1);

    priority_queue <lli> p;
    p.push(a[0].c);

    rep(i,n,1)
    {
        int size=k<p.size()?k:p.size();
        vector <lli> temp(size);
        rep(j,size,0)
        {
            temp[j]=p.top();
            a[i].ec+=temp[j];
            p.pop();
        }

        rep(j,size,0)
        p.push(temp[j]);

        p.push(a[i].c);
    }

    sort(a.begin(),a.end(),comp2);

    rep(i,n,0)
    cout<<a[i].ec<<" ";
}