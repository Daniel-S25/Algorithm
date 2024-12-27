#include <iostream>
using namespace std;

// 합계를 계산하는 함수
double calculateSum(double n[], int a) {
    double sum = 0;
    for (int i = 0; i < a; i++) {
        sum += n[i];
    }
    return sum;
}

// 평균을 계산하는 함수
double calculateAverage(double n[], int a) {
    double sum = calculateSum(n, a);
    return sum / a;
}

int main() {
    const int A = 5;   // 배열 크기 상수화
    double numbers[A]; // 사용자 입력을 저장할 배열

    cout << "정수 5개를 입력하세요: ";

    // 사용자로부터 입력받기
    for (int i = 0; i < A; i++) {
        cin >> numbers[i];
    }

    // 합계와 평균 계산
    double sum = calculateSum(numbers, A);
    double average = calculateAverage(numbers, A);

    // 결과 출력
    cout << "합계: " << sum << ", 평균: " << average << endl;

    return 0;
}