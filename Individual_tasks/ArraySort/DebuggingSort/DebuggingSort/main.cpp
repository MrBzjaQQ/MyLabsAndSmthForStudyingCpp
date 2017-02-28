#include <QCoreApplication>
#include <QTextStream>
int* SortByWidth(int* ArrayString, int ARRAY_WIDTH);
int main(int argc, char *argv[])
{
    QTextStream cout(stdout);
    QCoreApplication a(argc, argv);
    int *ArrayString = new int[10] {10, 9, 3, 7, 6, 18, 4, 9, 2, 1};
    SortByWidth(ArrayString, 10);
    for (int i = 0; i<10; i++)
        cout << ArrayString[i] << " " << flush;
    delete ArrayString;
    return a.exec();
}
int* SortByWidth(int* ArrayString, int ARRAY_WIDTH)
{
    //Алгоритм сортировки пузырьком
    int temp;
    bool not_sorted = true;
    while(not_sorted)
    {
        not_sorted = false;
        for (int i = 1; i<ARRAY_WIDTH; i++)
            if(ArrayString[i] < ArrayString[i-1])
            {
                temp = ArrayString[i];
                ArrayString[i] = ArrayString[i-1];
                ArrayString[i-1] = temp;
                not_sorted = true;
            }

    }
    return ArrayString;


}

