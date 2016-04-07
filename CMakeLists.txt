cmake_minimum_required (VERSION 2.6)
project (Experiments)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH}) #SFML Package doesn't tell CMAKE how to find the lib, so FindSFML.cmake is required


find_package(SFML 2 REQUIRED system window graphics)

include_directories(${SFML_INCLUDE_DIR})



add_executable(
	Programme
	main.cpp

)

target_link_libraries(Programme ${SFML_LIBRARIES})