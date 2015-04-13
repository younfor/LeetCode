/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
    int min(int a, int b)
    {
    	return a < b ? a : b;
    }
    int s(vector<int> &num, int l, int r)
    {
    	if (l>r)
    		return INT_MAX;
    	if (l == r)
    		return num[l];
    	int mid = (l + r) >> 1;
    	if (num[mid] < num[r])
    		return min(num[mid], s(num, l, mid - 1));
    	else if (num[mid] > num[r])
    		return s(num, mid + 1, r);
    	else
    		return s(num, l, r - 1);
    	
    }
    int findMin(vector<int> &num) {
    	int len = num.size();
    	return s(num, 0, len - 1);
    }
};