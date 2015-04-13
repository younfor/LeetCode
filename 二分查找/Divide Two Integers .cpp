/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = labs(dividend);
        long b = labs(divisor);
        long s = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (b == 0 || dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        } 
    	long ans = 0;
    	while (a >= b)
    	{
    		int i = 0;
    		while (a >= (b << i))
    		{
    			a -= b << i;
    			ans += 1 << i;
    			i++;
    		}
    	}
    	return ans*s;
    }
};