class RandomizedSet {
public:
    vector<int> a;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            a.push_back(val);
            mp[val]=a.size()-1;
            return true;
        }
        else
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
           int last=a.back();
           a[mp[val]]=last;
           mp[last]=mp[val];
           a.pop_back();
           mp.erase(val); 
            return true;
        }
        else
        return false;
    }
    
    int getRandom() {
        int idx=rand()%a.size();
        return a[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */