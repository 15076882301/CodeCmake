#模块名称
project(redis)

#顶层cmake宏
include(../../module.cmake)

include_directories(
	.
    ../../interface
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
)

#生成dll工程
create_dll()
#create_exe()
#create_lib()

