<<<<<<< HEAD
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int len=num.size(),l=0,r=len-1,m;
        if(len==1)
            return num[0];
        while(l<=r)
        {
            m=(l+r)>>1;
            if( (m==len-1 || num[m]<num[m+1] ) && (m==0 ||num[m-1] >num[m] ))
                return num[m];
            if(num[m]<num[r])
                r=m-1;
            else
                l=m+1;
        }
        return num[0];
    }
=======
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int len=num.size(),l=0,r=len-1,m;
        if(len==1)
            return num[0];
        while(l<=r)
        {
            m=(l+r)>>1;
            if( (m==len-1 || num[m]<num[m+1] ) && (m==0 ||num[m-1] >num[m] ))
                return num[m];
            if(num[m]<num[r])
                r=m-1;
            else
                l=m+1;
        }
        return num[0];
    }
>>>>>>> 222e49d346a44577b6aed1dc0c4d7fd0015ac6e6
};