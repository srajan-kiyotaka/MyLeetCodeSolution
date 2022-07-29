/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    queue<int> flatten;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto i : nestedList){
            help(i);
        }
    }
    
    int next() {
        int temp = flatten.front();
        flatten.pop();
        return temp;
    }
    
    bool hasNext(){
        if(flatten.empty()) return false;
        return true;
    }
    
    void help(NestedInteger value){
        if(value.isInteger()){
            flatten.push(value.getInteger());
        }
        else{
            for(auto i : value.getList()){
                help(i);
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */