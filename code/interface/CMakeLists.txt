#模块名称
project(interface)

#顶层cmake宏
include(../module.cmake)

include_directories(
	.
)

#生成dll工程
create_dll()