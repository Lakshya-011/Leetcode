class MinStack {
public:
    int *arr;
    int *temp;
    int idx=-1;
    MinStack() {
        arr= new int[100000];
        temp= new int[100000];
    }
    
    void push(int value) {
        if(idx<100000){
            idx++;
            arr[idx]=value;
        }
        if(idx==0)
        temp[idx]=value;
        else
        temp[idx]=min(value,temp[idx-1]);
    }
    
    void pop() {
        if(idx>=0)
        idx--;
    }
    
    int top() {
        if(idx>=0)
        return arr[idx];
        return -1;
    }
    
    int getMin() {
        if(idx>=0)
        return temp[idx];
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */