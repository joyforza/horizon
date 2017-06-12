#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
#define MAXN 505
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9

template<class T> inline T Mid(T a,T b) {return ((a + b) / 2);}
template<class T> inline T Max(T a,T b) {return a > b ? a : b;}

int sign(RL x) {return x < -EPS ? -1 : x > EPS;}
int sign(RL x, RL y) {return sign(x - y);}

typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

/*** template ****/
struct POINT {
    double x,y;
    POINT(double _x = 0,double _y = 0){x = _x, y = _y;}
} p[MAXN];

struct CIRCLE {
    double r;
    POINT o;
    CIRCLE(double _r = 0 , POINT _o = 0){r = _r, o = _o;}
};
double dist(POINT p1,POINT p2){
    return sqrt((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y));
}

bool incir(POINT a ,CIRCLE b){
   //return (dist(a, b.o) <= b.r);
    double del = b.r - dist(a, b.o);
    if (abs(del) <= esp) return true; /// equal
    return (del > 0);
}


CIRCLE one;
CIRCLE two;

void makeCircle(POINT p1, POINT p2, double len){
  //  cout << "point 1 = " << p1.x << " " << p1.y << "\n";
  //  cout << "point 2 = " << p2.x << " " << p2.y << "\n";

    POINT tmp = POINT(Mid(p1.x,p2.x),Mid(p1.y,p2.y));

    double A = sqr(p2.y) - sqr(p1.y) + sqr(p2.x) - sqr(p1.x);
    double B = A / (-2 * p1.x + 2 * p2.x);
    double C = (2 * p1.y - 2 * p2.y) / (-2 * p1.x + 2 * p2.x);

    double D = len * len - sqr(dist(tmp, p1));

   // cout << D << "\n";

    /// pt: Ax^2 + Bx + C = 0
    double hsA = 1 + sqr(C);
    double hsB = 2 * B * C - 2 * tmp.x * C - 2 * tmp.y;
    double hsC = sqr(B) - 2 * tmp.x * B + sqr(tmp.y) + sqr(tmp.x) - D;
    //cout << hsA << " " << hsB << " " << hsC << "\n";

    /// solve
    double delTa = sqr(hsB) - 4 * hsA * hsC;
    ///
    double y1 = (-hsB - sqrt(delTa)) / (2 * hsA);
    double y2 = (-hsB + sqrt(delTa)) / (2 * hsA);
    double x1 = B + C * y1;
    double x2 = B + C * y2;

  //  cout << "first cir = " << x1 << " " << y1 << "\n";
   // cout << "second cir = " << x2 << " " << y2 << "\n";

   // cout << dist(p1, POINT(x1, y1)) << "\n";
   // cout << dist(p2, POINT(x1, y1)) << "\n";

    one.o = POINT(x1, y1);
    two.o = POINT(x2, y2);
    one.r = len;
    two.r = len;
}

int n, m;

vector <pp> mtp;

bool check(double len) {

    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(dist(p[i], p[j]) > 2.0 * len) continue;

                makeCircle(p[i], p[j], len);

                int dem1 = 0;
                int dem2 = 0;

                for(int k = 0 ; k < n ; k++) {
                    if (incir(p[k], one)) dem1++;
                    if (incir(p[k], two)) dem2++;
                }

               // cout << dem1 << "\n";
               // cout << dem2 << "\n";

                if (dem1 >= m) return true;
                if (dem2 >= m) return true;
            }
        }
    return false;
}

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;


    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mtp.pb(mp(i, j));

    double l = 0;
    double r = 2000;

    double ret = 0;
    for (int i = 1; i <= 18; i++) {

        double mid = (l + r) / 2;

        if (check(mid)) {
            ret = mid;
           // cout << mid << "\n";
            r = mid;
        }
        else {
            l = mid;
           // cout << "can not " << mid << "\n";
         //   cout << check(mid) << "\n";
          //  break;
        }
    }


   // cout << check(3.90626) << "\n";

   // cout << "final ret = " << ret << "\n";
    printf("%.6lf", ret);

    /**/ return 0;
}
