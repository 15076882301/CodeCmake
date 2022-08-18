#ifndef REDIS_CLIENT_PTR__H__ZYS__
#define REDIS_CLIENT_PTR__H__ZYS__
#include <cpp_redis/core/client.hpp>
#include <export_dll/export_dll.h>
#include <queue>
#include <string>
#include <condition_variable>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/mutex.hpp>
#include "redis_struct/data_base/data_base.h"
YYDS_BEGIN
using queue_redis = std::queue<cpp_redis::client*>;
using queue_string = std::queue<std::string>;
struct DataBase;
struct RedisClientStruct
{
	queue_redis queue_redis;
	queue_string queue_commend;
	DataBase data;
	static boost::mutex lock_redis_queue;
	static boost::mutex lock_commend_quque;
	static boost::condition_variable condition_variable_commend;
};

struct RedisClientPtr
{
public:
	int preareJson(const std::string& filepath, std::string& out);

	RedisClientStruct* m_data = nullptr;
	int prepareConnectQueue();
public:
	~RedisClientPtr();
};

YYDS_END

#endif