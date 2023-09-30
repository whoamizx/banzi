#include <bits/stdc++.h>
using namespace std;
#define LL long long
const double pi = acos(-1.0);
const double eps = 1e-8;
const int N = 1e6 + 10;
int sgn(double x)
{
    if (fabs(x) < eps)
    {
        return 0;
    }
    else
    {
        return x < 0 ? -1 : 1;
    }
}
int dcmp()
{
    double x, y;
    if (fabs(x - y) < eps)
    {
        return 0;
    }
    else
    {
        return x < y ? -1 : 1;
    }
}
struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
} point[N * 2];
typedef Point Vector;
LL cross(Point A, Point B)
{
    return (LL)A.x * B.y - (LL)A.y * B.x;
}

bool up(Point a)
{
    return a.y >= 0 || (a.y == 0 && a.x >= 0);
}
// 极角排序
bool cmp(Point a, Point b)
{
    if (up(a) != up(b))
    {
        return up(a) > up(b);
    }
    return cross(a, b) > 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &point[i].x, &point[i].y);
        }
        if (n == 1 || n == 2)
        {
            puts("0");
            continue;
        }
        sort(point + 1, point + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
        {
            point[i + n] = point[i];
        }
        int res = n;
        for (int i = 1, j = 2; i <= n; i++)
        {
            while (j + 1 <= n + i && cross(point[i], point[j]) >= 0)
            {
                j++;
            }
            res = min(res, min(j - i, n - j + i));
        }
        printf("%d\n", res);
    }
}