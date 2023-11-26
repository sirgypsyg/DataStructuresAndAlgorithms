#include <iostream>
#include <string>

class Queue{
    private:
        char *tab;
        int head, tail;
        int size;
    public:
        Queue(){
            head = tail = 0;
            size = 100;
            tab = new char[size];
        }

        bool empty(){
            return head == tail ? true : false;
        }

        char front(){
            return tab[head];
        }

        void pop(){
            head = (head+1)%size;
        }

        void push(char element){
            tab[tail] = element;
            tail = (tail+1) % size;
            if (head == tail)
            {
                int i = 0;
                char *temp_tab = new char[2 * size];
                do
                {
                    temp_tab[i] = tab[head];
                    head = (head + 1)% size;
                    ++i;
                } while (head != tail);
                
                delete[] tab;
                tab = temp_tab;
                head = 0;
                tail = size;
                size *= 2;                
            }
        }

        void clear(){
            head = tail = 0;
        }
};

class CStack {
private:
    char *tab;
    int head;
    int size;

public:
    CStack() {
        head = 0;
        size = 100;
        tab = new char[size];
    }

    ~CStack() {
        delete[] tab;
    }

    bool empty() {
        return head == 0;
    }

    double top() {
        return tab[head - 1];
    }

    void pop() {
        if (!empty()) {
            --head;
        }
    }

    void push(double element) {
        tab[head] = element;
        ++head;
        if (head == size) {
            int newSize = 2 * size;
            char *temp_tab = new char[newSize];
            for (int i = 0; i < size; ++i) {
                temp_tab[i] = tab[i];
            }

            delete[] tab;
            tab = temp_tab;
            size = newSize;
        }
    }
};

class DStack {
private:
    double *tab;
    int head;
    int size;

public:
    DStack() {
        head = 0;
        size = 100;
        tab = new double[size];
    }

    ~DStack() {
        delete[] tab;
    }

    bool empty() {
        return head == 0;
    }

    double top() {
        return tab[head - 1];
    }

    void pop() {
        if (!empty()) {
            --head;
        }
    }

    void push(double element) {
        tab[head] = element;
        ++head;
        if (head == size) {
            int newSize = 2 * size;
            double *temp_tab = new double[newSize];
            for (int i = 0; i < size; ++i) {
                temp_tab[i] = tab[i];
            }

            delete[] tab;
            tab = temp_tab;
            size = newSize;
        }
    }
};


bool toRPN(std::string string, Queue &que) {
    CStack stack;
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
        else if (e == ']' ){
            while (!stack.empty() && stack.top() != '[')
            {
                que.push(stack.top());
                stack.pop();
            }
            if (stack.empty() || stack.top() != '['){
                return false;
            }
            stack.pop();
        }
        else if (e == '}' ){
            while (!stack.empty() && stack.top() != '{')
            {
                que.push(stack.top());
                stack.pop();
            }
            if (stack.empty() || stack.top() != '{'){
                return false;
            }
            stack.pop();
        }
        else if (e == ')' ){
            while (!stack.empty() && stack.top() != '(')
            {
                que.push(stack.top());
                stack.pop();
            }
            if (stack.empty() || stack.top() != '('){
                return false;
            }
            stack.pop();
        }else if (e == '+' || e == '-') {
            while (!stack.empty() && stack.top() != '[' && stack.top() != '{' && stack.top() != '(') {
                que.push(stack.top());
                stack.pop();
            }
            stack.push(e);
        }else if (e == '*' || e == '/') {
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

double rpnToDouble(Queue que) {
    DStack stack;

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
    std::string s;
    Queue que;

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, s);
        if(toRPN(s,que))
            std::cout << rpnToDouble(que);
        else
            std::cout << "BLAD";
        std::cout << std::endl;
        que.clear();
    }

    return 0;
}