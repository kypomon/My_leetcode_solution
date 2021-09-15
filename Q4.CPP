class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        stack<int> stack1;
        //两个滑动的指针
        int i = 0;
        int j = 0;
        int m = nums1.size();
        int n = nums2.size();

        //特殊情况
        if( m+n==0) return 0;
        if( m== 0 && n == 1) return nums2[0];
        if( n == 0 && m == 1) return nums1[0];

        //以下情形为m>=1,n>=1
        for(int s = 1; s <= (m+n)/2+1; s++)
        {
            if(i <= m-1 && j <= n-1 )
            {
                if( nums1[i] <= nums2[j] ) 
                {
                    stack1.push( nums1[i]);
                    i++;
                }
                else
                {
                    stack1.push( nums2[j] );
                    j++;
                }
                continue;
                   
            }
            else
                if( i>m-1 && j <= n-1)
                {
                    stack1.push( nums2[j] );
                    j++;
                }
                else
                    if(i <= m-1 && j > n-1 )
                    {
                        stack1.push( nums1[i] );
                        i++;
                    }
        }

   
        //总数为偶数
        if((m+n)%2==0) 
        {
            int a = stack1.top();
            stack1.pop();
            int b = stack1.top();
            return (a+b)/2.0;
        }
        else
            return stack1.top();


        
    }
};