#ifndef REDIS__CLIENT__H__ZYS
#define REDIS__CLIENT__H__ZYS
#include <export_dll/export_dll.h>
#include <memory>
#include <string>

YYDS_BEGIN
struct RedisClientPtr;
class EXPORT_DLL RedisClient
{
public:
	RedisClient(std::string *out = nullptr);
	~RedisClient();

private:
	RedisClientPtr* m_struct = nullptr;
};
YYDS_END
#endif