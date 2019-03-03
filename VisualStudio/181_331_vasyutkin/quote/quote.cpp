//Lab_1 - создание простецкой приложухи(работа с классами)

#include "quote.h"
#include <iostream>
#include <string>

using namespace std;

class Quote2 :public Quote //наследование классов
{

};

int main()
{
	setlocale(LC_ALL, "Rus");

	Quote q1; //когда такое пишем вызывается конструктор всегда(только один раз)
	q1.print();
	q1.setContent("Ну не нервничайте!");
	q1.print();

	Quote q2("C++ ТОП", "Все программисты", "Никогда", "");
	q2.print();

	cout << q2.getContent() << endl << endl;

	Quote q3("xxx", "yyy", "", "");
	Quote *p = &q3;
	cout << p->getContent() << "\n" "\n";

	cout << q2.concatenation(q2) << "\n" << endl;

	Quote2 q4;
	q4.print();
}

/*
В .h объявление
В .cpp реализация
Здесь main
*/