cmake_minimum_required(VERSION 3.24)
project(Effecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Effecto main.cpp
               filter/tfilter.cpp filter/tfilter.h
               gui/buttons/tbuttons.cpp gui/buttons/tbuttons.h
               gui/textboxes/textbox.cpp gui/textboxes/textbox.h
               gui/gui.cpp gui/gui.h resources/tsample.h
               gui/tpage.cpp gui/tpage.h)

set(SFML_STATIC_LIBRARIES TRUE)

add_link_options("-lsfml-graphics", "-lsfml-window", "-lsf
# ml-system", "-lsfml-audio")

set(SFML_DIR /usr/lib/cmake/SFML)

include_directories(/usr/include/SFML)
target_link_libraries(Effecto sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsf
# ml-system -lsfml-audio