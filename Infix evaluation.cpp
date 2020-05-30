#include <bits/stdc++.h>
using namespace std;
int priority(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}
int eval(int a, int b, char ch){
    if(ch == '+'){
        return a+b;
    }
    if(ch == '-'){
        return a-b;
    }
    if(ch == '/'){
        return a/b;
    }
    if(ch == '*'){
        return a*b;
    }
    return 0;
}
int func(string input){
    stack<int> operand;
    stack<char> operators;
    int n = input.length();
    for(int i = 0; i < n; i++){
        if(input[i] == '('){
            operators.push(input[i]);
        }
        else if(isdigit(input[i])){
            operand.push(input[i] - '0');
        }
        
        else if(input[i] == ')'){
            while(!operators.empty() && operators.top() != '('){
                
                int oper1 = operand.top();
                operand.pop();
                int oper2 = operand.top();
                operand.pop();
                char op = operators.top();
                operators.pop();
                
                int ans = eval(oper2, oper1, op);
                operand.push(ans);
            }
            if(!operators.empty()){
                operators.pop();
            }
        }
        else{
            while(!operators.empty() && priority(operators.top()) >= priority(input[i])){
                
                int oper1 = operand.top();
                operand.pop();
                int oper2 = operand.top();
                operand.pop();
                char op = operators.top();
                operators.pop();
                int ans = eval(oper2, oper1, op);
                operand.push(ans);
            }
            operators.push(input[i]);
        }
    }
    while(!operators.empty()){
        
                int oper1 = operand.top();
                operand.pop();
                int oper2 = operand.top();
                operand.pop();
                char op = operators.top();
                operators.pop();
                int ans = eval(oper2, oper1, op);
                operand.push(ans);
    }
    return operand.top();
}
int main(){
    
    string input = "2+3*1-((3+4*1)+(2*3))";
    cout << func(input) << endl;
    return 0;
}
