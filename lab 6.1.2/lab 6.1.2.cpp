// Варіант 25(Рекурсивний спосіб)
#include <iostream> 
using namespace std;

void InitArray(int t[], const int size, int i)
{
    if (i < size)
    {
        t[i] = -11 + rand() % 25;
        InitArray(t, size, i + 1);
        return;
    }
}


void PrintArray(int t[], const int size, int i) {
    if (i < size)
    {
        if (i == 0)
            cout << "{";
        cout << t[i];
        if (i != size - 1)
            cout << ", ";
        else cout << "}" << endl;
        PrintArray(t, size, i + 1);
        return;
    }
}

int SumArray(const int* const t, const int size, int i)
{
    if (i < size) {
        if (i % 3 != 0 && t[i] < 0)
            return t[i] + SumArray(t, size, i + 1);
        else
            return SumArray(t, size, i + 1);
    }
    else return 0;
}


int CountElementArray(const int* const t, const int size, int i)
{
    if (i < size)
    {
        if (i % 3 != 0 && t[i] < 0)
            return 1 + CountElementArray(t, size, i + 1);
        else
            return CountElementArray(t, size, i + 1);
    }
    else return 0;
}


void ReplaceElementArray(int t[], const int size, int i)
{
    if (i < size)
    {
        if (i % 3 != 0 && t[i] < 0)
            t[i] = 0;
        ReplaceElementArray(t, size, i + 1);
        return;
    }
}

int main()
{
    srand(time(0));
    const int size = 25;
    int t[size];

    InitArray(t, size, 0);
    PrintArray(t, size, 0);
    cout << "Array sum by condition = " << SumArray(t, size, 0) << endl;
    cout << "Count element by condition = " << CountElementArray(t, size, 0) << endl;
    ReplaceElementArray(t, size, 0);
    PrintArray(t, size, 0);

    return 0;
}

