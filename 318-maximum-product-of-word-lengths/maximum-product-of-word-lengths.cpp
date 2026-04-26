class Solution {
    // bool check(string a,string b){
    //    vector<char> p(26,0);
    //    vector<char> q(26,0);
    //    for(char i:a)
    //    p[i-'a']++;

    //    for(char i:b)
    //    q[i-'a']++;

    //    for(int i=0;i<25;i++){
    //     if(p[i]!=0 && q[i]!=0)
    //     return false;
    //    }
    //    return true;
    // }
public:
    int maxProduct(vector<string>& words) {
        int maxi=0;
        vector<int> mask(words.size());
        for(int i=0;i<words.size();i++){
            for(auto &c:words[i])
            mask[i] |=1<<(c-'a');
            // int j=i+1;
            for(int j=0;j<i;j++){
                if((mask[i] & mask[j])==0){
                    int p=words[i].length()*words[j].length();
                    maxi=max(maxi,p);
                }
            }
        }
        return maxi;
    }
};