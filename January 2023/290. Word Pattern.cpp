/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

*/

class Solution {
public:
    string nextPart(string s,int &index){
        string temp="";
        for(;index<s.size() && s[index]!=' ';index++){
            temp+=s[index];
        }
        cout<<index<<" "<<temp<<endl;
        index++;
        return temp;
    }
    bool wordPattern(string pattern, string s) {
        int index=0,i=0;
        unordered_map<char,string>m;
        unordered_set<string>store;
        for(;i<pattern.size() && index<s.size() ;i++){
            string curr=nextPart(s,index);
            cout<<"word "<<i+1<<" "<<pattern[i]<<" "<<curr<<endl;
            if(m.find(pattern[i])==m.end()){
                if(store.find(curr)!=store.end())
                    return false;
                m[pattern[i]]=curr;
                cout<<"   new word pair added as "<<pattern[i]<<":"<<curr<<endl;
                store.insert(curr);
                continue;
            }
            else if(m[pattern[i]]!=curr)
                return false;
        }
        if(i<pattern.size() || index<s.size())
            return false;
        return true;
    }
};
