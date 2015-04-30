<<<<<<< HEAD
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
	public:
		int harfsearch(int l, int r, int target,int a[])
		{
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (target == a[mid])
					return mid;
				if (target > a[mid])
					l = mid + 1;
				else
					r = mid - 1;
			}
			return -1;
		}
		int search(int A[], int n, int target) {
			// find mid
			int i;
			for (i = 0; i < n-1; i++)
			{
				if (A[i]>A[i + 1] || A[i]==target)
					break;
			}
			if (A[i] == target) return i;
			int r = harfsearch(0, i, target,A);
			if (r != -1) return r;
			r = harfsearch(i + 1, n - 1, target,A);
			return r;
		}
=======
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
	public:
		int harfsearch(int l, int r, int target,int a[])
		{
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (target == a[mid])
					return mid;
				if (target > a[mid])
					l = mid + 1;
				else
					r = mid - 1;
			}
			return -1;
		}
		int search(int A[], int n, int target) {
			// find mid
			int i;
			for (i = 0; i < n-1; i++)
			{
				if (A[i]>A[i + 1] || A[i]==target)
					break;
			}
			if (A[i] == target) return i;
			int r = harfsearch(0, i, target,A);
			if (r != -1) return r;
			r = harfsearch(i + 1, n - 1, target,A);
			return r;
		}
>>>>>>> 222e49d346a44577b6aed1dc0c4d7fd0015ac6e6
};