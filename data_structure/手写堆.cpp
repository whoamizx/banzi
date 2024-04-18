// 小根堆
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int heap[N];
int len = 0;
void push(int x)
{
    heap[++len] = x;
    int i = len;
    // 与父亲比较,小于就上升
    while (i > 1 && heap[i] < heap[i / 2])
    {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}
void pop()
{
    heap[1] = heap[len--];
    int i = 1;
    //  至少有左儿子
    while (i * 2 <= len)
    {
        // 左儿子
        int son = 2 * i;
        // 有右儿子,并且右儿子小
        if (son < len && heap[son + 1] < heap[son])
        {
            son++;
        }
        // 与较小的儿子交换
        // 否则比较小的儿子还小就已经结束了
        if (heap[son] < heap[i])
        {
            swap(heap[son], heap[i]);
            i = son;
        }
        else
        {
            break;
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
    }
    return 0;
}
