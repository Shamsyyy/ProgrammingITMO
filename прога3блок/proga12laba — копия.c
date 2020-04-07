#include <stdio.h>
#include <limits.h>

int* max_element(const int* arr, int n){

    int values[2] = {INT_MIN, 0};
    for(int i=0; i<n; i++){
        if(arr[i]==values[0]){
            values[1]++;
        }
        if(arr[i]>values[0]){
            values[0] = arr[i];
            values[1] = 1;
        }
    }
    return values;
}

int main() {
    int* arr[5];
    arr[0] = 0;
    arr[1] = 5;
    arr[2] = 5;
    arr[3] = 4;
    arr[4] = 3;
    int* arr_2 = max_element(arr, 5);
    printf("%d %d", arr_2[0], arr_2[1]);
    return 0;
}

    //написать функцию которая принимает двумерный массив
    //пользователь получает от функции значение максимального элемента и кол-во таких элементов
    //функция main содержит фрагмент кода демонстрирующее использование кода
