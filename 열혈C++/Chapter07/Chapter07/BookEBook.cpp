#include <iostream>
using namespace std;

// EBook is a Book -> 상속관계
class Book
{
private:
	char* title;
	char* isbn;
	int price;

public:
	Book(const char* _title, const char* _isbn, int _price)
		:price(_price)
	{
		title = new char[strlen(_title) + 1];
		strcpy(title, _title);

		isbn = new char[strlen(_isbn) + 1];
		strcpy(isbn, _isbn);
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class EBook :public Book
{
private:
	char* DMRKey;

public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DMRKey)
		:Book(_title, _isbn, _price)
	{
		DMRKey = new char[strlen(_DMRKey) + 1];
		strcpy(DMRKey, _DMRKey);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DMRKey << endl;
	}
	~EBook() {
		delete[] DMRKey;
	}

};

int main() {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}

