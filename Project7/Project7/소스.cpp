#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

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
		isbn = new char[strlen(_isbn) + 1];
		strcpy(title, _title);
		strcpy(isbn, _isbn);
	}
	Book(const Book& ref)//����
		:price(ref.price)
	{
		cout << "Book(const Book& ref)" << endl;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}
	Book& operator=(const Book& ref)//����
	{
		cout << "Book& operator=(const Book& ref)" << endl;
		price = ref.price;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);

		return *this;
	}
	void ShowBookInfo()
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����" << price << endl;
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;
public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey)
		:Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy(DRMKey, _DRMKey);
	}
	EBook(const EBook& ref)//����
		:Book(ref)
	{
		cout << "EBook(const EBook& ref)" << endl;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook& operator=(const EBook& ref)//����
	{
		Book::operator=(ref);
		cout << "EBook& operator=(const EBook& ref)" << endl;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);

		return *this;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[]DRMKey;
	}
};

int main(void)
{
	Book book1("���� C++", "555-12345-890-0", 20000);
	Book book2 = book1; //���� ������
	book1 = book2;		//���� ������

	EBook ebook1("����C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;  //���� ������
	ebook1 = ebook2;		//���� ������
	return 0;
}