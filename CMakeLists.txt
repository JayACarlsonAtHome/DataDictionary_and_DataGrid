cmake_minimum_required(VERSION 3.6)
project(DataDictionary_and_DataGrid)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
    LICENSE main.cpp DataDictionary.cpp DataDictionary.h DataColumnHeader.cpp DataColumnHeader.h)

add_executable(DataDictionary_and_DataGrid ${SOURCE_FILES} DataDictionary.cpp DataDictionary.h DataColumnHeader.cpp DataColumnHeader.h)