#include <iostream>
#include <queue>

template <typename T>
class Stack {
private:
    T* elements;    // Tablica dynamiczna do przechowywania elementów
    size_t capacity; // Pojemność tablicy
    size_t size;     // Aktualny rozmiar stosu

public:
    Stack() : capacity(10), size(0) {
        elements = new T[capacity];
    }

    ~Stack() {
        delete[] elements;
    }

    void push(const T& value) {
        if (size == capacity) {
            // Jeżeli stos jest pełny, zwiększ pojemność
            resize();
        }
        elements[size++] = value;
    }

    void pop() {
        if (!empty()) {
            --size;
        }
    }

    T top() const {
        if (!empty()) {
            return elements[size - 1];
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }

    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

private:
    void resize() {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
};


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

        ~Queue(){
            delete[]tab;
        }

        bool empty(){
            return head == tail ? true : false;
        }

        char pop(){
            char temp = tab[head];
            head = (head+1)%size;
            return temp;
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


void infToRPN(std::string string, Queue &que) {
    Stack<char> stack;
    int i = 0;
    int size = string.size();
    
    while (i != size) {
        char e = string.at(i);

        if (isdigit(e)){
            que.push(e);
            if (i < size - 1)
            {
                while (isdigit(string.at(i+1)))
                {
                    que.push(string.at(i+1));
                    ++i;
                }    
            }
            que.push(';');
        }
            
        else if (e == '[' || e == '{' || e == '(')
            stack.push(e);
        else if (e == ']' || e == '}' || e == ')') {
            while (!stack.empty() && stack.top() != '[' && stack.top() != '{' && stack.top() != '(') {
                que.push(stack.top());
                stack.pop();
            }
            if (stack.empty() || stack.top() != '[' && stack.top() != '{' && stack.top() != '('){
                que.clear();
                return;
            }
            stack.pop();
        } else if (e == '+' || e == '-') {
            if (i < size - 1)
            {
                char e1 = string.at(i+1);
                if (e1 == '+' || e1 == '-' || e1 == '/' || e1 == '*'){
                    que.clear();
                    return;
                }
            }
            while (!stack.empty() && stack.top() != '[' && stack.top() != '{' && stack.top() != '(') {
                que.push(stack.top());
                stack.pop();
            }
            stack.push(e);
        } else if (e == '*' || e == '/') {
            if (i < size - 1)
            {
                char e1 = string.at(i+1);
                if (e1 == '+' || e1 == '-' || e1 == '/' || e1 == '*'){
                    que.clear();
                    return;
                }
            }
            
            while (!stack.empty() && (stack.top() == '+' || stack.top() == '-' ||stack.top() == '*' || stack.top() == '/')) {
                que.push(stack.top());
                stack.pop();
            }
            stack.push(e);
        }
        ++i;
    }

    while (!stack.empty()) {
        if (stack.top() == '[' || stack.top() == '{' || stack.top() == '(')
        {
            que.clear();
            return;
        }
        
        que.push(stack.top());
        stack.pop();
    }
}

double RPNToInt(Queue que) {
    Stack<double> stack;

    while (!que.empty()) {
        char e = que.pop();

        if (isdigit(e)) {
            std::string a;
            a += e;
            char e1;
            while (1) {
                e1 = que.pop();
                if (isdigit(e1))
                    a += e1;
                else
                    break;
            }
            double numericValue = std::stod(a);  // Convert the string to a numeric value
            stack.push(numericValue);
        } else {
            if (e == '+') {
                double valB = stack.top();
                stack.pop();
                double valA = stack.top();
                stack.pop();
                double result = valA + valB;
                stack.push(result);
            } else if (e == '*') {
                double valB = stack.top();
                stack.pop();
                double valA = stack.top();
                stack.pop();
                double result = valA * valB;
                stack.push(result);
            } else if (e == '/') {
                double valB = stack.top();
                stack.pop();
                double valA = stack.top();
                stack.pop();
                double result = valA / valB;  // Corrected division operation
                stack.push(result);
            } else if (e == '-') {
                double valB = stack.top();
                stack.pop();
                double valA = stack.top();
                stack.pop();
                double result = valA - valB;
                stack.push(result);
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
    std::string string, rpn;
    Queue que[n];

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, string);
        infToRPN(string,que[i]);
    }
    for (int i = 0; i < n; i++){
        if (que[i].empty()){
            std::cout << "BLAD";
        }else{
            std::cout << RPNToInt(que[i]);
        }
        std::cout << "\n";
    }

    return 0;
}

