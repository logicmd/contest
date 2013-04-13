#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)    for(int i=(a);i<(b);i++)
#define REP(i,n)    FOR(i,0,n)
#define SORT(v)     sort((v).begin(),(v).end())
#define UN(v)     SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb        push_back

const int mod =  1000000007;

ll f[11111];
ll qp(ll val,ll st){
  ll res=1;
  while(st){
    if(st&1)res*=val,res%=mod;
    val*=val;val%=mod;
    st>>=1;
  }
  return res;
}
ll inv(ll val){return qp(val,mod-2);}
ll c(int n,int m){
  ll r=f[n];
  r*=inv(f[m]);r%=mod;
  r*=inv(f[n-m]);r%=mod;
  return r;
}

int a[11111];

int main(){
#ifdef LocalHost
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif

  f[0]=1;
  FOR(i,1,11111)f[i]=(f[i-1]*i)%mod;

  int tc;
  cin>>tc;
  REP(TC,tc){
    int n,k;
    cin>>n>>k;
    REP(i,n) scanf("%d",a+i);
    sort(a,a+n);
    ll res = 0;
    FOR(i,k-1,n){
      res += a[i] * c(i,k-1);
      res %= mod;
    }
    printf("Case #%d: %d\n",TC+1,int(res));
  }


#ifdef LocalHost
//  printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
  return 0;
}