class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        a.push(x);
        size++;
    }

    // Removes the element on top of the stack.
    void pop(void) {
        for(int i = 0; i < size-1; i++){
            a.push(a.front());
            a.pop();
        }
        a.pop();
        size--;
    }

    // Get the top element.
    int top(void) {
        for(int i = 0; i < size-1; i++){
            a.push(a.front());
            a.pop();
        }
        int ret = a.front();
        a.pop(); a.push(ret);
        return ret;
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return (size==0);
    }
private:
    queue<int> a;
    int size = 0;
};