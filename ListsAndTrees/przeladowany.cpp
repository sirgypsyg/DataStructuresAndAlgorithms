#include <iostream>
#include <queue>
#include <stack>

std::string infToRPN(std::string string) {
    std::stack<char> stack;
    int i = 0;
    std::string rpn;
    int size = string.size();
    
    while (i != size) {
        char e = string.at(i);

        if (isdigit(e) || isalpha(e))
            rpn += e;
        else if (e == '[' || e == '{' || e == '(')
            stack.push(e);
        else if (e == ']' || e == '}' || e == ')') {
            while (!stack.empty() && stack.top() != '[' && stack.top() != '{' && stack.top() != '(') {
                rpn += stack.top();
                stack.pop();
            }
            if (stack.empty() || stack.top() != '[' && stack.top() != '{' && stack.top() != '(')
                return "BLAD";
            stack.pop();
        } else if (e == '+' || e == '-') {
            if (i < size - 1)
            {
                char e1 = string.at(i+1);
                if (e1 == '+' || e1 == '-' || e1 == '/' || e1 == '*')
                    return "BLAD";
            }
            while (!stack.empty() && stack.top() != '[' && stack.top() != '{' && stack.top() != '(') {
                rpn += stack.top();
                stack.pop();
            }
            stack.push(e);
        } else if (e == '*' || e == '/') {
            if (i < size - 1)
            {
                char e1 = string.at(i+1);
                if (e1 == '+' || e1 == '-' || e1 == '/' || e1 == '*')
                    return "BLAD";
            }
            
            while (!stack.empty() && (stack.top() == '+' || stack.top() == '-' ||stack.top() == '*' || stack.top() == '/')) {
                rpn += stack.top();
                stack.pop();
            }
            stack.push(e);
        }
        ++i;
    }

    while (!stack.empty()) {
        if (stack.top() == '[' || stack.top() == '{' || stack.top() == '(')
        {
            return "BLAD";
        }
        
        rpn += stack.top();
        stack.pop();
    }

    return rpn;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string string, rpn;
    std::string output[n];

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, string);
        output[i] = infToRPN(string);
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << i << " " << output[i] << "\n";
    }

    return 0;
}
