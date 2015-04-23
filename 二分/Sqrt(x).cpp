<<<<<<< HEAD
/*
Implement int sqrt(int x).

Compute and return the square root of x.

*/

class Solution {
public:
    int sqrt(int x) {
        if(x<=1) return x;
        int l = 1, r = x;
    	while (l <= r)
    	{
    		int mid = (l + r) >> 1;
    		if ( mid == x/mid) return mid;
    		if (mid > x/mid) 
    			r = mid - 1;
    		else
    			l = mid + 1;
    	}
    	return r;
    }
=======
/*
Implement int sqrt(int x).

Compute and return the square root of x.

*/

class Solution {
public:
    int sqrt(int x) {
        if(x<=1) return x;
        int l = 1, r = x;
    	while (l <= r)
    	{
    		int mid = (l + r) >> 1;
    		if ( mid == x/mid) return mid;
    		if (mid > x/mid) 
    			r = mid - 1;
    		else
    			l = mid + 1;
    	}
    	return r;
    }
>>>>>>> 222e49d346a44577b6aed1dc0c4d7fd0015ac6e6
};