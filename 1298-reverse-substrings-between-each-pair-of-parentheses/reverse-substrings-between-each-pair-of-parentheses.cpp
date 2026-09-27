class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        for(char c:s){
            if(c=='(')
            ans.push_back(c);

            else if(c==')'){
                string temp;
                while(ans.back()!='('){
                    temp.push_back(ans.back());
                    ans.pop_back();
                }

                ans.pop_back();
                for(char p:temp)
                ans.push_back(p);
            }
            else
            ans.push_back(c);
        }
        return ans;
    }
};