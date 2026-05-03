class Solution {
public:
    bool rotateString(string s, string goal) {
        string r=s+s;
        if(s.length()!=goal.length())
        return false;
        if(r.find(goal)!=string::npos)
        return true;
        else
        return false;
    }
};