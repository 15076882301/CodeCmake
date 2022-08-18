cmake_minimum_required(VERSION 3.1)

project(test)

include(./module.cmake)
#初始化一些变量和输出文件的路径
init_value()
#设置cxx14标准
ctl_cxx14()
#设置包含的模块名称
set(models_project
    models/math
    models/boost_thread
	models/redis
    interface
	test
)

#设置install目录
set(CMAKE_INSTALL_PREFIX "D:/MyCode/code_pro/install")

#加载模块
foreach(sub ${models_project})
    add_subdirectory(${sub})
endforeach(sub )