#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int Length1;
int Length2;

float** inputMass(string filename)
{
    ifstream file(filename);
    file >> Length1;
    file >> Length2;
    float** bMass = new float* [Length1];


    for (int i = 0; i < Length1; i++) {
        bMass[i] = new float[Length2];

        for (int j = 0; j < Length2; j++) {
            file >> bMass[i][j];
        }
    }
    return bMass;
}

void quickSort(float* array, int low, int high)
{
    int i = low;
    int j = high;
    float pivot = array[(i + j) / 2];
    float temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

float** /*DEBUG*/ TakeNumFromMatrix(float** SortedMatrix) {

    float** VMass = new float* [Length1];


    for (int i = 0; i < Length1; i++) {
        VMass[i] = new float[Length2];
    }

    float temp;
    int counter = 0;

    for (int i = 0; i < Length1; i++) {
        temp = SortedMatrix[i][0];
        counter = 0;
        for (int j = 0; j < Length2; j++) {
            if (temp != SortedMatrix[i][j]) {
                VMass[i][counter] = temp;
                temp = SortedMatrix[i][counter];
                counter++;
            }

        }
    }

    return VMass;
}

int main() {
    float** MainMass = inputMass("input.txt");

    for (int i = 0; i < 2; i++)
    {
        quickSort(MainMass[i], 0, Length2 - 1);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++) {
            cout << " " << MainMass[i][j];
        }
        cout << "\n";
    }

    cout << "\n";

    MainMass = TakeNumFromMatrix(MainMass);


    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++) {
            cout << " " << MainMass[i][j];
        }
        cout << "\n";
    }


}
