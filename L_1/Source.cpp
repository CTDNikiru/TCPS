#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int Length1;
int Length2;

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}



vector<float>* inputMass(string filename, int numOfStr)
{
    ifstream file(filename);
    float bufer;
    char* s = new char[256];
    for (int i = 0; i < numOfStr; i++)
        file.getline(s, 256);
          

    file >> Length1;
    file >> Length2;

    vector<float> *vMass = new vector<float>[Length1];

    for (int i = 0; i < Length1; i++) {
        for (int j = 0; j < Length2; j++) {
            file >> bufer;
            vMass[i].push_back(bufer);
        }
    }
    return vMass;
}


int main() {

    vector<float>* VectorMass = inputMass("input.txt", 0);


    cout << "Matrix 1: \n";

    for (int i = 0; i < Length1; i++) {
        for (int j = 0; j < Length2; j++) {
            cout << " " << VectorMass[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < Length1; i++) {
        sort(VectorMass[i].begin(), VectorMass[i].end());
        VectorMass[i].erase(unique(VectorMass[i].begin(), VectorMass[i].end()), VectorMass[i].end());
    }

    cout << "---------------------------------------------------\n";

    vector<float>* Vector2 = inputMass("input.txt", 7);

    cout << "Matrix 2: \n";

    for (int i = 0; i < Length1; i++) {
        for (int j = 0; j < Length2; j++) {
            cout << " " << Vector2[i][j];
        }
        cout << "\n";
    }


    for (int i = 0; i < Length1; i++) {
        sort(Vector2[i].begin(), Vector2[i].end());
        Vector2[i].erase(unique(Vector2[i].begin(), Vector2[i].end()), Vector2[i].end());
    }


    cout << "---------------------------------------------------\n";
    cout << "Sorted and deleted duplicates Matrix 1: \n";

    for (int i = 0; i < Length1; i++) { //
        for (int j = 0; j < VectorMass[i].size(); j++) {
            cout << " " << VectorMass[i][j];
        }
        cout << "\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Sorted and deleted duplicates Matrix 2: \n";

    for (int i = 0; i < Length1; i++) { //
        for (int j = 0; j < Vector2[i].size(); j++) {
            cout << " " << Vector2[i][j];
        }
        cout << "\n";
    }

    cout << "---------------------------------------------------\n";

    int counter = 0;
    for (int i = 0; i < Length1; i++) { //
        for (int j = 0; j < Length1; j++) {
            if (VectorMass[j] == Vector2[i]) {
                counter++;
            }
        }
    }
    cout << "\ntotal equalis count: " << counter;
}
