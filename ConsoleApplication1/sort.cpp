#include <iostream>

using namespace std;

template <typename T>
void swap(T a[], int m, int n)
{
	T temp = a[m];
	a[m] = a[n];
	a[n] = temp;
}

template <typename T1>
void sort_one(T1 a[], int m, int n)
{
	int p=m;
	T1 t = a[m];
	if (m > n)
		return;
	for (int i = m+1; i <= n; i++)
	{
		if (a[i] < t)
		{
			swap<T1>(a, ++p, i);
		}
	}
	swap<T1>(a, m, p);
	sort_one(a,m,p-1);
	sort_one(a, p + 1, n);
}

template <typename T2>
void sort_two(T2 a[], int m, int n)
{
	if (m > n)
		return;
	T2 t = a[m];
	int p = m,q=n+1;
	while (1)
	{
		for (p++; p <= n&&a[p] < t; p++);
		for (q--; a[q]>t; q--);
		if (p > q)
			break;
		swap<T2>(a, p, q);
	}
	swap<T2>(a, m, q);
	sort_two(a, m, q - 1);
	sort_two(a, q + 1, n);
}

template <typename T3>
void sort_three(T3 a[], int m, int n)
{
	if (m > n)
		return;
	swap<T3>(a, a[m], a[rand() % (n - m + 1) + m]);
	T3 t = a[m];
	int p = m, q = n + 1;
	while (1)
	{
		for (p++; p <= n&&a[p] < t; p++);
		for (q--; a[q]>t; q--);
		if (p > q)
			break;
		swap<T3>(a, p, q);
	}
	swap<T3>(a, m, q);
	sort_two(a, m, q - 1);
	sort_two(a, q + 1, n);
}

int main()
{
	double a[]= { 55.3, 55.2, 59.5, 26, 53, 58, 97, 93 };
	sort_three<double>(a, 0, 7);
	for (int i=0; i < 8; i++)
		cout << a[i]<<",";
	return 0;
}