#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Create(int* r, const int size, const int Low, const int High, int i)
{
    r[i] = Low + rand() % (High - Low + 1); 
    if (i < size - 1)
        Create(r, size, Low, High, i + 1);
}

void Print(const int* r, const int size, int i)
{
    cout << setw(4) << r[i]; 
    if (i < size - 1)
        Print(r, size, i + 1); 
    else
        cout << endl;
}

void ProcessArray(int* r, const int size, int& count, int& sum, int i)
{
    if (!(r[i] % 2 == 0 || r[i] % 13 == 0)) {
        sum += r[i];
        count++; 
        r[i] = 0; 
    }
    if (i < size - 1)
        ProcessArray(r, size, count, sum, i + 1); 
}

int main() {
    srand((unsigned)time(0));

    const int n = 23; 
    int r[n];

    int Low = 4, High = 68;

    Create(r, n, Low, High, 0);
    cout << "Initial array: " << endl;
    Print(r, n, 0);

    int count = 0, sum = 0;

    ProcessArray(r, n, count, sum, 0);

    cout << "Number of elements that meet the criteria: " << count << endl;
    cout << "Sum of those elements: " << sum << endl;
    cout << "Modified array: " << endl;
    Print(r, n, 0);

    return 0;
}
