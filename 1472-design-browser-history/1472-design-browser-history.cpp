class BrowserHistory {
public:
    int pos = 0;
    vector<string> b;
    BrowserHistory(string homepage) {
        b.push_back(homepage);
    }
    
    void visit(string url) {
        pos++;
        if(pos<=b.size()-1){
            b[pos] = url;
            b.resize(pos+1);
        }
        else
            b.push_back(url);
    }
    
    string back(int steps) {
        pos -= steps;
        if(pos<0)
            pos = 0;
        return b[pos];
    }
    
    string forward(int steps) {
        pos += steps;
        if(pos>b.size()-1)
            pos = b.size()-1;
        return b[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */