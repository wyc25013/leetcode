class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        a.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!a.empty()){
            int at = a.top();
            tmp.push(at);
            a.pop();
        }
        tmp.pop();
        while(!tmp.empty()){
            int tt = tmp.top();
            a.push(tt);
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        while(!a.empty()){
            int at = a.top();
            tmp.push(at);
            a.pop();
        }
        int ret = tmp.top();
        while(!tmp.empty()){
            int tt = tmp.top();
            a.push(tt);
            tmp.pop();
        }
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return a.empty();   
    }
private:
    stack<int> a;
    stack<int> tmp;
};