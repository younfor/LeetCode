<<<<<<< HEAD
class Solution {
public:
    double pow(double x, int n) {
    	double r = 1;
    	if(n<0)
    	{
    	    x=1.0/x;
    	    n=-n;
    	}    
    	while (n>0)
    	{
    		int i = 1;
    		double y = x;
    		while (n>=i)
    		{
    			r *= y;
    			y *= y;
    			n -= i;
    			i <<= 1;
    			
    		}
    	}
    	return r;
    }
=======
class Solution {
public:
    double pow(double x, int n) {
    	double r = 1;
    	if(n<0)
    	{
    	    x=1.0/x;
    	    n=-n;
    	}    
    	while (n>0)
    	{
    		int i = 1;
    		double y = x;
    		while (n>=i)
    		{
    			r *= y;
    			y *= y;
    			n -= i;
    			i <<= 1;
    			
    		}
    	}
    	return r;
    }
>>>>>>> 222e49d346a44577b6aed1dc0c4d7fd0015ac6e6
};