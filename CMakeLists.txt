#Version minimum
cmake_minimum_required(VERSION "3.8")

#Nom du projet
project(IAProject)

#Set des fichier cpp dans le string SRC
set(SRCS main.cpp input.cpp Gui.cpp)
set(HEADER main.h input.h Gui.h)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS system window graphics network audio REQUIRED) 

#Ajout executable avec les cpp du projet et header
add_executable (IAProject ${SRCS} ${HEADER})

#target_include_directories("${NAME_PROJECT}" PUBLIC ${PNG_INCLUDE_DIR})
target_link_libraries (IAProject sfml-main sfml-system sfml-window sfml-graphics sfml-audio)


