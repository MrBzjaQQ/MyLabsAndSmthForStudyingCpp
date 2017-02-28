#include <QCoreApplication>
#include <QTextStream>
#include <QTime>

void PrintArray(int *Array, int LENGTH);
void PrintElements(int *Array, int LENGTH);
int* FillArray(int LENGTH);

QTextStream cin(stdin);
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Input length of single-line array\n" << flush;
    int LENGTH;
    cin >> LENGTH;
    int *Array = FillArray(LENGTH);
    PrintArray(Array,LENGTH);
    PrintElements(Array,LENGTH);
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

void PrintElements(int *Array, int LENGTH)
{
    cout << "\neven: " << flush;
    for(int i = 0; i<LENGTH; i++)
    {
        if(Array[i]%2==0)
            cout << Array[i] << " " << flush;
    }
    cout << "\nodd: " << flush;
    for(int i = 0; i<LENGTH; i++)
    {
        if(Array[i]%2==1)
            cout << Array[i] << " " << flush;
    }
}

void PrintArray(int *Array, int LENGTH)
{
    cout << "Array: " << flush;
    for(int i = 0; i<LENGTH; i++)
    {
         cout << Array[i] << " " << flush;
    }
}
