class Solution {
public:
    int totalWaviness(int num1, int num2) {
        vector<string> temp;
        int cnt=0;
        for(int i=num1;i<=num2;i++){
            string a=to_string(i);
            temp.push_back(a);
        }
        for(int j=0;j<temp.size();j++){
            string s=temp[j];
            for(int i=1;i<s.length()-1;i++){
                if(((s[i]>s[i-1]) && (s[i]>s[i+1])) || ((s[i]<s[i-1]) && (s[i]<s[i+1])))
                cnt+=1;
            }
        }
        return cnt;
    }
};