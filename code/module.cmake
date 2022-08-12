#定义分组宏定义
macro(source_group_by_dir)
    if(MSVC)
        set(sgdb_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(sgdb_file ${CUR_DIRS})
            string(REGEX REPLACE ${sgdb_cur_dir}/\(.*\) \\1 sgdb_fpath ${sgdb_file})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgdb_group_name ${sgdb_fpath})
            string(COMPARE EQUAL ${sgdb_fpath} ${sgdb_group_name} sgdb_nogroup)
            string(REPLACE "/" "\\" sgdb_group_name ${sgdb_group_name})
            if(sgdb_nogroup)
                set(sgdb_group_name "\\")
            endif(sgdb_nogroup)
            source_group(${sgdb_group_name} FILES ${sgdb_file})
        endforeach(sgdb_file)
    endif(MSVC)
endmacro(source_group_by_dir)


#将扩展名为下列所示的文件添加到项目中
macro(find_cur_all_files)

    file(GLOB_RECURSE CUR_DIRS
        "*.h"
        "*.cpp"
        "*.ui"
        "*.hpp"
        "*.cc"
        "*.cxx"
        "*.ipp"
    )
endmacro(find_cur_all_files)

#将添加QT依赖
macro(depends_qt)
    file(GLOB_RECURSE UI_FILES ${PROJECT_SOURCE_DIR}/*.ui)
    set(DIR_SRCS ${DIR_SRCS} ${UI_FILES})
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${Qt5_DIR})
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(QT_LIBRARIES Core Concurrent Gui Xml Sql Svg Widgets Network)
    find_package(Qt5 REQUIRED ${QT_LIBRARIES})
endmacro(depends_qt)

#内部链接库，qt或者其他  thrid_party_libraries
macro(load_dll_lib)
    foreach(qt_library ${QT_LIBRARIES})
        target_link_libraries(${PROJECT_NAME} ${qt_library})
        message("-- ${PROJECT_NAME}  --->  添加链接库          ${qt_library}")
    endforeach(qt_library)

    foreach(thrid_party_library ${thrid_party_libraries})
        target_link_libraries(${PROJECT_NAME} ${thrid_party_library})
        message("-- ${PROJECT_NAME}  --->  添加链接库          ${thrid_party_library}")
    endforeach()
endmacro(load_dll_lib)

# 创建exe
macro(create_exe)
    find_cur_all_files()
    source_group_by_dir()
    include_directories_dir()
    add_executable(${PROJECT_NAME} ${CUR_DIRS})
    load_dll_lib()
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})    
    set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_deug")    
    set_install()
    message("-- ${PROJECT_NAME}  --->  完成创建            最终生成可执行文件")
    message("     ")
endmacro(create_exe)

#创建dll
macro(create_dll)
    find_cur_all_files()
    source_group_by_dir()
    include_directories_dir()
    add_library(${PROJECT_NAME} SHARED ${CUR_DIRS})
    load_dll_lib()
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})    
    set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_deug_dll")    
    set_install()
    message("-- ${PROJECT_NAME}  --->  完成创建            最终生成动态库")
    message("     ")
endmacro(create_dll)

#创建lib
macro(create_lib)
    find_cur_all_files()
    source_group_by_dir()
    include_directories_dir()
    add_library(${PROJECT_NAME} ${CUR_DIRS})
    load_dll_lib()
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})    
    set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_deug_lib")     
    set_install()
    message("-- ${PROJECT_NAME}  --->  完成创建            最终生成静态库")
    message("     ")
endmacro(create_lib)

#设置c11标准
macro(crt_cxx11)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endmacro(crt_cxx11)

#设置c14标准
macro(ctl_cxx14)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endmacro(ctl_cxx14)

#输出文件路径
macro(out_part)
    if(CMAKE_CL_64)
        set(out_dir X64)
    else()
        set(out_dir X86)
    endif()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_ROOT_DIR}/target/${out_dir}/bin/debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_ROOT_DIR}/target/${out_dir}/bin/release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_ROOT_DIR}/target/${out_dir}/bin/debug)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_ROOT_DIR}/target/${out_dir}/bin/release)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_ROOT_DIR}/target/${out_dir}/bin/debug)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_ROOT_DIR}/target/${out_dir}/bin/release)
    message(STATUS "生成文件路径  --->  ${PROJECT_ROOT_DIR}/target/${out_dir}/bin")
endmacro(out_part)

#初始化工程
macro(init_value)
    string(REGEX REPLACE "(.*)/(.*)" "\\1" CMAKE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    set(PROJECT_ROOT_DIR ${CMAKE_ROOT_DIR})
    set(THRID_PARTY ${PROJECT_ROOT_DIR}/thrid_party)
    out_part()
endmacro(init_value)

#rpc宏定义
macro(rpc_define)
    add_definitions(-D_WIN32_WINNT=0x0A00)    
endmacro(rpc_define)

# 字符集
macro(unicode_set)
    add_definitions(-DUNICODE -D_UNICODE)    
endmacro(unicode_set)


# 包含第三方库有文件
macro(include_directories_dir)
    foreach(include_dir ${include_dirs})
        include_directories(${THRID_PARTY}/${include_dir}/include)
        link_directories(${THRID_PARTY}/${include_dir}/lib)
        message("-- ${PROJECT_NAME}  --->  添加头文件包含目录  ${THRID_PARTY}/${include_dir}/include")
        message("-- ${PROJECT_NAME}  --->  添加链接库包含目录  ${THRID_PARTY}/${include_dir}/lib")
    endforeach(include_dir)
endmacro(include_directories_dir)

macro(set_install)
INSTALL(TARGETS ${PROJECT_NAME}
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION libstatic
)
endmacro(set_install)