class StockPrice {
private:
    unordered_map<int, int> price_ts;
    multiset<int> st;
    int max_time = 0;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(price_ts.find(timestamp) != price_ts.end()){
            auto it = st.find(price_ts[timestamp]);
            st.erase(it);
        }
        price_ts[timestamp] = price;
        st.insert(price);
        max_time = max(max_time, timestamp);
    }
    
    int current() {
        return price_ts[max_time];
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
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