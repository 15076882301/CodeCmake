#ifndef REDIS_CLIENT_PTR__H__ZYS__
#define REDIS_CLIENT_PTR__H__ZYS__
#include <cpp_redis/core/client.hpp>
#include <export_dll/export_dll.h>
#include <queue>
#include <boost/thread/mutex.hpp>
#include "redis_struct/data_base/data_base.h"
YYDS_BEGIN
using queue_redis = std::queue<cpp_redis::client*>;
struct DataBase;
struct RedisClientStruct
{
	queue_redis queue;
	DataBase data;
	static boost::mutex lock_queue;
};

struct RedisClientPtr
{
public:
	int preareJson(const std::string& filepath, std::string& out);

	RedisClientStruct* m_data = nullptr;
public:
	~RedisClientPtr();
};

YYDS_END

#endif