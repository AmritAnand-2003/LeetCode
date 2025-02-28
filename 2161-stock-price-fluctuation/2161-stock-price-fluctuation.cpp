class StockPrice {
private:
    map<int, int> price_ts;
    multiset<int> st;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(price_ts.find(timestamp) != price_ts.end()){
            auto it = st.find(price_ts[timestamp]);
            if(it != st.end()){
                st.erase(it);
            }
        }
        price_ts[timestamp] = price;
        st.insert(price);
    }
    
    int current() {
        auto it = price_ts.end();
        it--;
        return it->second;
    }
    
    int maximum() {
        auto it = st.end();
        it--;
        return *it;
    }
    
    int minimum() {
        auto it = st.begin();
        return *it;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */