//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v3.0.3 (BETA)

int n;
int data[200005];
vi angka;
map<int,int> mapping;
vi now;
pii dpnaik[200005];
pii dpturun[200005];
pii tree[800005];
pii risan = mp(-INF,0);
int dua[200005];
int MOD = 1e9 + 7;

void combine(pii &a, pii b)
{
  if (b.fi > a.fi) a = b;
  else if (b.fi == a.fi) a.se += b.se;
  if (a.se >= MOD) a.se -= MOD;
}

/*void backup()
{
  FORN(i,0,4002) tree2[i] = tree[i];
}

void load()
{
  FORN(i,0,4002) tree[i] = tree2[i];
}*/

void update(int ix,int L,int R,int pos,pii val)
{
  if (L == R)
  {
    combine(tree[ix],val);
    return;
  }
  int M = (L + R) >> 1;
  if (pos <= M) update(ix*2+1,L,M,pos,val);
  else update(ix*2+2,M+1,R,pos,val);
  tree[ix] = mp(-INF,0);
  combine(tree[ix],tree[ix*2+1]);
  combine(tree[ix],tree[ix*2+2]);
}

pii query(int ix,int L,int R,int x,int y)
{
  if (x <= L && R <= y) return tree[ix];
  if (R < x || y < L) return mp(-INF,0);
  pii ret = mp(-INF,0);
  int M = (L + R) >> 1;
  combine(ret,query(ix*2+1,L,M,x,y));
  combine(ret,query(ix*2+2,M+1,R,x,y));
  return ret;
}

int main()
{
  scanf("%d",&n);
  dua[0] = 1;
  FORN(i,1,n) dua[i] = (dua[i-1] * 2) % MOD;
  REP(i,n)
  {
    scanf("%d",&data[i]);
    angka.pb(data[i]);
  }
  SORT(angka);
  angka.erase(unique(ALL(angka)),angka.end());
  REP(i,SIZE(angka)) mapping[angka[i]] = i;
  REP(i,n) data[i] = mapping[data[i]];

  FORN(i,0,800002) tree[i] = mp(-INF,0);
  FORD(i,n-1,0)
  {
    dpnaik[i] = mp(1,1);
    pii q = query(0,0,n-1,data[i]+1,n-1);
    combine(dpnaik[i],mp(q.fi+1,q.se));
    update(0,0,n-1,data[i],dpnaik[i]);
  }
  FORN(i,0,800002) tree[i] = mp(-INF,0);
  FORD(i,n-1,0)
  {
    dpturun[i] = mp(1,1);
    pii q = query(0,0,n-1,0,data[i]-1);
    combine(dpturun[i],mp(q.fi+1,q.se));
    update(0,0,n-1,data[i],dpturun[i]);
  }
  //REP(i,n) debug("%d %d : %d %d %d %d\n",i,data[i],dpnaik[i].fi,dpnaik[i].se,dpturun[i].fi,dpturun[i].se);
  REP(i,n)
  {
    pii temp;
    temp.fi = dpnaik[i].fi + dpturun[i].fi - 1;
    temp.se = ((LL)(dpnaik[i].se) * (LL)(dpturun[i].se)) % MOD;
    temp.se = ((LL)temp.se * (LL)dua[n - temp.fi]) % MOD;
    combine(risan,temp);
  }
  printf("%d %d\n",risan.fi,risan.se);
  return 0;
}









