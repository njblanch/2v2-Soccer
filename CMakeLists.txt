cmake_minimum_required(VERSION 3.24)
project(M2OEP-njblanch)

set(CMAKE_CXX_STANDARD 14)

add_executable(M2OEP-njblanch
        main.cpp SoccerGame.h Player.h Field.h SoccerGame.cpp Field.cpp Player.cpp PlayerSymbols.h)
