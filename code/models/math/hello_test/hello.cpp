#include "hello.h"
#include <iostream>
void Hello::start()
{
	std::cout << "start" << std::endl;
}

void Hello::run()
{
	std::cout << "run" << std::endl;
}

void Hello::close()
{
	std::cout << "close" << std::endl;
}