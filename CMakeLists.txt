cmake_minimum_required(VERSION 3.24)
project(M2OEP-njblanch)

set(CMAKE_CXX_STANDARD 14)

add_executable(M2OEP-njblanch
        main.cpp
        SoccerGame.h SoccerGame.cpp
        Player.h Player.cpp #FastPlayer.h FastPlayer.cpp StrikerPlayer.h StrikerPlayer.cpp
        Field.h Field.cpp
        PlayerSymbols.h
        UserInput.h UserInput.cpp
        )
