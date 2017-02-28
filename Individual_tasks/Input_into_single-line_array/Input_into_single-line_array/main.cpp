#include <QCoreApplication>
#include <QTextStream>
#include <QTime>

int* FillArray(int LENGTH);
void PrintArray(int *Array, int LENGTH);
int FindMax(int *Array, int LENGTH);
int* PutSumAfterThisTwo(int *Array, int LENGTH, int* TwoCloseToMaxValuesIndexes);
int* FindIndexesOfTwoCloseElements(int *Array, int maxElement, int LENGTH);
//Lab 5 -> 5
QTextStream cin(stdin);
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int LENGTH;
    cout << "Input Array length\n" << flush;
    cin >> LENGTH;
    int *Array = FillArray(LENGTH);
    PrintArray(Array, LENGTH);
    int maxInArray = FindMax(Array, LENGTH);
    int *TwoCloseToMaxValuesIndexes = FindIndexesOfTwoCloseElements(Array, maxInArray, LENGTH);
    cout << "\nClose Value 1 = " << Array[TwoCloseToMaxValuesIndexes[0]] << "\nClose Value 2 = " << Array[TwoCloseToMaxValuesIndexes[1]] << "\n" << flush;
    int NewLength = LENGTH+2;
    int *NewArray = PutSumAfterThisTwo(Array, NewLength, TwoCloseToMaxValuesIndexes);
    PrintArray(NewArray, NewLength);
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

int FindMax(int *Array, int LENGTH) // previousIndex = индекс предыдущего максимального (или -1 если такого нет)
{
    int max = -1;
    for (int i = 0; i<LENGTH; i++)
    {
        if (max<Array[i])
        {
            max = Array[i];
        }
    }
    return max;

}
int* PutSumAfterThisTwo(int *Array, int LENGTH, int* TwoCloseToMaxValuesIndexes)
{
    int SumOfTwoClose = Array[TwoCloseToMaxValuesIndexes[0]] + Array[TwoCloseToMaxValuesIndexes[1]];
    int *NewArray = new int[LENGTH];

    for (int i = 0, j = 0; j<LENGTH; i++, j++)
    {
        NewArray[j] = Array[i];
        if (i == TwoCloseToMaxValuesIndexes[0] || i == TwoCloseToMaxValuesIndexes[1])
            NewArray[++j] = SumOfTwoClose;
    }
    return NewArray;
}

int* FindIndexesOfTwoCloseElements(int *Array, int maxElement, int LENGTH)
{
    int difference = 10000;
    int *TwoCloseToMaxValuesIndexes = new int[2];
    for (int i = 0; i<LENGTH; i++)
        for (int j = 0; j<LENGTH; j++)
            if (difference > qAbs(maxElement - (Array[i] + Array[j])) && i!=j && Array[i] + Array[j] != maxElement)
            {
                difference = qAbs(maxElement - (Array[i] + Array[j]));
                TwoCloseToMaxValuesIndexes[0] = i;
                TwoCloseToMaxValuesIndexes[1] = j;
            }
    return TwoCloseToMaxValuesIndexes;
}

