#include<bits/stdc++.h>
using namespace std;

class ST {
	vector<int>seg , lazy;
public:
	ST(int n )
	{
		seg.resize(4 * n);
		lazy.resize(4 * n);
	}
public:
	void build(int ind , int low , int high , int arr[])
	{
		if (low == high)
		{
			seg[ind] = arr[low];
			return;

		}
		int mid = (high + low) >> 1;
		build(2 * ind + 1 , low , mid , arr);
		build(2 * ind + 2, mid + 1 , high , arr);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
public:
	void update(int ind , int low , int high , int l , int r , int val)
	{
		// update the previous remaining updates and propogate downwards
		if (lazy[ind] != 0)
		{
			seg[ind] += (high - low + 1) * lazy[ind];
			// propogate the lazy update downwards for the remaining nodes to get updated
			if (low != high)
			{
				lazy[2 * ind + 1] += lazy[ind];
				lazy[2 * ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}
		// no overlap -> dont do anything and return
		if (low > r || high < l) return;

		// complete overlap -> low >= l && high <= r
		if (low >= l && high <= r)
		{
			seg[ind] += (high - low + 1) * val;
			// if not a leaf node then it will have children
			if (low != high)
			{
				lazy[2 * ind + 1] += val;
				lazy[2 * ind + 2] += val;
			}
			return ;
		}
		// Partial Overlap
		int mid = (low + high) >> 1;
		update(2 * ind + 1 , low , mid , l , r , val);
		update(2 * ind + 2 , mid + 1 , high , l , r , val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];

	}
public:
	int query(int ind , int low, int high , int l , int r)
	{
		if (lazy[ind] != 0)
		{
			seg[ind] += (high - low + 1) * lazy[ind];
			if (low != high)
			{
				lazy[2 * ind + 1] += lazy[ind];
				lazy[2 * ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}
		if (low > r || high < l) return 0;

		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(ind , low , mid , l , r);
		int right = query(ind , mid + 1 , high , l , r);
		seg[ind] = left + right;

	}
};
