#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int N, M;
int tecNumber;

void outArray(int *B) {                 // вывод массива в случае A
    int len = N;
    for (int i = 0; i < len; i++) {
        std::cout << B[i] << " ";
    }
}

void outArray(std::vector<int> B) {     // вывод массива в случае B
    int len = N;
    for (int i = 0; i < len; i++) {
        std::cout << B[i] << " ";
    }
}

void outArrayX(int **B) {
    int lenX = N, lenY = M;
    for (int i = 0; i < lenX; i++) {
        for (int j = 0; j < lenY; j++)
            std::cout << B[i][j] << " ";
        std::cout << std::endl;
    }
}


bool checkForChangedSize(int *B) { // проверка на наличие в списке повторяющегося элемента
    bool result = false;
    int len = N;
    std::set<int> compareArray(B, B + len); // преобразуем в множество что бы избавиться от повторений
    if (compareArray.size() != len)
        result = true;
    return result;
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

int compareForLastNumber(int a, int b) {
    return a % 10 > b % 10;
} // ключ для сравнения (здесь по убыванию последней цифры)

int compareForFirstNumber(int a, int b) {  // ключ для сравнения (здесь по возрастанию последней цифры)
    bool result;
    char16_t aString = std::to_string(a)[0];
    char16_t bString = std::to_string(b)[0];
    int A = aString - '0';
    int B = bString - '0';
    if (A != B)         // сравниваем первые цифры
        result = (A < B);
    else {
        result = compareEqual(a, b);

    }

    return result;
}

std::vector<int> sortArray(int *B, int typeOfCompaer) {    // сортировка массива
    std::vector<int> result(B, B + N);
    if (typeOfCompaer == false)
        std::sort(result.begin(), result.end(), compareForLastNumber);
    else
        std::sort(result.begin(), result.end(), compareForFirstNumber);
    return result;
}


void part1(int *A) {  // 1 часть лабораторной

    if (checkForChangedSize(A))
        outArray(sortArray(A, 0));
    else
        outArray(A);
    std::cout << " " << std::endl;

}

void part2(int *A) { // 2 часть

    outArray(sortArray(A, 1));

    std::cout << " " << std::endl;

}

void part3() { // 3 часть
    int sum;
    int maxSum = -100;
    int indexOfMaxSum;

    std::cout << "Write size of array N*M:";
    std::cin >> N >> M;
    int A[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> tecNumber;
            A[i][j] = tecNumber;
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
//    std::cout << "Write size of array:";
//    std::cin >> N;
//    int A[N];
//    for (int i = 0; i < N; i++) {
//        std::cin >> tecNumber;
//        A[i] = tecNumber;
//    }
//    part1(A);
//    part2(A);
    part3();


    return 0;

}


