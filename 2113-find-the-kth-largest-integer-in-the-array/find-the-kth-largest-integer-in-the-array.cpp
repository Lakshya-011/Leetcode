class cmp{
    public:
    bool operator() (string &b, string &a){
        if(a.size()!=b.size()) return a.size()<b.size();
        return a<b;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> q;

        for(string& s:nums){
            q.push(s);
            if(q.size()>k)
            q.pop();
        }
        return q.top();
    }
};