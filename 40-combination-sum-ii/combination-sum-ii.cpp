class Solution {
    private:
    void solve(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp,int i){
            if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1])
            continue;

            if(candidates[i]>target)
            break;
       
        temp.push_back(candidates[j]);
        solve(candidates,target-candidates[j],ans,temp,j+1);
        temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};