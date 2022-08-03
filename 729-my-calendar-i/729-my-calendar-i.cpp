class MyCalendar {
    vector<pair<int, int>> events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(events.empty()){
            events.push_back({start, end});
            // cout << start << "~" << end << endl;
            return true;
        }
        for(auto i : events){
            if((start >= i.first && start < i.second) || (end > i.first && end <= i.second)) return false;
            if(end > i.second && start < i.first) return false;
        }
        // cout << start << "~" << end << endl;
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */