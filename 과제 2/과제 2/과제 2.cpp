#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void makesound() = 0;
	virtual ~Animal() {}
};

class dog : public Animal
{
public:
	void makesound() {
		cout << "Dog woofs : Woof!" << endl;
	}
};

class cat : public Animal
{public:
	void makesound() {
		cout << "Cat meows : Meow~" << endl;
} };

class Cow : public Animal
{
public:
	void makesound() {
		cout << "Cow moos : Mooo~!" << endl;
	}
};

int main() {
	
    const int a = 3;
    Animal* animals[a];

    // 각 동물 객체를 Animal 포인터 배열에 추가
    animals[0] = new dog();
    animals[1] = new cat();
    animals[2] = new Cow();

    // 배열 순회하며 동물의 소리를 출력
    for (int i = 0; i < a; i++) {
        animals[i]->makesound();
    }

    // 동적 할당된 메모리 해제
    for (int i = 0; i < a; i++) {
        delete animals[i];
    }

    return 0;
}
