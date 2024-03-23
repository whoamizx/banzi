#include <bits/stdc++.h>
using namespace std;
#define int long long
const double pi = acos(-1.0);
const double eps = 1e-8;
const int N = 1e6 + 10;
struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
} point[N * 2];
typedef Point Vector;
int cross(Point A, Point B)
{
    return A.x * B.y - A.y * B.x;
}
bool up(Point a)
{
    return a.y >= 0 || (a.y == 0 && a.x >= 0);
}
// 极角排序//从x正半轴开始逆时针排序
bool cmp(Point a, Point b)
{
    if (up(a) != up(b))
    {
        return up(a) > up(b);
    }
    return cross(a, b) > 0;
}
// 极角排序//从y正半轴开始顺时针排序
bool right(Point a)
{
    return a.x >= 0 || (a.x == 0 && a.y >= 0);
}
bool cmp2(Point a, Point b)
{
    if (right(a) != right(b))
    {
        return right(a) > right(b);
    }
    return cross(a, b) < 0;
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &point[i].x, &point[i].y);
    }
    sort(point + 1, point + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld %lld\n", point[i].x, point[i].y);
    }
}