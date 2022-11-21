class MinStack {
public:
    
    vector<pair<int,int>>ans;
    // stack<int>s;
    MinStack() {
        
    }
    
    void push(int val){
        if(!ans.empty()){
            ans.push_back({val,min(val,ans.back().second)});
        }
       else{
           ans.push_back({val,val});
       }
    }
    
    void pop() {
        ans.pop_back();
    }
    
    int top()
    {
        return ans.back().first;
    }
    
    int getMin(){
       return ans.back().second;
       }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */