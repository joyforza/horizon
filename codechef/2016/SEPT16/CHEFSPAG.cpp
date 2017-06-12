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
#define N 17
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n;

class Point {
public:
    int x, y;
    Point() {}
    Point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
};

Point poly[N];

/* bool cointans(Point test) {
    int i, j;
    bool ret = false;
    for (i = 0, j = n - 1; i < n; j = i++) {
        if ((poly[i].y > test.y) != (poly[j].y > test.y) &&
        (test.x < (poly[j].x - poly[i].x) * (test.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x)) {
          //  cout << ret << " " << !ret << "\n";
            ret = !ret;
        }
    }
    return ret;
}
*/

/*
function TestConvexPolygon(point, polygon)
  if polygon.size == 3 then
    return TestTriangle(point, polygon) // constant time

  if (TestLine(point, polygon[0], polygon[polygon.size/2]) > 0)
    return TestConvexPolygon(point, new polygon from polygon.size/2 to polygon.size-1 and 0)
  else
    return TestConvexPolygon(point, new polygon from 0 to polygon.size/2)
*/

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    n = 4;
    poly[0] = Point(1, 1);
    poly[1] = Point(3, 1);
    poly[2] = Point(3, 3);
    poly[3] = Point(1, 3);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
    if (cointans(Point(i, j))) {
        cout << i << ", " << j << endl;
    }
    /**/ return 0;
}
