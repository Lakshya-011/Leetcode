class Solution {
    private:
    void solve(int i, vector<int>& arr,int n, int k,vector<vector<int>>& ans,vector<int>& temp){
      if(temp.size()==k){
        ans.push_back(temp);
        return;
      }  
      if(i>=n)
      return;
        temp.push_back(arr[i]);
        solve(i+1,arr,n,k,ans,temp);
        temp.pop_back();

        solve(i+1,arr,n,k,ans,temp);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        solve(0,arr,n,k,ans,temp);
        return ans;
    }
};