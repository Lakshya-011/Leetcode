class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int idx=-1;
        int size=s.length();
        for(int i=size-2;i>=0;i--){
            if(s[i]<s[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1)
        return -1;

        for(int i=size-1;i>idx;i--){
            if(s[i]>s[idx]){
                swap(s[i],s[idx]);
                break;
            }
        }
        sort(s.begin()+idx+1,s.end());
        long long ans= stoll(s);
        return ans>INT_MAX? -1:ans;
    }
};