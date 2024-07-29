#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

#define MAXN 10000000

double a[MAXN], b[MAXN], c[MAXN], d[MAXN], x[MAXN];

int thrnum = 4;
int bsize;

int n;

int pnt[MAXN];

int main()
{
	memset(a, sizeof a, 0);
	memset(b, sizeof b, 0);
	memset(c, sizeof c, 0);
	memset(d, sizeof d, 0);
	
	cin >> n;
	for (int i = 2; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i < n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
		cin >> d[i];
	
	bsize = n / thrnum;
	
//	cout << "size: " << bsize << endl;
	#pragma omp parallel for schedule(static) num_threads(thrnum)
	for (int i = 1; i <= n; ++i)
	{
		if (i % bsize != 1)
		{
			double coef = a[i] / b[i - 1];
			a[i] = -a[i - 1] * coef;
			b[i] -= c[i - 1] * coef;
			d[i] -= d[i - 1] * coef;
		}
	}
	
//	cout << "hey:" << endl;
//	for (int i = 1; i <= n; ++i)
//		cout << a[i] << " ";
//	cout << endl;
//	
//	for (int i = 1; i <= n; ++i)
//		cout << b[i] << " ";
//	cout << endl;
//	for (int i = 1; i <= n; ++i)
//		cout << c[i] << " ";
//	cout << endl;
//	
//	for (int i = 1; i <= n; ++i)
//		cout << d[i] << " ";
//	cout << endl;
	
	#pragma omp parallel for schedule(static) num_threads(thrnum)
	for (int i = n; i >= 1; --i)
	{
		if ((i - 1) % bsize < (bsize - 2))
		{
//			cout << i << endl;
			double coef = c[i] / b[i + 1];
			
//			cout << "coef:" << coef << endl;
			c[i] = -c[i + 1] * coef;
			a[i] -= a[i + 1] * coef;
			d[i] -= d[i + 1] * coef;
		}
		
	}
	
	for (int i = 1; i <= thrnum; ++i)
	{
		pnt[i] = i * bsize;
	}
	pnt[thrnum] = n;
	
	for (int i = 1; i < thrnum; ++i)
	{
		double coef = c[pnt[i]] / b[pnt[i] + 1];
		c[pnt[i]] = -coef * c[pnt[i] + 1];
		b[pnt[i]] -= coef * a[pnt[i] + 1];
		d[pnt[i]] -= coef * d[pnt[i] + 1];
	}
	
	
	for (int i = 2; i <= thrnum; ++i)
	{
		double coef = a[pnt[i]] / b[pnt[i - 1]];
		b[pnt[i]] -= coef * c[pnt[i - 1]];
		d[pnt[i]] -= coef * d[pnt[i - 1]];
	}
	
	for (int i = thrnum - 1; i >= 1; --i)
	{
		double coef = c[pnt[i]] / b[pnt[i + 1]];
		d[pnt[i]] -= coef * d[pnt[i + 1]];
	}
	
	for (int i = 1; i <= thrnum; ++i)
	{
		x[pnt[i]] = d[pnt[i]] / b[pnt[i]];
	}
	
//	for (int i = 1; i <= n; ++i)
//	{
//		cout << x[i] << endl;
//	}

	#pragma omp parallel for schedule(static) num_threads(thrnum)
	for (int i = 1; i <= n; ++i)
	{
		int num = (int)((i - 1) / bsize) + 1;
		if (i % bsize != 0)
		{
			x[i] = (d[i] - a[i] * x[pnt[num - 1]] - c[i] * x[pnt[num]]) / b[i];
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		cout << "x[" << i << "]=" << x[i] << endl;
	}
	return 0;
}

/* Test data:
12
1 7 5 4 9 7 7 4 9 3 3
2 2 4 4 3 1 5 8 9 10 2 4
6 2 8 2 11 7 5 7 3 1 5
1 2 3 4 5 6 7 8 9 10 11 12
*/
