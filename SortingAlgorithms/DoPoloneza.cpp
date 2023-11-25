#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;  // imię
    float s;
    int d,m;  // średnia
};

void bubbleSort(Student arr[], int n, char que[])
{
    int i, j;
    bool swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = false;

        for (j = 0; j < n - i - 1; j++) {
            
            switch (que[0])
            {
            case 's': //start
                if (arr[j].s < arr[j + 1].s) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
                else if (arr[j].s == arr[j + 1].s)
                {
                    switch (que[1])
                    {
                    case 'm':
                        if (arr[j].m < arr[j + 1].m) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        else if (arr[j].m == arr[j + 1].m)
                        {
                            if (arr[j].d < arr[j + 1].d) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        }
                        break;
                    case 'd':
                        if (arr[j].d < arr[j + 1].d) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        else if (arr[j].d == arr[j + 1].d)
                        {
                            if (arr[j].m < arr[j + 1].m) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        }
                        break;
                    }
                }
                break; //end

            case 'm': //start
                if (arr[j].m < arr[j + 1].m) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
                else if (arr[j].m == arr[j + 1].m)
                {
                    switch (que[1])
                    {
                    case 's':
                        if (arr[j].s < arr[j + 1].s) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        else if (arr[j].s == arr[j + 1].s)
                        {
                            if (arr[j].d < arr[j + 1].d) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        }
                        break;
                    case 'd':
                        if (arr[j].d < arr[j + 1].d) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        else if (arr[j].d == arr[j + 1].d)
                        {
                            if (arr[j].s < arr[j + 1].s) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        }
                        break;
                    }
                }
                break; //end
            case 'd': //start
                if (arr[j].d < arr[j + 1].d) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
                else if (arr[j].d == arr[j + 1].d)
                {
                    switch (que[1])
                    {
                    case 'm':
                        if (arr[j].m < arr[j + 1].m) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        else if (arr[j].m == arr[j + 1].m)
                        {
                            if (arr[j].s < arr[j + 1].s) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        }
                        break;
                    case 's':
                        if (arr[j].s < arr[j + 1].s) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        else if (arr[j].s == arr[j + 1].s)
                        {
                            if (arr[j].m < arr[j + 1].m) {
                            swap(arr[j], arr[j + 1]);
                            swapped = true;
                        }
                        }
                        break;
                    }
                }
                break; //end        
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;           //wczytuje ilosc 
    cin.ignore();

    
    Student men[n];
    Student women[n];

    char arr[3];
          //kolejnosc sortowania
    cin >> arr[0] >> arr[1] >> arr[2];
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cin >> men[i].name >> men[i].s >> men[i].d >> men[i].m >> women[i].name >> women[i].s >> women[i].d >> women[i].m;
        cin.ignore();
    }

    bubbleSort(men, n, arr);
    bubbleSort(women, n, arr);

    for (int i = 0; i < n; i++)
    {
        std::cout << men[i].name << " " << women[i].name << " ";
    }
    

    return 0;
}