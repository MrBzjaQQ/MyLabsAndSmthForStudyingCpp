#include <QCoreApplication>
#include <QTextStream>
#include <QTime>

void PrintArray(int *Array, int LENGTH);
int* FillArray(int LENGTH);
int FindMinimum(int *Array, int LENGTH);
int FindMaximum(int *Array, int LENGTH);
int* GetArrayBetween(int *Array, int minIndex, int maxIndex);
void SwapNumbersBetween(int *Array, int minIndex, int maxIndex);

QTextStream cin(stdin);
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Input length of single-line array\n" << flush;
    int LENGTH;
    cin >> LENGTH;
    int *Array = FillArray(LENGTH);
    //int *Array = new int[10] {46, 26, 47, 4, 45, 29, 20, 23, 2, 43};
    PrintArray(Array, LENGTH);
    int minIndex = FindMinimum(Array, LENGTH);
    int maxIndex = FindMaximum(Array, LENGTH);
    cout << "\nmin = " << Array[minIndex] << "\nminIndex = " << minIndex << flush;
    cout << "\nmax = " << Array[maxIndex] << "\nmaxIndex = " << maxIndex << flush;
    if(minIndex < maxIndex)
        SwapNumbersBetween(Array, minIndex, maxIndex);
    else SwapNumbersBetween(Array,  maxIndex, minIndex);
    PrintArray(Array, LENGTH);

    return a.exec();
}

int* FillArray(int LENGTH)
{
    int *Array = new int[LENGTH];
    QTime midn(0,0,0);
    qsrand(midn.secsTo(QTime::currentTime()));
    for (int i = 0; i<LENGTH; i++)
    {
        Array[i] = qrand()%50 + 1;
    }
    return Array;
}
void PrintArray(int *Array, int LENGTH)
{
    cout << "\nArray: " << flush;
    for(int i = 0; i<LENGTH; i++)
    {
         cout << Array[i] << " " << flush;
    }
}

int FindMaximum(int *Array, int LENGTH)
{
    int max = -1000, index = -1;
    for(int i = 0; i<LENGTH; i++)
        if (max < Array[i])
        {
            max = Array[i];
            index = i;
        }
    return index;

}
int FindMinimum(int *Array, int LENGTH)
{
    int min = 1000, index = -1;
    for(int i = 0; i<LENGTH; i++)
        if (min > Array[i])
        {
            min = Array[i];
            index = i;
        }
    return index;
}
int* GetArrayBetween(int *Array, int minIndex, int maxIndex)
{
    if(maxIndex - minIndex < 2)
        return Q_NULLPTR;
    int *NewArray = new int[maxIndex-minIndex-1];
    for (int i = minIndex+1; i<maxIndex; i++)
        NewArray[i] = Array[i];
    return NewArray;

}
void SwapNumbersBetween(int *Array, int minIndex, int maxIndex)
{
    int *NewArray = GetArrayBetween(Array, minIndex, maxIndex);
    if (NewArray == Q_NULLPTR)
        return;
    for(int i = minIndex+1, j=maxIndex-1; i<maxIndex; i++, j--)
        Array[j] = NewArray[i];
}
