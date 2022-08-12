#ifndef NET__WORK__H__
#define NET__WORK__H__
#include <export_dll/export_dll.h>
#include <string>
#include <ostream>
YYDS_BEGIN

struct IpPort
{
	using stdos = std::ostream;
	std::string ip = "127.0.0.1";
	uint32_t port = 8090;
	friend stdos& operator << (stdos& out, const IpPort& other)
	{
		out << other.ip << ":" << std::to_string(other.port);
		return out;
	}
};

YYDS_END
#endif