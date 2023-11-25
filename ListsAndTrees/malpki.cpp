#include <iostream>
#include <string>
#include <queue>
#include <vector>

struct Monkey
{
    std::string name;
    int numKids;
    std::vector<Monkey*> kids;
    
};

void append(Monkey *head, Monkey *mon){
    head->kids.push_back(mon);
    head->numKids-=1;
}


void preorder(Monkey *v, std::string &output){ 
    output+=v->name;
    for(size_t i=0; i <v->kids.size(); i++){
        preorder(v->kids[i], output);
    }
}

void releaseMemory(Monkey *v) {
    for (size_t i = 0; i < v->kids.size(); i++) {
        releaseMemory(v->kids[i]);
    }
    delete v;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int k;
    int n;

    std::queue<Monkey*> que;

    Monkey *head = nullptr;
    
    std::cin >> k; std::cin.ignore();

    std::string fOutput[k];
    for (int i = 0; i < k; i++)
    {
        std::cin >> n;  std::cin.ignore();
        head = new Monkey;
        std::cin >> head->name >> head->numKids;
        que.push(head);
        std::string output = "";
        for(int j = 0; j < n - 1; ++j){
            if(que.front()->numKids == 0) que.pop();

            Monkey *currHead = que.front();
            Monkey *mon = new Monkey;
            std::cin >> mon->name >> mon->numKids;
            append(currHead, mon);
            que.push(mon);
        }
        preorder(head, output);
        fOutput[i] = output;

        //clearing
        std::cin.ignore();
        releaseMemory(head);
        while(!que.empty())
            que.pop();
    }
    for(int i = 0 ; i < k; ++i){
        std::cout << fOutput[i] << "\n";
    }
    
    return 0;
}
