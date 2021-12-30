/*https://leetcode.com/problems/longest-valid-parentheses/*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> stIndex;
        stIndex.push(-1);
        for(int i=0; i< s.size(); i++){
            if(st.empty()){
                stIndex.push(i);
               st.push(s[i]) ;
                continue;
            }
            if(s[i]==')'&& st.top()=='('){
                st.pop();
                stIndex.pop();
                continue;
            }
            stIndex.push(i);
            st.push(s[i]);
        }
        if(st.empty())return s.size();
        int maxDiff=INT_MIN , start, end=s.size()-1;
        while(!stIndex.empty()){
            start= stIndex.top();
            int diff= end-start;
            maxDiff= max(maxDiff,diff );
            end=start-1;
            stIndex.pop();
        }
        return maxDiff;
        
        
    }
};
