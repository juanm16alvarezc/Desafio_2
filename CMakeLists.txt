cmake_minimum_required(VERSION 3.16)

project(Code_desafio2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Code_desafio2 main.cpp


    Funciones_.h
    Clase_Tanque.cpp
    Clase_Venta.cpp
    Clase_RedNacional.cpp
    Clase_EstacionDeServicio.cpp
    Clase_Surtidor.cpp
    Funciones.cpp
    ClaseEstacionDeServicio.h
    ClaseRedNacional.h
    ClaseSurtidor.h
    ClaseTanque.h
    ClaseVenta.h)

include(GNUInstallDirs)
install(TARGETS Code_desafio2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
