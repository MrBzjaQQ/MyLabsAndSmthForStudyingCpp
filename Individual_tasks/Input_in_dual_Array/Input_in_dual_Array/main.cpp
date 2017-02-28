#include <QCoreApplication>
#include <QTextStream>
#include <QTime>

int** FillArray(int ARRAY_HEIGHT, int ARRAY_WIDTH);
void PrintArray(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH);
void AnvancedPrintArray(int **NewArray, int NEW_ARRAY_HEIGHT, int ARRAY_WIDTH);
int** PutRowsWithSumToArray(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH);
// Отладить

QTextStream cin(stdin);
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Input height and width of Array\n" << flush;
    int ARRAY_HEIGHT, ARRAY_WIDTH;
    cin >> ARRAY_HEIGHT >> ARRAY_WIDTH;
    int **Array = FillArray(ARRAY_HEIGHT, ARRAY_WIDTH);
    PrintArray(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
    int **NewArray = PutRowsWithSumToArray(Array, ARRAY_HEIGHT, ARRAY_WIDTH);
    AnvancedPrintArray(NewArray, ARRAY_HEIGHT*2, ARRAY_WIDTH);
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
    cout << "\nArray: \n" << flush;
    for (int i = 0; i<ARRAY_HEIGHT; i++)
    {
        for (int j = 0; j<ARRAY_WIDTH; j++)
            cout << Array[i][j] << " " << flush;
        cout << "\n" << flush;
    }
}

int** PutRowsWithSumToArray(int **Array, int ARRAY_HEIGHT, int ARRAY_WIDTH)
{
    int sum = 0;
    int NEW_ARRAY_HEIGHT = ARRAY_HEIGHT*2;
    int **NewArray = new int*[NEW_ARRAY_HEIGHT];
    for(int i = 0; i<ARRAY_HEIGHT; i++)
    {
        if (i%2 == 1)
        NewArray[i] = new int[NEW_ARRAY_HEIGHT];
        else
            NewArray[i] = new int[1];
    }
    for (int i = 0, k = 0; i<NEW_ARRAY_HEIGHT; i+=2, k++)
    {
        sum = 0;
        for (int j = 0; j<ARRAY_WIDTH; j++)
        {
            NewArray[i][j] = Array[k][j];
            if (Array[k][j] > 0)
                sum += Array[k][j];
            NewArray[i+1][0] = sum;
        }
    }
    return NewArray;

}
void AnvancedPrintArray(int **NewArray, int NEW_ARRAY_HEIGHT, int ARRAY_WIDTH)
{
    cout << "\nNewArray: " << flush;
    for (int i = 0; i<NEW_ARRAY_HEIGHT; i+=2)
    {
        for (int j = 0; j<ARRAY_WIDTH; j++)
        {
            cout << NewArray[i][j] << " " << flush;
        }
        cout << "\n" << NewArray[i+1][0] << " " << flush;
    }

}
