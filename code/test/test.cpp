#include <redis/redis_client/redis_client.h>
int main()
{
	{
		std::string out;
		using YYDS_REDIS = YYDS::RedisClient;

		YYDS_REDIS redisc(&out);
	}
	return 0;
}