#include <redis/redis_client/redis_client.h>
#include <boost/dll.hpp>
#include <iostream>
#include <math/hello_test/hello.h>
#define DLL_CONDI 1
#define DLL_MATH 1
#define DLL_REDIS 0
int main()
{
#if DLL_REDIS
	{
		std::string out;
		using YYDS_REDIS = YYDS::RedisClient;

		YYDS_REDIS redisc(&out);
		END_OF(for)
	}
#elif DLL_CONDI
	using void_function_void = void(*)(void);
	using boost_dll_shared = boost::dll::shared_library;
	void_function_void func;
	boost_dll_shared lib(R"(D:\MyCode\code_pro\target\X64\bin\debug\condition_variable_test_deug_dll.dll)");
	if (lib.has(R"(function_strat)"))
	{
		std::cout << "load library successful" << std::endl;
		try {
			//func = lib.get<void(void)>("function_strat");
			func = lib.get<void (void)>("function_strat");
			//__stdcall
		}
		catch (const std::exception& exceptions)
		{
			std::cout << exceptions.what() << std::endl;
		}
		func();
	}
	else
	{
		std::cout << "load library error" << std::endl;
	}
#elif DLL_MATH
	

#endif
	Hello he;
	he.start();
	he.close();

	return 0;
}