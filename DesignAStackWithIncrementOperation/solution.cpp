class CustomStack {
private:
    const int m_maxSize;
    vector<int> m_stack;

public:
    CustomStack(int maxSize) : m_maxSize(maxSize)
    {
        
    }
    
    void push(int x) 
    {
        if (m_stack.size() < m_maxSize)
        {
            // add element to top of stack (back of vector)
            m_stack.push_back(x);
        }
    }
    
    int pop() 
    {
        int val = -1;   // -1 means stack is empty

        if (! m_stack.empty())
        {
            val = m_stack.back();

            // remove top element in stack (back of vector)
            m_stack.pop_back();
        }

        return val;
    }
    
    void increment(int k, int val) 
    {
        // increment k elements from the bottom of the stack (start of the vector) by val
        for (int i=0; i<min(k, (int)m_stack.size()); i++)
        {
            m_stack.at(i) += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
