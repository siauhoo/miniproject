cmake_minimum_required(VERSION 3.20)
project(MiniProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(MiniProject main.cpp sysinfo.h Stocks.cpp Stocks.h File.cpp File.h Snapshot.cpp Snapshot.h UpdateLevel.cpp UpdateLevel.h DeleteLevel.cpp DeleteLevel.h)
