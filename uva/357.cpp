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
lli llmax(lli a,lli b){if(a>b)return a; return b;}

int type[6];
lli memo [6][35000];
lli value(int id,int ml)
{
    // cout<<id<<" "<<ml<<endl;
    if(memo[id][ml]!=-1)
    return memo[id][ml];
    if(id==5 || ml<0)
    return 0;
    if(ml==0)
    return 1;

    if(ml>=type[id])
    return memo[id][ml]= value(id+1,ml) + value(id,ml-type[id]);
    return 0;
}

int main()
{
    type[0]=1;
    type[1]=5;
    type[2]=10;
    type[3]=25;
    type[4]=50;
    memset(memo,-1,sizeof memo);

    fastio;
    int n;
    while(cin>>n)
    {
       if(value(0,n)==1)
       printf("There is only %lld way to produce %d cents change.\n",value(0,n),n);
       else
       printf("There are %lld ways to produce %d cents change.\n",value(0,n),n);
    }
}