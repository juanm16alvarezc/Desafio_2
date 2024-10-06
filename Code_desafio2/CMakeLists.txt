cmake_minimum_required(VERSION 3.16)

project(Code_desafio2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Code_desafio2 main.cpp
    FuncionesD2.cpp
    ClasesD2.cpp
    Funciones_Clases.h)

include(GNUInstallDirs)
install(TARGETS Code_desafio2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
