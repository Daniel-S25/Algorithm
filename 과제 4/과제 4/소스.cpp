#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author));
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // 책 제목으로 검색
    void searchByTitle(const string& title) const {
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "책을 찾았습니다: " << book.title << " by " << book.author << endl;
                return;
            }
        }
        cout << "해당 제목의 책을 찾을 수 없습니다." << endl;
    }

    // 작가로 검색
    void searchByAuthor(const string& author) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.author == author) {
                if (!found) {
                    cout << "해당 작가의 책 목록:" << endl;
                }
                cout << "- " << book.title << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "해당 작가의 책을 찾을 수 없습니다." << endl;
        }
    }
};

int main() {
    BookManager manager;

    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 책 제목으로 검색" << endl;
        cout << "4. 작가로 검색" << endl;
        cout << "5. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2) {
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            string title;
            cout << "검색할 책 제목: ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            string author;
            cout << "검색할 작가 이름: ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}
