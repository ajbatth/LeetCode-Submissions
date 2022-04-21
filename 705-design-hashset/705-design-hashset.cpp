class MyHashSet {
public:
    int size;
    vector<list<int>>v;
    MyHashSet() {
        size=1000;
        v.resize(size);
    }
    int myhash(int key){ return key%size;}
    
    auto search(int key){
        int i=myhash(key);
        return find(v[i].begin(),v[i].end(),key);
    }
    
    void add(int key) {
        int i=myhash(key);
        if(search(key)==v[i].end())
        v[i].push_back(key);
    }
    
    void remove(int key) {
        int i=myhash(key);
        auto it=search(key);
        if(it!=v[i].end())
        v[i].erase(it);
        
    }
    
    bool contains(int key) {
        int i=myhash(key);
        return search(key)!=v[i].end();
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */