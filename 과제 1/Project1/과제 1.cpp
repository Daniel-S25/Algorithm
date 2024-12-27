#include <iostream>
using namespace std;

// �հ踦 ����ϴ� �Լ�
double calculateSum(double n[], int a) {
    double sum = 0;
    for (int i = 0; i < a; i++) {
        sum += n[i];
    }
    return sum;
}

// ����� ����ϴ� �Լ�
double calculateAverage(double n[], int a) {
    double sum = calculateSum(n, a);
    return sum / a;
}

int main() {
    const int A = 5;   // �迭 ũ�� ���ȭ
    double numbers[A]; // ����� �Է��� ������ �迭

    cout << "���� 5���� �Է��ϼ���: ";

    // ����ڷκ��� �Է¹ޱ�
    for (int i = 0; i < A; i++) {
        cin >> numbers[i];
    }

    // �հ�� ��� ���
    double sum = calculateSum(numbers, A);
    double average = calculateAverage(numbers, A);

    // ��� ���
    cout << "�հ�: " << sum << ", ���: " << average << endl;

    return 0;
}