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

vi parent(101000);

int root(int a)
{
    int newparent;
    if(parent[a]==a)
    return a;
    else
    {
        newparent=root(parent[a]);
        parent[a]=newparent;
        return newparent;
    }
}

int quickUnion(int x,int y)
{
    parent[y]=x;
}

int main()
{
  fastio;
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      vi a(n+1);
      rep(i,n+1,1)
      {
        cin>>a[i];
        parent[i]=i;
      }

      int q;
      cin>>q;
      int x1,x2;
      while(q--)
      {
          int ch,x,y;
          cin>>ch>>x;
          if(ch==0)
          {
              cin>>y;
              x1=root(x);
              x2=root(y);
              if(x1==x2)
              cout<<"Invalid query!"<<endl;
              else
              {
                  if(a[x1]>a[x2])
                  quickUnion(x1,x2);
                  else if(a[x1]<a[x2])
                  quickUnion(x2,x1);
              }
          }
          else
          cout<<root(x)<<endl;
      }   
  }  
}