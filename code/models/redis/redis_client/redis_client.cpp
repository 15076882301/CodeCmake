#include "redis_client.h"
#include "redis_client_ptr.h"
#include <boost/filesystem.hpp>


YYDS_BEGIN

RedisClient::RedisClient(std::string* out)
{
	if (out == nullptr)
	{
		exit(-1);
	}
	m_struct = new RedisClientPtr;
	
	int result = m_struct->preareJson(boost::filesystem::current_path().string() + "/config/redis_db.config",*out);
	DELETE_PTR_FUNCTION_ERROR(result, m_struct);
}
RedisClient::~RedisClient()
{

}

YYDS_END