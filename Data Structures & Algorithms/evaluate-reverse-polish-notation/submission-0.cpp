class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                char op =  tokens[i][0];
                int operand2 = st.top(); st.pop();
                int operand1 = st.top(); st.pop();
                int result;
                switch(op){
                    case '+' : 
                    st.push(operand1 + operand2);
                    break;
                    case '-' : 
                    st.push(operand1 - operand2);
                    break;
                    case '*' : 
                    st.push(operand1 * operand2);
                    break;
                    case '/' : 
                    if(operand2 != 0){
                        st.push(operand1 / operand2);
                    }
                    else{
                        return -1;
                    }
                    break;
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }            
        }
        return st.top();
    }
};
