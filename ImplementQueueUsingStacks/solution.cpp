class MyQueue {
private:
    vector<int> stack;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // add val to top of stack
        stack.push_back(x);
    }
    
    int pop() {
        // get last element
        int val = peek();

        // remove front element
        stack.erase(stack.begin());

        return val;
    }
    
    int peek() {
        return stack.front();
    }
    
    bool empty() {
        // check if empty
        bool isEmpty = stack.empty();
        return isEmpty;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
