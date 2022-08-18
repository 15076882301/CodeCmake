#include "redis_client_ptr.h"
#include <fstream>
#include <export_dll/export_dll.h>
#include <boost/json.hpp>
#include <boost/json/parse.hpp>
#include <boost/filesystem/fstream.hpp> 
#include <boost/thread.hpp>

YYDS_BEGIN

boost::condition_variable RedisClientStruct::condition_variable_commend;
boost::mutex RedisClientStruct::lock_commend_quque;

RedisClientPtr::~RedisClientPtr()
{
	if (m_data != nullptr)
	{
		DELETE_PTR(m_data)
	}
}

int RedisClientPtr::preareJson(const std::string& fiiepath, std::string& out)
{
	using fstreamd = boost::filesystem::fstream;
	using stringd = std::string;
	fstreamd fos;
	fos.open(fiiepath.c_str(),std::ios::in);
	if (!fos.is_open())
	{
		return -1;
	}

	stringd str;
	while (!fos.eof())
	{
		stringd ss;
		fos >> ss;
		str.append(ss);
	}
	fos.close();
	
	boost::json::string_view stringview(str.c_str());
	boost::json::value json_val_t;
	std::cout << stringview << std::endl;
	try
	{
		json_val_t = boost::json::parse(stringview);
	}
	catch (const std::exception& exces)
	{
		std::cout << exces.what() << std::endl;
	}
	
	if (!json_val_t.is_object())
	{
		return -1;
	}

	return 0;
}

int RedisClientPtr::prepareConnectQueue()
{
	using redis_client = cpp_redis::client;
	DELETE_PTR_EUQAL_NULLPTR(m_data);
	
	for (uint64_t i = 0; i < m_data->data.max_connext; i++)
	{
		redis_client* client = new cpp_redis::client();
		client->connect(
			m_data->data.ip_port.ip,
			m_data->data.ip_port.port,
			[&](const std::string& ip, size_t port, cpp_redis::connect_state status)->void
			{
				if (cpp_redis::connect_state::ok == status)
				{
					m_data->queue_redis.push(client);
					m_data->data.current_valubal_connect++;
				}
			}
			);

	};

	return 0;
}

YYDS_END