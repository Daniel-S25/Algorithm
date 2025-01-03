#include <iostream>
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;          
    size_t currentSize; 
    size_t maxCapacity;

public:
    // 기본 생성자: 크기 10
    SimpleVector() : currentSize(0), maxCapacity(10) {
        data = new T[maxCapacity];
    }

    // 크기를 받는 생성자
    SimpleVector(size_t size) : currentSize(0), maxCapacity(size) {
        data = new T[maxCapacity];
    }

    // 소멸자: 메모리 해제
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: 원소 추가
    void push_back(const T& value) {
        if (currentSize < maxCapacity) {
            data[currentSize++] = value;
        }
        else {
            cout << "Vector is full. Cannot add more elements.\n";
        }
    }

    // pop_back: 마지막 원소 제거
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
        else {
            cout << "Vector is empty. Cannot remove elements.\n";
        }
    }

    // size: 현재 원소 개수 반환
    size_t size() const {
        return currentSize;
    }

    // capacity: 최대 크기 반환
    size_t capacity() const {
        return maxCapacity;
    }

    // 배열 요소 출력 (디버깅용)
    void print() const {
        for (size_t i = 0; i < currentSize; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // 기본 생성자 테스트
    SimpleVector<int> vec;
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
    }
    vec.print(); // 출력: 1 2 3 4 5 6 7 8 9 10

    vec.push_back(11); // 배열 가득참 테스트

    vec.pop_back(); // 마지막 원소 제거
    vec.print(); // 출력: 1 2 3 4 5 6 7 8 9

    cout << "Size: " << vec.size() << endl;       // 출력: Size: 9
    cout << "Capacity: " << vec.capacity() << endl; // 출력: Capacity: 10

    // 사용자 정의 크기 생성자 테스트
    SimpleVector<string> strVec(5);
    strVec.push_back("Hello");
    strVec.push_back("World");
    strVec.print(); // 출력: Hello World

    cout << "Size: " << strVec.size() << endl;       // 출력: Size: 2
    cout << "Capacity: " << strVec.capacity() << endl; // 출력: Capacity: 5

    return 0;
}
