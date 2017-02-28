#include <QCoreApplication>
#include <QTextStream>
#include <QTime>

void FillArray(QList<int> *array, int LENGTH);
void DeleteElements(QList<int> *array);
void PrintArray(QList<int> *array);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    cout << "Input length of array\n" << flush;
    int LENGTH;
    cin >> LENGTH;
    QList<int> array;
    FillArray(&array, LENGTH);
    cout << "Array: " << flush;
    PrintArray(&array);
    DeleteElements(&array);
    cout << "\nEdited array: " << flush;
    PrintArray(&array);
    return a.exec();
}

void FillArray(QList<int> *array, int LENGTH)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    array->push_back(qrand()%4+2);
    for (int i = 1; i<LENGTH; i++)
       array->push_back(qrand()%25 + 1);
}

void DeleteElements(QList<int> *array) //которые нацело делятся на 1-й элемент
{
    for (int i = 1; i<array->size(); i++)
    {
        if(array->at(i)%array->at(0) == 0)
        {
            array->removeAt(i);
            i--;
        }
    }
}

void PrintArray(QList<int> *array)
{
    QTextStream cout(stdout);
    for (int i = 0; i<array->size(); i++)
        cout << array->at(i) << " " << flush;
}


