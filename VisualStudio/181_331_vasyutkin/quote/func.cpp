#include "quote.h"
#include <string>

using namespace std;

string Quote::concatenation(Quote t) //������� ����� �� ������� ������
{
	return this->_content + t.getContent();
}