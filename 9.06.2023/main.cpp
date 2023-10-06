#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <io.h>

using namespace std;

int myStrlen(char* array)
{
	int tmp{};
	while (array[tmp] != '\0')
	{
		tmp++;
	}
	return tmp;
}
2
void helloMorld(char*& string_one, char*& string_two)
{
	int size = (myStrlen(string_one) + myStrlen(string_two)) + 1;
	char* string_thr = new char[size];
	char* temp = string_thr;
	for (int i{ 0 }; i < myStrlen(string_one); i++)
	{
		*temp = *(string_one + i);
		temp++;
	}

	for (int i{ 0 }; i < myStrlen(string_two); i++)
	{
		*temp = *(string_two + i);
		temp++;
	}
	*temp = '\0';

	string_one = string_thr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Êàêîé ôàéë íóæíî íàéòè? " << endl;
	char put[256]{};
	cout << "Ïóòü " << endl;
	cin >> put;
	char rashir[256]{};
	cout << "Ðàñøèðåíèå " << endl;
	cin >> rashir;
	char* tmp_one = put;
	char* tmp_two = rashir;

	helloMorld(tmp_one, tmp_two);

	strcat_s(tmp_one, 256, tmp_two); // òîæå êîíêàòåíàöèÿ

	_finddata_t fileinfo{}; // ñòðóêòóðà èç Ñ++
	intptr_t ptr = _findfirst(tmp_one, &fileinfo); // ïîèñê ôàéëîâ
	cout << fileinfo.name << endl;

	while (_findnext(ptr, &fileinfo) != -1) //âûâîä âñåõ ñëåäóþùèõ ôàéëîâ
	{
		cout << fileinfo.name << endl;
	}

	return 0;
}
