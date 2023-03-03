/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

class Solution {
    void sort(vector<int>& nums,int l,int r,vector<int>&temp){
        if(l<r){
            int m=l+(r-l)/2;
            sort(nums,l,m,temp);
            sort(nums,m+1,r,temp);
            merge(nums,l,m,r,temp);
        }
        return;
    }

    void merge(vector<int>&nums,int l,int m,int r,vector<int>&temp){
        int i=l,j=m+1,k=l;
        while(i<m+1 && j<=r){
            if(nums[i]<nums[j])
                temp[k++]=nums[i++];
            else
                temp[k++]=nums[j++];
        }
        while(i<m+1)
            temp[k++]=nums[i++];
        while(j<=r)
            temp[k++]=nums[j++];
        for(i=l;i<=r;i++)
            nums[i]=temp[i];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>temp(nums.size());
        sort(nums,0,nums.size()-1,temp);
        return nums;
    }
};
