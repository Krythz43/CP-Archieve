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
    string s;
    cin>>s;
    string fr="",bc="";
    int n=s.length();

    int p1=0,p2=n-1;

    while(p2-p1>=2){
        // cout<<p1<<" "<<p2<<endl;
        if(s[p1]==s[p2]){
            fr+=s[p1];
            bc+=s[p2];
            p1++;
            p2--;
        }
        else if(p2-p1==1)break;
        else if(p2-p1==2){
            if(s[p1]==s[p2-1]){
                fr+=s[p1];
                bc+=s[p2-1];
            }
            else if(s[p1+1]==s[p2]){
                fr+=s[p1+1];
                bc+=s[p2];
            }
            break;
        }
        else{
            if(s[p1+1]==s[p2-1]){
                fr+=s[p1+1];
                bc+=s[p2-1];
                p1+=2;
                p2-=2;
            }
            else if(s[p1]==s[p2-1])
            p2--;
            else if(s[p1+1]==s[p2])
            p1++;
        }
    }

    if(p1!=p2)fr+=s[p1];

    reverse(bc.begin(),bc.end());
    string ans=fr+bc;
    if(ans.length()>=n/2)
    cout<<ans<<endl;
    else
    cout<<"IMPOSSIBLE"<<endl;
}


// bool comp(ipair a,ipair b){
//     return a.ss-a.ff>b.ss-b.ff;
// }

// int main(){
//     string s;
//     cin>>s;
//     string s1=s;
//     // s1=reverse(s1.begin(),s1.end());
//     int n=s.length();
//     vector<ipair> a;
//     int p1,p2;
//     rep(i,n,0)a.pb(mp(i,i));

//     p1=0,p2=n-1;
//     while(p2>p1){
//         if(s[p1]=='a' && s[p2]=='a'){
//             a.pb(mp(p1,p2));
//             p1++;
//             p2--;
//         }
//         while(p1!=n){
//             if(s[p1]=='a')
//             break;
//             p1++;
//         }

//         while(p2!=-1){
//             if(s[p2]=='a')
//             break;
//             p2--;
//         }
//     }

//     p1=0,p2=n-1;
//     while(p2>p1){
//         if(s[p1]=='b' && s[p2]=='b'){
//             a.pb(mp(p1,p2));
//             p1++;
//             p2--;
//         }
//         while(p1!=n){
//             if(s[p1]=='b')
//             break;
//             p1++;
//         }

//         while(p2!=-1){
//             if(s[p2]=='b')
//             break;
//             p2--;
//         }
//     }

//     p1=0,p2=n-1;
//     while(p2>p1){
//         if(s[p1]=='c' && s[p2]=='c'){
//             a.pb(mp(p1,p2));
//             p1++;
//             p2--;
//         }
//         while(p1!=n){
//             if(s[p1]=='c')
//             break;
//             p1++;
//         }

//         while(p2!=-1){
//             if(s[p2]=='c')
//             break;
//             p2--;
//         }
//     }

//     sort(a.begin(),a.end(),comp);

//     int cdiff=a[0].ss-a[0].ff,st=a[0].ff,en=a[0].ss;
//     vi ans;
//     ans.pb(a[0].ff);
//     if(a[0].ss!=a[0].ff)
//     ans.pb(a[0].ss);
//     rep(i,a.size(),1){

//         // cout<<a[0].ff<<" "<<a[0].ss<<" "<<st<<" "<<" "<<en<<endl;
//         if(a[i].ff>st && a[i].ss<en){
//             cout<<"selecting "<<s[a[i].ff]<<" at position "<<a[i].ff<<" with a range length "<<a[i].ss-a[i].ff<<endl;
//             ans.pb(a[i].ff);
//             if(a[i].ff!=a[i].ss)
//             ans.pb(a[i].ss);
//             st=a[i].ff,en=a[i].ss;
//         }
//     }

//     rep(i,a.size(),0)cout<<s[a[i].ff]<<" "<<a[i].ff<<" "<<a[i].ss<<endl;
//     SO(ans);
//     string fans="";
//     rep(i,ans.size(),0)
//     fans+=s[ans[i]];

//     cout<<fans<<endl;
//     if(fans.length()>=n/2)
//     cout<<fans<<endl;
//     else cout<< "IMPOSSIBLE"<<endl;
// }