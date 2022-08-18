#ifndef CONTION__VARIABLE_TEST__H__ZYS
#define CONTION__VARIABLE_TEST__H__ZYS
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <queue>
#include <string>
#include <list>

using boost_mutex = boost::mutex;
using task_queue = std::queue<std::string>;
using condition_value_ctl = boost::condition_variable;
class ConditionVariableTest
{
public:
	void thread_one();
	void thread_tow();
	void thread_three();
	void start();
	~ConditionVariableTest();
private:
	task_queue first;
	task_queue second;

	boost_mutex mutex_first;
	boost_mutex mutex_second;

	condition_value_ctl condition_val;
	std::list<boost::thread*> thread;

};
#endif