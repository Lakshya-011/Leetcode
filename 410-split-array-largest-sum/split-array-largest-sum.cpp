class Solution {
    private:
    int solve(vector<int>& nums,int mid){
        int temp=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<= mid){
                sum+=nums[i];
            }
            else{
                temp++;
                sum=nums[i];
            }
        }
        return temp;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return -1;
        int l=*max_element(nums.begin(),nums.end());
        int h= accumulate(nums.begin(),nums.end(),0);
        while(l<=h){
            int mid= l+(h-l)/2;

            if(solve(nums,mid)>k){
                l=mid+1;
            }
            else
            h=mid-1;
        }
        return l;
    }
};