class Solution {
public:
    string getPermutation(int n, int k) {
        int f=1;
        vector<int> a;
        string ans="";
        for(int i=1;i<n;i++){
            f=f*i;
            a.push_back(i);
        }
        a.push_back(n);
        k--;
        while(true){
            ans+=to_string(a[k/f]);
            a.erase(a.begin()+k/f);
            if(a.size()==0)
            break;

            k=k%f;
            f=f/a.size();
        }
        return ans;
    }
};