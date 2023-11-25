#include <string>
#include <iostream>
#include <cmath>

using namespace std;

struct person
{
    long x;
    string name;
};

void insertSort(person arr[], long n)
{
    int i, j;
    person key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && (arr[j].x < key.x || (arr[j].x == key.x && arr[j].name > key.name))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void recruitingTime(person arr[], long n, long p, string &output){
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += 1 + arr[i].x * i;       
        if (i < p){
            output+= arr[i].name + " ";
        }
            
    }
    output += "\n" + to_string(sum % 1000003) + "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long t, n, p;
    cin >> t; cin.ignore();
    string output;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> p; cin.ignore();
        person people[n];
        for (int j = 0; j < n; j++)
            cin >> people[j].name >> people[j].x; cin.ignore();
        insertSort(people, n);
        recruitingTime(people, n, p, output);
    }
    std::cout << output;


    return 0;
}