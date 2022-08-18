#include "condition_variable_extern.h"
#include <iostream>
#include "condition_variable_test.h"


void ConditionVariableTest::thread_one()
{
	FOR_BEGIN
	{
		boost::unique_lock<boost::mutex> lock(mutex_first);
		while (first.size() == 0)
		{
			condition_val.wait(lock);
		}
		std::cout << "task 1 : " << first.front() << std::endl;
		first.pop();
	};
	FOR_END
	boost::this_thread::interruption_point();
}

void ConditionVariableTest::thread_tow()
{
	FOR_BEGIN
	{
		boost::unique_lock<boost::mutex> lock(mutex_second);
		while (second.size() == 0)
		{
			condition_val.wait(lock);
		}
		std::cout << "task 2 : " << second.front() << std::endl;
		second.pop();
	};
	FOR_END
	boost::this_thread::interruption_point();
}

void ConditionVariableTest::thread_three()
{
	
	static int i = 0;
	static int j = 100;
	FOR_BEGIN
	{
		std::string ch;
	//ch = std::to_string(std::getline());
	std::cin >> ch;
	if (ch == "first")
	{
		{
			boost::unique_lock<boost::mutex> lock(mutex_first);
			first.push(std::to_string(i++));
			first.push(std::to_string(i++));
			first.push(std::to_string(i++));
		}
		condition_val.notify_all();


	}
	else if (ch == "second")
	{
		{
			boost::unique_lock<boost::mutex> lock(mutex_second);
			second.push(std::to_string(j++));
			second.push(std::to_string(j++));
			second.push(std::to_string(j++));
		}
		condition_val.notify_all();

	}
	else if (ch == "exit")
	{
		for(auto & x : thread)
		{
			x->interrupt();
		}
		boost::this_thread::interruption_point();
	}
	};
	FOR_END;
	
}

void YYDS::function_strat()
{
	ConditionVariableTest test;
	test.start();
}

void ConditionVariableTest::start()
{


	std::cout << "Hello World Export Dll Function" << std::endl;

	thread.push_back(new boost::thread(&ConditionVariableTest::thread_one, this));
	thread.push_back(new boost::thread(&ConditionVariableTest::thread_tow, this));
	thread.push_back(new boost::thread(&ConditionVariableTest::thread_three, this));

}

ConditionVariableTest::~ConditionVariableTest()
{
	for (auto& x : thread)
	{
		x->join();
		delete x;
		x = nullptr;
	}
	thread.clear();
}