#include <QCoreApplication>
#include <QTextStream>
#include <QTime>

int** FillArray(int ARRAY_HEIGHT, int ARRAY_WIDTH);
void SetColumn(int** Array, int ARRAY_HEIGHT, int index, int* ArrayColumn);
int* GetColumn(int** Array, int ARRAY_HEIGHT, int index);
int* FindMin(int **Array,  int ARRAY_HEIGHT, int ARRAY_WIDTH);
int* FindMax(int **Array,  int ARRAY_HEIGHT, int ARRAY_WIDTH);
void PrintArray(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH);
QTextStream cin(stdin);
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Input height and width of the array\n" << flush;
    int ARRAY_HEIGHT, ARRAY_WIDTH;
    cin >> ARRAY_HEIGHT >> ARRAY_WIDTH;
    int **Array = FillArray(ARRAY_HEIGHT, ARRAY_WIDTH);
    cout << "Array\n" << flush;
    PrintArray(Array,ARRAY_HEIGHT,ARRAY_WIDTH);
    int *MinIndexes = FindMin(Array,  ARRAY_HEIGHT, ARRAY_WIDTH);
    int *MaxIndexes = FindMax(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
    cout << "indexes: " << MinIndexes[0] << " " << MinIndexes[1] << "\n" <<flush;
    cout << "indexes: " << MaxIndexes[0] << " " << MaxIndexes[1] << "\n" <<flush;
    int *Column1 = GetColumn(Array, ARRAY_HEIGHT, MinIndexes[1]);
    int *Column2 = GetColumn(Array, ARRAY_HEIGHT, MaxIndexes[1]);
    SetColumn(Array, ARRAY_HEIGHT, MaxIndexes[1], Column1);
    SetColumn(Array, ARRAY_HEIGHT, MinIndexes[1], Column2);
    cout << "Array\n" << flush;
    PrintArray(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
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
            Array[i][j] = qrand()%1000 - 500;
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

int* FindMin(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH)
{
    int *MinIndexes = new int[2];
    int minimum = 23456678;
    for(int i = 0; i<ARRAY_HEIGHT; i++)
        for(int j = 0; j<ARRAY_WIDTH; j++)
        {
            if (minimum > Array[i][j])
            {
                minimum = Array[i][j];
                MinIndexes[0] = i;
                MinIndexes[1] = j;
            }
        }
    cout << "Minimum: " << minimum << "\n" << flush;
    return MinIndexes;
}
int* FindMax(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH)
{ // минимальный по модулю положительный
    int *MaxIndexes = new int[2];
    int minimum = 23456678;
    for(int i = 0; i<ARRAY_HEIGHT; i++)
        for(int j = 0; j<ARRAY_WIDTH; j++)
        {
            if (minimum > Array[i][j] && Array[i][j] > 0)
            {
                minimum = Array[i][j];
                MaxIndexes[0] = i;
                MaxIndexes[1] = j;
            }
        }
    cout << "Minimum_pol: " << minimum << "\n" << flush;
    return MaxIndexes;
}

void PrintArray(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH) //+
{
    for (int i = 0; i<ARRAY_HEIGHT; i++)
    {
        for (int j = 0; j<ARRAY_WIDTH; j++)
            cout << Array[i][j] << "    " << flush;
        cout << "\n" << flush;
    }
}

