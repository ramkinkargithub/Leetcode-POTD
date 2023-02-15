/*
The array-form of an integer num is an array representing its digits in left to right order.

    For example, for num = 1321, the array form is [1,3,2,1].

Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

Constraints:

    1 <= num.length <= 104
    0 <= num[i] <= 9
    num does not contain any leading zeros except for the zero itself.
    1 <= k <= 104


*/class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int i=0;
        while(k>0 && i<num.size()){
            k+=num[i];
            num[i]=k%10;
            k/=10;
            i++;
        }
        while(k>0){
            num.push_back(k%10);
            k/=10;
        }
        reverse(num.begin(),num.end());
        return num;
    }
};
