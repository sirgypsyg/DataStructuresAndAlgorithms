#include <string>
#include <iostream>

using namespace std;

struct Actor {
    string name;
    long int fans;
    Actor* next;
};

void append(Actor* &head, string actorName, long int actorFans) {
    Actor* newActor = new Actor;
    newActor->name = actorName;
    newActor->fans = actorFans;    
    newActor->next = nullptr;

    if (head == nullptr) {
        head = newActor;
        cout << "TAK" << endl;
        return;
    }

    Actor* current = head;
    Actor* prev = nullptr;

    while (current != nullptr) {
        if (actorFans == current->fans){
            if (actorName == current->name){
                delete newActor;
                cout << "NIE" << endl;
                return;
            }
            else if (actorName < current->name){
            if (prev == nullptr) {                        
                newActor->next = current;     
                head = newActor;                
            } else {                         
                newActor->next = current;   
                prev->next = newActor;
            }
            cout << "TAK" << endl;
            return;
            }   
        }
        prev = current;
        current = current->next;
    }
    prev->next = newActor;
    cout << "TAK" << endl;
}


void findActor(Actor* &head, long int fansToLose){

    Actor* current = head;
    Actor* previous = nullptr;

    Actor *curMAX = nullptr;
    Actor *prevMAX = nullptr;
    bool found = false;
    
        
    while (current != nullptr){ 
        if (current->fans <= fansToLose){
            if (curMAX == nullptr || current->fans > curMAX->fans || (current->fans == curMAX->fans && current->name < curMAX->name)) {
                curMAX = current;
                prevMAX = previous;
            }
            found = true;
        }
        previous = current;
        current = current->next;
    }
    if (found){
        if (prevMAX == nullptr){
            cout << curMAX->name << endl;
            head = curMAX->next;
        }
        else{
            cout << curMAX->name << endl;
            prevMAX->next = curMAX->next;
        }
        
    }else{
        cout << "NIE" << endl;
    }
}     

void displayList(Actor* head) {
    Actor* current = head;
    while (current != nullptr) {
        cout << current->name << " " << current->fans << "\n";
        current = current->next;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string n;
    int nValue;
    getline(std::cin, n);
    nValue = stoi(n);

    Actor* head = nullptr;

    for (int i = 0; i < nValue; i++) {
        string op;
        int opValue;
        getline(cin, op);
        opValue = stoi(op);
        switch (opValue) {
        case 1:
            {
                string actorName;
                getline(cin, actorName);
                string actorFans;
                getline(cin, actorFans);
                append(head, actorName, stoi(actorFans));
            }
            break;
        case 2:
            {
                string fansToLose;
                getline(cin, fansToLose);
                findActor(head, stoi(fansToLose));
                break;
            }
        }
       
    }

    //displayList(head);

    Actor* current = head;
    while (current != nullptr) {
        Actor* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}