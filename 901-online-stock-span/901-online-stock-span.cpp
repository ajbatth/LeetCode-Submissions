class StockSpanner {
public:
    stack<int>sk;
    vector<int>v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(sk.empty()){
            sk.push(v.size());
            v.push_back(price);
            return sk.top()+1;
        }
        while( !sk.empty() && v[sk.top()]<=price ){
            sk.pop();
        }
        int ans=v.size()-(sk.empty()?-1:sk.top());
        sk.push(v.size());
        v.push_back(price);
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */