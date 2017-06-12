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

stack<int> now;
int k,data[55];
int last[1000005];
string s;
char sym[1000005];
vi child[1000005];
int n;

int parse(int a,int b)
{
  int now = n++;
  sym[now] = '?';
  if (a == b - 2) return now;
  sym[now] = s[last[b-1]-1];
  int i = b - 1;
  while (i > a)
  {
    child[now].pb(parse(last[i],i));
    i = last[i] - 2;
  }
  return now;
}

double val(int now)
{
  if (sym[now] == '?') return data[0];
  if (sym[now] == '+')
  {
    double ret = 0;
    REP(i,SIZE(child[now])) ret += val(child[now][i]);
    return min(ret,(double)data[SIZE(child[now]) - 1]);
  } else 
  {
    vector<double> ret;
    double risan = 1;
    double sisa = data[SIZE(child[now]) - 1];
    REP(i,SIZE(child[now])) ret.pb(val(child[now][i]));
    SORT(ret);
    REP(i,SIZE(child[now]))
    {
      double bagi = sisa / (double)(SIZE(child[now]) - i);
      risan *= min(bagi, ret[i]);
      sisa -= min(bagi, ret[i]);
    }
    return risan;
  }
}

int main()
{
  scanf("%d",&k);
  REP(i,k) scanf("%d",&data[i]);
  s = GetString();
  RESET(last,-1);
  REP(i,SIZE(s))
  {
    if (s[i] == '(') now.push(i);
    if (s[i] == ')')
    {
      last[i] = now.top();
      now.pop();
    }
  }
  parse(0,SIZE(s)-1);
  /*REP(i,n)
  {
    debug("%d %c :",i,sym[i]);
    REP(j,SIZE(child[i])) debug(" %d", child[i][j]);
    debug("\n");
  }*/
  printf("%.10lf\n",val(0));
  return 0;
}









