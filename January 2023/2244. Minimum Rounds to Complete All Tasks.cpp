/*
You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

 

Example 1:

Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

Example 2:

Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.

 

Constraints:

    1 <= tasks.length <= 105
    1 <= tasks[i] <= 109


*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        //creating frequency collection
        for(int i=0;i<tasks.size();i++)
            m[tasks[i]]++;
        //checking whether frequency cleared by any number of rounds or not
        int count=0;
        for(auto &num:m){
            if(num.second==2||num.second==3){
                count++;
                continue;
            }
            else if(num.second==1)
                return -1;
            if(num.second%3==0){
                count+=num.second/3;
                continue;
            }
            else if(num.second%3==2){
                count+=num.second/3+1;
                continue;
            }
            else{
                // with modulo==1
                count+=num.second/3;
                count=count-1+2; //subtracting one round of 3 and 2 rounds of 2;
            }
        }
        return count;
    }
};
