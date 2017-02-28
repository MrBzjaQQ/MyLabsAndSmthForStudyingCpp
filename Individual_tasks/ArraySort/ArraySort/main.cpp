#include <QCoreApplication>
#include <QLinkedList>
#include <QTextStream>
#include <QTime>
int** FillArray(int ARRAY_HEIGHT, int ARRAY_WIDTH);
void PrintArray(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH);
void SortByWidth(int* ArrayRow, int ARRAY_WIDTH);
int* SortByHeight(int* ArrayColumn, int ARRAY_HEIGHT);
void Swap(int** Array, int ARRAY_HEIGHT, int ARRAY_WIDTH);
int** SortRectangle(int** Array, int ARRAY_HEIGHT, int ARRAY_WIDTH);
int* GetColumn(int** Array, int ARRAY_HEIGHT, int index);
void SetColumn(int** Array, int ARRAY_HEIGHT, int index, int* ArrayColumn);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    cout << "Input height and width for new array\n" << flush;
    int ARRAY_HEIGHT = 0, ARRAY_WIDTH=0;
    cin >> ARRAY_HEIGHT;
    cin >> ARRAY_WIDTH;

    int **Array = FillArray(ARRAY_HEIGHT, ARRAY_WIDTH);
    cout << "Array:\n" << flush;
    PrintArray(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
    cout << "\nStep 1: \n" << flush;
    Array = SortRectangle(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
    PrintArray(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
    cout << "\nStep 2:\n" <<flush;
    Swap(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
    PrintArray(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
    cout << "\nDone\n" << flush;
    return a.exec();
}
int** FillArray(int ARRAY_HEIGHT, int ARRAY_WIDTH) //+
{
    int** Array = new int*[ARRAY_HEIGHT];
    for(int i = 0; i<ARRAY_HEIGHT; i++)
        Array[i] = new int[ARRAY_WIDTH];
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    for (int i = 0; i<ARRAY_HEIGHT; i++)
        for (int j = 0; j<ARRAY_WIDTH; j++)
            Array[i][j] = qrand()%10;
    return Array;
}

void PrintArray(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH) //+
{
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    for (int i = 0; i<ARRAY_HEIGHT; i++)
    {
        for (int j = 0; j<ARRAY_WIDTH; j++)
            cout << Array[i][j] << " " << flush;
        cout << "\n" << flush;
    }
}

void SortByWidth(int* ArrayRow, int ARRAY_WIDTH)
{
    int temp;
    bool not_sorted = true;
    while(not_sorted)
    {
        not_sorted = false;
        for (int i = 1; i<ARRAY_WIDTH; i++)
            if(ArrayRow[i] < ArrayRow[i-1])
            {
                temp = ArrayRow[i];
                ArrayRow[i] = ArrayRow[i-1];
                ArrayRow[i-1] = temp;
                not_sorted = true;
            }

    }
}

int* SortByHeight(int* ArrayColumn, int ARRAY_HEIGHT)
{
    int temp;
    bool not_sorted = true;
    while(not_sorted)
    {
        not_sorted = false;
        for (int i = 1; i<ARRAY_HEIGHT; i++)
            if(ArrayColumn[i] < ArrayColumn[i-1])
            {
                temp = ArrayColumn[i];
                ArrayColumn[i] = ArrayColumn[i-1];
                ArrayColumn[i-1] = temp;
                not_sorted = true;
            }

    }
    return ArrayColumn;
}

void Swap(int** Array, int ARRAY_HEIGHT, int ARRAY_WIDTH)
{
    int** ArrayCopy = new int*[ARRAY_HEIGHT];
    for(int i = 0; i<ARRAY_HEIGHT; i++)
        ArrayCopy[i] = new int[ARRAY_WIDTH];
    for (int i = 0; i<ARRAY_HEIGHT; i++)
        for (int j=0; j<ARRAY_WIDTH; j++)
        {
            ArrayCopy[i][j] = Array[i][j];
        }


    int temp;
    for (int i = 0; i<ARRAY_HEIGHT; i++)
        for (int j=0; j<ARRAY_WIDTH; j++)
        {
            temp = Array[i][j];
            Array[i][j] = ArrayCopy[ARRAY_HEIGHT-i-1][ARRAY_WIDTH-j-1];
            ArrayCopy[ARRAY_HEIGHT-i-1][ARRAY_WIDTH-j-1] = temp;
        }
    delete ArrayCopy;
}

int** SortRectangle(int** Array, int ARRAY_HEIGHT, int ARRAY_WIDTH)
{
    for(int i = 0; i<ARRAY_HEIGHT; i++)
    {
        SortByWidth(Array[i], ARRAY_WIDTH); //??
    }
    for(int i = 0; i<ARRAY_WIDTH; i++)
    {
        SetColumn(Array, ARRAY_HEIGHT, i, SortByHeight(GetColumn(Array,ARRAY_HEIGHT, i), ARRAY_HEIGHT));
    }
    return Array;
}
int* GetColumn(int** Array, int ARRAY_HEIGHT, int index)
{
    int* ArrayColumn = new int[ARRAY_HEIGHT];
    for(int i = 0; i<ARRAY_HEIGHT;i++)
        ArrayColumn[i] = Array[i][index];
    return ArrayColumn;
}
void SetColumn(int** Array, int ARRAY_HEIGHT, int index, int* ArrayColumn)
{
    for(int i = 0; i<ARRAY_HEIGHT;i++)
       Array[i][index] = ArrayColumn[i];
}
