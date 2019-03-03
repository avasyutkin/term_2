#pragma once
#ifndef quote_H
#define quote_H
#include <iostream>
#include <string>

using namespace std;

class Quote
{
private: //������� ������ �������� ��������� 
	string _content; //�������� ���������� ������
	string _author;
	string _date;
	string _hometown;

public:
	Quote()
	{
		_content = "�� �����������!"; //���������� ���������� ������
		_author = "����� ����������";
		_date = "5 �������� 2018";
		_hometown = "���������";
	}

	Quote(string content, string author, string date, string hometown) //���� ������ ���� ��������� �����-�� �������� ������ �������
	{
		_content = content;
		_author = author;
		_date = date;
		_hometown = hometown;
	}

	string concatenation(Quote t); //��������� ���������� ������

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