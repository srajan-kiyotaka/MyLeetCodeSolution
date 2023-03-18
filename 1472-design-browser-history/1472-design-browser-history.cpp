class DoublyLinkedList {
    public:
        string url;
        DoublyLinkedList* next;
        DoublyLinkedList* back;

    DoublyLinkedList(){
        url = "";
        next = NULL;
        back = NULL;
    }

    DoublyLinkedList(string x){
        url = x;
        next = NULL;
        back = NULL;
    }
};

class BrowserHistory {
private:
    DoublyLinkedList* home = new DoublyLinkedList;
    DoublyLinkedList* currPage = home;
public:
    BrowserHistory(string homepage) {
        home->url = homepage;
    }
    
    void visit(string url) {
        if(currPage->next == NULL){
            DoublyLinkedList* page = new DoublyLinkedList(url);
            currPage->next = page;
            page->back = currPage;
            currPage = page;
        }
        else{
            DoublyLinkedList* forward = currPage->next;
            // Clear forward history
            while(forward != NULL){
                DoublyLinkedList* temp = forward;
                forward = forward->next;
                delete temp;
            }
            forward = new DoublyLinkedList(url);
            currPage->next = forward;
            forward->back = currPage;
            currPage = forward;
        }
    }
    
    string back(int steps) {
        for(int i = 0; i < steps; i++){
            if(currPage->back == NULL){
                return currPage->url;
            }
            currPage = currPage->back;
        }
        return currPage->url;
    }
    
    string forward(int steps) {
        for(int i = 0; i < steps; i++){
            if(currPage->next == NULL){
                return currPage->url;
            }
            currPage = currPage->next;
        }
        return currPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */