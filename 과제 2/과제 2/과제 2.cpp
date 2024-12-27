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

    // �� ���� ��ü�� Animal ������ �迭�� �߰�
    animals[0] = new dog();
    animals[1] = new cat();
    animals[2] = new Cow();

    // �迭 ��ȸ�ϸ� ������ �Ҹ��� ���
    for (int i = 0; i < a; i++) {
        animals[i]->makesound();
    }

    // ���� �Ҵ�� �޸� ����
    for (int i = 0; i < a; i++) {
        delete animals[i];
    }

    return 0;
}
