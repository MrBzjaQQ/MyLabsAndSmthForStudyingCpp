#include <QCoreApplication>
#include <QTextStream>
int* find2Maximal(int *arr, int N);
int* inputSumsOfMaximums(int* arr, int N, int* indexes, int *new_N, int sum);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    int N = 10;
    int *arr = new int[10] {8, 1, 2, 3, 4, 5, 6, 7, 9, 0};
    int *indexes = find2Maximal(arr, N);
    int new_N = 10;
    int sum = arr[indexes[0]] + arr[indexes[1]];
    arr = inputSumsOfMaximums(arr, N, indexes, &new_N, sum);
    for (int i = 0; i<new_N; i++)
    {
        cout << arr[i] << " " << endl;
    }
    return a.exec();
}

int* find2Maximal(int *arr, int N)
{
    int *indexes = new int[2] {-23456, -23456};

    for (int i = 0; i< N; i++)
    {
        if (arr[i] > indexes[0])
        {
            indexes[0] = arr[i];
            continue;
        }
        if (arr[i] > indexes[1] && arr[i] <= indexes[0])
            indexes[1] = arr[i];
    }
    return indexes;
}

int* inputSumsOfMaximums(int* arr, int N, int* indexes, int *new_N, int sum)
{
    int *new_arr;
    for(int i = 0; i< 2; i++)
    {
       if (indexes[i] == N-1)
       {
           new_arr = new int[N+1];
           for (int j = 0; j<10; j++)
           {
               new_arr[j] = arr[j];
           }
           new_arr[10] = sum;
           arr = new_arr;
           *new_N = N+1;
       }
       else
       {
           arr[indexes[i] + 1] = sum;
       }
    }
    delete new_arr;
    return arr;
}
