#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;

int a[N];
int per[N];
int rk[N];
int tree[4 * N];
int tag[4 * N];
int n;
template class vector<int>;

int ls(int p)
{
	return p * 2;
}
int rs(int p)
{
	return p * 2 + 1;
}
void push_up(int p)
{
	tree[p] = tree[ls(p)] + tree[rs(p)];
}
void build(int p, int pl, int pr)
{
	tag[p] = 0;
	if (pl == pr)
	{
		tree[p] = 0;
		return;
	}
	int mid = (pl + pr) / 2;
	build(ls(p), pl, mid);
	build(rs(p), mid + 1, pr);
	push_up(p);
}
void addtag(int p, int pl, int pr, int d)
{
	tree[p] += (pr - pl + 1) * d;
	tag[p] += d;
}
void push_down(int p, int pl, int pr)
{
	if (!tag[p])
	{
		int mid = (pl + pr) / 2;
		addtag(ls(p), pl, mid, tag[p]);
		addtag(rs(p), mid + 1, pr, tag[p]);
		tag[p] = 0;
	}
}
void update(int L, int R, int p, int pl, int pr, int d)
{
	if (L <= pl && pr <= R)
	{
		addtag(p, pl, pr, d);
		return;
	}
	push_down(p, pl, pr);
	int mid = (pl + pr) / 2;
	if (L <= mid)
	{
		update(L, R, ls(p), pl, mid, d);
	}
	if (mid < R)
	{
		update(L, R, rs(p), mid + 1, pr, d);
	}
	push_up(p);
}
int query(int L, int R, int p, int pl, int pr)
{
	if (L <= pl && pr <= R)
	{
		return tree[p];
	}
	push_down(p, pl, pr);
	int res = 0;
	int mid = (pl + pr) / 2;
	if (L <= mid)
	{
		res += query(L, R, ls(p), pl, mid);
	}
	if (mid < R)
	{
		res += query(L, R, rs(p), mid + 1, pr);
	}
	return res;
}
// 查找第k小的数字
int bin(int p, int pl, int pr, int rk)
{
	int L = 0;
	int R = n + 1;
	int ans;
	while (L + 1 < R)
	{
		int M = (L + R) / 2;
		// 更改这里的query可以变成查找第k大
		if (query(M, n, 1, 1, n) < rk)
		{
			R = M;
		}
		else
		{
			L = M;
			ans = M;
		}
	}
	// ans也记得跟着上面改
	return ans - 1;
}
signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%lld", &n);
		vector<int> vc;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			vc.push_back(a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &per[i]);
		}

		// 离散化
		sort(vc.begin(), vc.end());
		vc.erase(unique(vc.begin(), vc.end()), vc.end());
		for (int i = 1; i <= n; i++)
		{
			rk[i] = lower_bound(vc.begin(), vc.end(), a[i]) - vc.begin() + 1;
		}

		build(1, 1, n);
		// 用权值排名更新线段树
		for (int i = 1; i <= n; i++)
		{
			update(rk[i], rk[i], 1, 1, n, 1);
		}
		int anscnt = 0;
		int ans = 0;
		for (int i = 1; i <= (n + 1) / 2; i++)
		{
			if (i != 1)
			{
				update(rk[per[i - 1]], rk[per[i - 1]], 1, 1, n, -1);
			}
			int temp = bin(1, 1, n, i);
			if (i * vc[temp] > ans)
			{
				anscnt = i;
				ans = i * vc[temp];
			}
		}
		printf("%lld %lld\n", ans, anscnt);
	}
	return 0;
}
