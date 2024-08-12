#pragma once

#include "SLL.h"

int main()
{
	SLL s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(3);
	s.Insert(4);
	s.Insert(5);
	s.print();
	s.Delete(3);
	s.print();
	s.Delete(5);
	s.print();


	return 0;
}
