#include "quote.h"
#include <string>

using namespace std;

string Quote::concatenation(Quote t) //вынесли метод за пределы класса
{
	return this->_content + t.getContent();
}