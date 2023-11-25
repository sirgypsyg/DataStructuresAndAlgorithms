#include <iostream>
#include <cctype>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int alphabet_size = 26;
    int valArr[alphabet_size] = {0};
    char word[2000000];

    cin.getline(word, sizeof(word), '^');

    int i = 0;
    while (word[i]) {
        char c = tolower(word[i]);
        if (isalpha(c)) {
            ++valArr[c - 'a'];
        }
        ++i;
    }

    int min = INT_MAX;
    int max = 0;
    for (int i = 0; i < alphabet_size; i++) {
        if (valArr[i] > max) {
            max = valArr[i];
        }
        if (valArr[i] < min && valArr[i] != 0) {
            min = valArr[i];
        }
    }

    int maxIndex = 0;
    int minIndex = 0;
    for (int i = 0; i < alphabet_size; i++) {
        if (valArr[i] == max) {
            maxIndex = i;
            break;
        }
    }
    for (int i = 0; i < alphabet_size; i++) {
        if (valArr[i] == min) {
            minIndex = i;
            break;
        }
    }

    cout << char('a' + maxIndex) << " " << char('a' + minIndex) << "\n";

    return 0;
}