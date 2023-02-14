/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

 

Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.


*/
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1,j=b.size()-1,sum=0;
        while(i>=0 && j>=0){
            if(a[i]=='1')
                sum++;
            if(b[j]=='1')
                sum++;
            ans=to_string(sum%2)+ans;
            sum/=2;
            i--;
            j--;
        }
        while(i>=0){
            if(a[i]=='1')
                sum++;
            ans=to_string(sum%2)+ans;
            sum/=2;
            i--;
        }
        while(j>=0){
            if(b[j]=='1')
                sum++;
            ans=to_string(sum%2)+ans;
            sum/=2;
            j--;
        }
        while(sum>0){
            ans=to_string(sum%2)+ans;
            sum/=2;
        }
        return ans;
    }
};
