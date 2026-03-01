class Solution {
public:
    int minPartitions(string n) {
       int maxi=0;
       int i=0;
       while(i<(int)n.length()){
        int temp= n[i]-'0';
        if(temp>maxi)
        maxi=temp;

        i++;
       } 
       return maxi;
    }
};