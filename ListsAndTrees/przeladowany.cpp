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
    std::string rpn;
    int size = string.size();
    
    while (i != size) {
        char e = string.at(i);

        if (isdigit(e) || isalpha(e))
            que.push(e);
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
    for (int i = 0; i < n; i++)
    {
        if (que[i].empty())
        {
            std::cout << i << " " << "BLAD" << "\n";
            continue;;
        }
        else{
            while (!que[i].empty())
            {
                std::cout << i << " " << que[i].pop();
            }
        }
        
        std::cout << "\n";
    }
    

    return 0;
}
