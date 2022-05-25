#include <iostream>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;

public:
	// ������
	Book(const char* _title, const char* _isbn, int _price)
		:price(_price)
	{
		title = new char[strlen(_title) + 1];
		strcpy(title, _title);

		isbn = new char[strlen(_isbn) + 1];
		strcpy(isbn, _isbn);
	}

	// ���� ������
	Book(const Book& ref)
		:price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);

		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}

	// ���� ������ �����ε�
	Book& operator=(const Book& ref) {
		delete[]title;
		delete[]isbn;

		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);

		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);

		price = ref.price;
		return *this;
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
	// ������
	EBook(const char* _title, const char* _isbn, int _price, const char* _DMRKey)
		:Book(_title, _isbn, _price)
	{
		DMRKey = new char[strlen(_DMRKey) + 1];
		strcpy(DMRKey, _DMRKey);
	}

	// ���� ������
	EBook(const EBook& ref)
		:Book(ref)
	{
		DMRKey = new char[strlen(ref.DMRKey) + 1];
		strcpy(DMRKey, ref.DMRKey);
	}

	// ���� ������ �����ε�
	EBook& operator=(const EBook& ref) {
		Book::operator=(ref);
		delete[]DMRKey;
		DMRKey = new char[strlen(ref.DMRKey) + 1];
		strcpy(DMRKey, ref.DMRKey);
		return *this;
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
	EBook ebook1("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;
	ebook2.ShowBookInfo();
	cout << endl;

	EBook ebook3("dumy", "dumy", 0, "dumy");
	ebook3 = ebook2;
	ebook3.ShowBookInfo();

	return 0;
}