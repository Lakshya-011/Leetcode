class Solution {
public:
int solve(string s1,string s2){
    int c=0;
    int i=0;
    while(i<s1.length()){
        if(s1[i]!=s2[i])
        c++;
        i++;
    }
    return c;
}
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string s:queries){
            for(string j:dictionary){
                if(solve(s,j)<=2){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};