cmake_minimum_required(VERSION 3.16)

project(CodigoDesafio2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CodigoDesafio2 main.cpp
    Clase_Tanque.cpp
    Clase_RedNacional.cpp
    Clase_EstacionDeServicio.cpp
    Clase_Surtidor.cpp
    Funciones.cpp
    Clase_Venta.cpp
    Funciones_.h
    ClaseVenta.h
    ClaseTanque.h
    ClaseSurtidor.h
    ClaseRedNacional.h
    ClaseEstacionDeServicio.h)

include(GNUInstallDirs)
install(TARGETS CodigoDesafio2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
