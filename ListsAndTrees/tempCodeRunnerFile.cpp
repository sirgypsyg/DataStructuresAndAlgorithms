#include <iostream>
#include <string>
#include <queue>
#include <stack>

bool toRPN(std::string string, std::queue<char> &que) {
    std::stack<char> stack;
    int i = 0;
    int size = string.size();
    
    while (i != size) {
        char e = string[i];

        if (isdigit(e)){
            que.push(e);
            if (!isdigit(string[i+1]))
            {
                que.push(';');
            }
        }
            
        else if (e == '[' || e == '{' || e == '(')
            stack.push(e);
        else if (e == ']' || e == '}' || e == ')') {
            while (!stack.empty() && stack.top() != '[' && stack.top() != '{' && stack.top() != '(') {
                que.push(stack.top());
                stack.pop();
            }
            if (stack.empty() || stack.top() != '[' && stack.top() != '{' && stack.top() != '('){
                return false;
            }
            stack.pop();
        } else if (e == '+' || e == '-') {
            while (!stack.empty() && stack.top() != '[' && stack.top() != '{' && stack.top() != '(') {
                que.push(stack.top());
                stack.pop();
            }
            stack.push(e);
        } else if (e == '*' || e == '/') {
            while (!stack.empty() && (stack.top() == '*' || stack.top() == '/')) {
                que.push(stack.top());
                stack.pop();
            }
            stack.push(e);
        }
        ++i;
    }

    while (!stack.empty()) {
        if (stack.top() == '[' || stack.top() == '{' || stack.top() == '(')
            return false;
        
        que.push(stack.top());
        stack.pop();
    }
    return true;
}

double rpnToDouble(std::queue<char> que) {
    std::stack<double> stack;

    while (!que.empty()) {
        char e = que.front();
        que.pop();

        if (isdigit(e)) {
            std::string a;
            a += e;
            char e1;
            while (1) {
                e1 = que.front();
                que.pop();
                if (isdigit(e1))
                    a += e1;
                else
                    break;
            }
            double numericValue = std::stod(a); 
            stack.push(numericValue);
        } else {
            if (e == '+') {
                double b = stack.top();
                stack.pop();
                double a = stack.top();
                stack.pop();
                stack.push(a + b);
            } else if (e == '*') {
                double b = stack.top();
                stack.pop();
                double a = stack.top();
                stack.pop();
                stack.push(a * b);
            } else if (e == '/') {
                double b = stack.top();
                stack.pop();
                double a = stack.top();
                stack.pop();
                stack.push(a / b);
            } else if (e == '-') {
                double b = stack.top();
                stack.pop();
                double a = stack.top();
                stack.pop();
                stack.push(a - b);
            }
        }
    }
    return stack.top();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string string;
    std::queue<char> que[n];
    bool cor[n];

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, string);
        cor[i] = toRPN(string,que[i]);
    }
    for (int i = 0; i < n; i++){
        if (!cor[i]){
            std::cout << "BLAD";
        }else{
            std::cout << rpnToDouble(que[i]);
        }
        std::cout << "\n";
    }

    return 0;
}

