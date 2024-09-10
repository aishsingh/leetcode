class MyStack {
private:
    vector<int> stack;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        // add val to top of stack
        stack.push_back(x);
    }
    
    int pop() {
        // get last element
        int val = top();

        // remove front element
        stack.pop_back();

        return val;
    }
    
    int top() {
        return stack.back();
    }
    
    bool empty() {
        // check if empty
        bool isEmpty = stack.empty();
        return isEmpty;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
