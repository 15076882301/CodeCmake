#ifndef DATA_BASE__H__ZYS
#define DATA_BASE__H__ZYS
#include <redis_struct/net/net.h>
#include <ostream>
YYDS_BEGIN

struct DataBase
{
	enum class Status
	{
		Run = 0,
		NO_CONNECT_NUMBER = -1,
		ERROR = -2
	};

	using stdos = std::ostream;

	IpPort ip_port;  //ip and port
	std::string user_name; // user name
	std::string user_password; // user password
	std::string data_base_name; // database name
	uint64_t max_connext = 255; // max connect
	uint64_t current_valubal_connect = 0;// current valubal connect
	Status status; //connect status

	friend stdos& operator <<(stdos& out, const DataBase& other)
	{
		out << "Data base name : " << other.data_base_name << std::endl
			<< "User name : " << other.user_name << std::endl
			<< "User password : " << other.user_password << std::endl
			<< "Max  connect : " << other.max_connext << std::endl
			<< "Connect to : " << other.ip_port << std::endl;
	}
};

YYDS_END
#endif