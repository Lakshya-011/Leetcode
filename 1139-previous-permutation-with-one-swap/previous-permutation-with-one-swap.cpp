class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int idx=-1;
        int n=arr.size();
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1)
        return arr;

        for(int i=n-1;i>=0;i--){
            if(arr[i]<arr[idx]){
                while(i>idx+1 && arr[i]==arr[i-1])
                i--;

                swap(arr[i],arr[idx]);
                break;
            }
        }
        return arr;
    }
};