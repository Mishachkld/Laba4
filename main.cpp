#include <iostream>

int N, M;
#define ARRAY_SIZE 10002
#define MATRIX_SIZE 102

void outArray(int *B) {                 // вывод массива в случае A
    int len = N;
    for (int i = 0; i < len; i++) {
        std::cout << B[i] << " ";
    }
}


bool checkForRepeat(int *B){ // проверка на наличие в списке повторяющегося элемента
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if(B[i] == B[j])
                return true;
        }
    }
    return false;
}



int multip(int a) {   // перемножаем цифры числа
    int result = 1;
    while (a != 0) {
        result *= (a % 10);
        a /= 10;
    }
    return result;
}

int compareEqual(int a, int b) {   // сравниваем  числа c одинаковой первой цифрой
    bool result;
    int A = multip(a);
    int B = multip(b);
    if (A == B)
        result = a < b;
    else
        result = A < B;
//    std::cout << A << " " << B << " ";
    return result;
}

int compareForLastNumber(int a, int b) {  // ключ для сравнения (здесь по убыванию последней цифры)
    return a % 10 > b % 10;
}

int compareForFirstNumber(int a, int b) {  // ключ для сравнения (здесь по возрастанию первой цифры)
    bool result;
    char16_t aChar = std::to_string(a)[0];
    char16_t bChar = std::to_string(b)[0];
    int A = aChar - '0';
    int B = bChar - '0';
    if (A != B)         // сравниваем первые цифры
        result = (A < B);
    else
        result = compareEqual(a, b);   // доп сравнение одинаковых первых цифр

    return result;
}

int* mySortForLastNumber(int* B){ //ласт намбер

    int len = N, temp = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if(compareForLastNumber(B[j], B[i])){
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }


    return B;
}int* mySortForFirstNumber(int* B){   //сортировка по первой цифре
    int len = N, temp = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if(compareForFirstNumber(B[j], B[i])){
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }

    return B;
}

int* sortArray(int* B, int typeOfCompare) {    // способ сортировки массива
    if (typeOfCompare == false)
        B = mySortForLastNumber(B); //std::sort(B, B + N, compareForLastNumber);
    else
        B = mySortForFirstNumber(B); // std::sort(B, B + N, compareForFirstNumber);

    return B;
}
//-------------------------------------------(＠＾◡＾)-------------------------------------------\\







void part1(int *A) {  // 1 часть лабораторной

    if (checkForRepeat(A)) {
        sortArray(A, 0);
        outArray(A);
    }
    else
        outArray(A);
    std::cout << " " << std::endl;

}

void part2(int *A) { // 2 часть
    sortArray(A, 1);
    outArray(A);

    std::cout << " " << std::endl;

}

void part3() { // 3 часть
    int sum;
    int maxSum = -100;
    int indexOfMaxSum;

    std::cout << "Write size of array N*M:";
    std::cin >> N >> M;
    int A[MATRIX_SIZE][MATRIX_SIZE];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    for (int i = 0; i < M; i++) {   // ищем столбец с максимальной суммой
        sum = 0;
        for (int j = 0; j < N; j++) {
            sum += A[j][i];
        }
        if (sum > maxSum) {
            maxSum = sum;
            indexOfMaxSum = i;
        }
    }

    for (int i = 0; i < N; i++) {  // умножаем нужный столбец на 3
        A[i][indexOfMaxSum] *= 3;
    }


    for (int i = 0; i < N; i++) {  // вывод матрицы
        for (int j = 0; j < M; j++)
            std::cout << A[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Max sum of column:" << " " << maxSum << std::endl;
    std::cout << "Index of max sum column:" << " " << indexOfMaxSum << std::endl;


}


int main() {
    std::cout << "Write size of array:";
    std::cin >> N;

    int A[ARRAY_SIZE];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    part1(A);
    part2(A);
    part3();

    return 0;

}


