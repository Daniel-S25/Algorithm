#include <iostream>
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;          
    size_t currentSize; 
    size_t maxCapacity;

public:
    // �⺻ ������: ũ�� 10
    SimpleVector() : currentSize(0), maxCapacity(10) {
        data = new T[maxCapacity];
    }

    // ũ�⸦ �޴� ������
    SimpleVector(size_t size) : currentSize(0), maxCapacity(size) {
        data = new T[maxCapacity];
    }

    // �Ҹ���: �޸� ����
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: ���� �߰�
    void push_back(const T& value) {
        if (currentSize < maxCapacity) {
            data[currentSize++] = value;
        }
        else {
            cout << "Vector is full. Cannot add more elements.\n";
        }
    }

    // pop_back: ������ ���� ����
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
        else {
            cout << "Vector is empty. Cannot remove elements.\n";
        }
    }

    // size: ���� ���� ���� ��ȯ
    size_t size() const {
        return currentSize;
    }

    // capacity: �ִ� ũ�� ��ȯ
    size_t capacity() const {
        return maxCapacity;
    }

    // �迭 ��� ��� (������)
    void print() const {
        for (size_t i = 0; i < currentSize; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // �⺻ ������ �׽�Ʈ
    SimpleVector<int> vec;
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
    }
    vec.print(); // ���: 1 2 3 4 5 6 7 8 9 10

    vec.push_back(11); // �迭 ������ �׽�Ʈ

    vec.pop_back(); // ������ ���� ����
    vec.print(); // ���: 1 2 3 4 5 6 7 8 9

    cout << "Size: " << vec.size() << endl;       // ���: Size: 9
    cout << "Capacity: " << vec.capacity() << endl; // ���: Capacity: 10

    // ����� ���� ũ�� ������ �׽�Ʈ
    SimpleVector<string> strVec(5);
    strVec.push_back("Hello");
    strVec.push_back("World");
    strVec.print(); // ���: Hello World

    cout << "Size: " << strVec.size() << endl;       // ���: Size: 2
    cout << "Capacity: " << strVec.capacity() << endl; // ���: Capacity: 5

    return 0;
}
