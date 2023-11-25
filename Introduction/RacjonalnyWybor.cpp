#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Car {
    string name;
    long int mileage;
};

bool comp(Car n1, Car n2) {
    if (n1.mileage != n2.mileage) 
        return n1.mileage < n2.mileage;
    return n1.name < n2.name;
}

int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long int n;

    cin >> n;  //min 3
    cin.ignore(); // Dodaj to, aby pozbyć się znaków nowego wiersza

    Car smallest[3];
    Car car;
    long double p; //min 0
    long int d; //min 1

    for (long i = 0; i < n; i++)
    {
 
        std::getline(std::cin, car.name);
        std::cin >> p >> d;     
        cin.ignore();
        
        car.mileage = p * 1000 / (d * 0.0254 * 3.141593);

        if (i < 3)
            smallest[i] = car;
        else
        {
            std::sort(smallest, smallest + 3, comp);
            bool should_update = false;
            bool should_update2 = false;
    
            for (int j = 0; j < 3; j++)
            {
                if (car.mileage < smallest[j].mileage)
                {
                    should_update = true;
                    break;
                }
                else if (car.mileage == smallest[j].mileage && car.name < smallest[j].name)
                {
                    should_update2 = true;
                    break;
                }
            }
    
            if (should_update)
            {
                if (car.mileage < smallest[0].mileage)
                {
                    smallest[2] = smallest[1];
                    smallest[1] = smallest[0];
                    smallest[0] = car;
                }
                else if (car.mileage < smallest[1].mileage)
                {
                    smallest[2] = smallest[1];
                    smallest[1] = car;
                }             
                else if (car.mileage < smallest[2].mileage)
                {
                    smallest[2] = car;
                }
            }
            if (should_update2)
            {
                if (car.mileage < smallest[0].mileage)
                {
                    smallest[2] = smallest[1];
                    smallest[1] = smallest[0];
                    smallest[0] = car;
                }
                else if (car.mileage < smallest[1].mileage)
                {
                    smallest[2] = smallest[1];
                    smallest[1] = car;
                }
                else if (car.mileage == smallest[2].mileage && car.name < smallest[2].name)
                {
                    smallest[2] = car;
                }                
                else if (car.mileage < smallest[2].mileage)
                {
                    smallest[2] = car;
                }

            }
        }
    }
    std::sort(smallest, smallest + 3, comp);
    for (int i = 0; i < 3; i++)
        cout << smallest[i].name << " " << smallest[i].mileage << "\n";

    return 0;
}