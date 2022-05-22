#include <iostream>
using namespace std;

// EBook is a Book -> ��Ӱ���
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
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
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
		cout << "����Ű: " << DMRKey << endl;
	}
	~EBook() {
		delete[] DMRKey;
	}

};

int main() {
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}

