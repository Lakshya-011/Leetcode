class Solution {
    private:
    int lent(int x){
        int c=0;
        while(x>0){
            c++;
            x=x/10;
        }
        return c;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
     unordered_set<int> st;
     for(int num:arr1){
        int x=num;
        while(x>0){
            st.insert(x);
            x=x/10;
        }
    }
    int ans=0;
    for(int num:arr2){
        int x=num;
        int len=lent(x);
        while(x>0){
            if(st.count(x)){
                ans=max(ans,len);
            }
            x=x/10;
            len--;
        }
    }
    return ans;
    }
};