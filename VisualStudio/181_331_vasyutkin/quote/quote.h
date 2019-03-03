#pragma once
#ifndef quote_H
#define quote_H
#include <iostream>
#include <string>

using namespace std;

class Quote
{
private: //принято делать атрибуты закрытыми 
	string _content; //атрибуты экземпляра класса
	string _author;
	string _date;
	string _hometown;

public:
	Quote()
	{
		_content = "Не нервничайте!"; //переменные экземпляра класса
		_author = "Автор засекречен";
		_date = "5 сенятбря 2018";
		_hometown = "Ленинград";
	}

	Quote(string content, string author, string date, string hometown) //сюда должны быть подсунуты какие-то значения внутри функции
	{
		_content = content;
		_author = author;
		_date = date;
		_hometown = hometown;
	}

	string concatenation(Quote t); //соединяем содержание циатат

	void setContent(string str)
	{
		_content = str;
	}

	string getContent()
	{
		return _content;
	}

	void print()
	{
		cout << _content << "\n";
		cout << _author << "\n";
		cout << _date << "\n";
		cout << _hometown << "\n" "\n";
	}
};

#endif //PCH_H