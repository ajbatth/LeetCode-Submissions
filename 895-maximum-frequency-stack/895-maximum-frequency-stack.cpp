class FreqStack {
public:
    vector<int>v;
    unordered_map<int,int>m;
    map<int,int>freq;
    FreqStack() {
    return;
        
    }
    
    void push(int val) {
        v.push_back(val);
        m[val]++;
        freq[m[val]]++;
    }
    
    int pop() {
        int n=v.size();
       auto it=--freq.end();
        int target=it->first,ans;
        for(int i=n-1;i>=0;i--){
            if(v[i]==-1)continue;
            if(m[v[i]]==target){
                ans=v[i];
                
                m[v[i]]--;
                v[i]=-1;
                it->second--;
                if(it->second==0)freq.erase(it);
                break;
            }
        }
        
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */