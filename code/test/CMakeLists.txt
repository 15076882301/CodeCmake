#模块名称
project(test)

#顶层cmake宏
include(../module.cmake)

include_directories(
	.
    ../interface
    ../models
)

#thrid_party下的包含库名称
set(include_dirs
    cpp_redis
    Boost
)

#需要链接的第三方库
set(thrid_party_libraries
    cpp_redis
    tacopie
    libboost_filesystem-vc143-mt-gd-x64-1_79
	redis
)


#生成dll工程
create_exe()
add_dependencies(
	${PROJECT_NAME}
	redis
)