class StockSpanner {
    vector<int> stock;
    vector<int> spanner;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        stock.push_back(price);
        spanner.push_back(1);
        int i = spanner.size() - 1;
        while(i >= 0){
            if(price >= stock[i]){
                i = i - spanner[i];
            }
            else{
                break;
            }
        }
        if(i < 0){
            if(spanner[stock.size() - 1] < stock.size()){
                spanner[stock.size() - 1] = stock.size();
                return stock.size();
            }
            return spanner[stock.size() - 1];
        }
        spanner[stock.size() - 1] = stock.size() - i - 1;
        return spanner[stock.size() - 1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */