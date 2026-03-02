class Solution {
    private:
    void solve(int s,vector<vector<int>> &res, vector<int> &temp, int k, int n, int sum){
        if(temp.size()==k){
            if(sum==n){
                res.push_back(temp);
            }
            return;
        }

        for(int i=s;i<=9;i++){
            if(sum+i > n)
            break;
            temp.push_back(i);
            solve(i+1,res,temp,k,n,sum+i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;

        solve(1,res,temp,k,n,0);
        return res;
    }
};