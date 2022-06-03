class RandomizedCollection {
private:
    vector<pair<int,int>>v;
    unordered_map<int,vector<int>>mp;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans=mp.find(val)==mp.end();
        
        mp[val].push_back(v.size());
        v.push_back({val,mp[val].size()-1});
        
        return ans;
    }
    
    bool remove(int val) {
        bool ans=mp.find(val)!=mp.end();
        
        if(ans) {
            pair<int,int> p=v.back();
            mp[p.first][p.second]=mp[val].back();
            v[mp[val].back()]=p;
            mp[val].pop_back();
            v.pop_back();
            if(mp[val].size()==0)mp.erase(val);
        }
        
        return ans;
    }
    
    int getRandom() {
        return v[rand()%v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */