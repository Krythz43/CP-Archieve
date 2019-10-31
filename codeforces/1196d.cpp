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
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        lli ans=inf,tans;
        int n,k;
        cin>>n>>k;
        string s1="",s2="",s3="";
        string s;
        cin>>s;
        rep(i,k,0){
            if(i%3==1)s1+='R';
            else if(i%3==2)s1+='G';
            else s1+='B';
        }

        rep(i,k,0){
            if(i%3==1)s2+='B';
            else if(i%3==2)s2+='R';
            else s2+='G';
        }



        rep(i,k,0){
            if(i%3==1)s3+='G';
            else if(i%3==2)s3+='B';
            else s3+='R';
        }

        // cout<<s1<<" "<<s2<<" "<<s3<<endl;

        
        tans=0;
        vector<char> swi,swe;

        if(s1[0]=='B')swi={'B','R','G'};
        else if(s1[0]=='G')swi={'G','B','R'};
        else swi={'R','G','B'};

        if(s1[k-1]=='B')swe={'B','R','G'};
        else if(s1[k-1]=='G')swe={'G','B','R'};
        else swe={'R','G','B'};

        rep(j,k,0){
            if(s[j]!=s1[j])tans++;
        }
        ans=min(tans,ans);
        // cout<<tans<<endl;

        // cout<<s1<<" ";
        // cout<<swi[0]<<" "<<swe[0]<<endl;
        rep(i,n-k+1,1){
            if(swi[(i-1)%3]!=s[i-1])tans--;
            if(swe[i%3]!=s[i+k-1])tans++;
            ans=min(ans,tans);
            // cout<<tans<<" at "<<i<<endl;
        }
        

        

        
        

        if(s2[0]=='B')swi={'B','R','G'};
        else if(s2[0]=='G')swi={'G','B','R'};
        else swi={'R','G','B'};

        if(s2[k-1]=='B')swe={'B','R','G'};
        else if(s2[k-1]=='G')swe={'G','B','R'};
        else swe={'R','G','B'}; 
        // cout<<swi[0]<<" "<<swe[0]<<" "<<s1<<endl;
        tans=0;
        rep(j,k,0){
            if(s[j]!=s2[j])tans++;
        }
        // cout<<tans<<endl;
        ans=min(tans,ans);
        rep(i,n-k+1,1){
            if(swi[(i-1)%3]!=s[i-1])tans--;
            if(swe[i%3]!=s[i+k-1])tans++;
            ans=min(ans,tans);
        }








        if(s3[0]=='B')swi={'B','R','G'};
        else if(s3[0]=='G')swi={'G','B','R'};
        else swi={'R','G','B'};

        if(s3[k-1]=='B')swe={'B','R','G'};
        else if(s3[k-1]=='G')swe={'G','B','R'};
        else swe={'R','G','B'};

        // cout<<swi[0]<<" "<<swe[0]<<" "<<s1<<endl;

        tans=0;

        rep(j,k,0){
            if(s[j]!=s3[j])tans++;
        }
        // cout<<tans<<endl;
        ans=min(tans,ans);

        rep(i,n-k+1,1){
            if(swi[(i-1)%3]!=s[i-1])tans--;
            if(swe[i%3]!=s[i+k-1])tans++;
            ans=min(ans,tans);
        }




        cout<<ans<<endl;
    }
    
}