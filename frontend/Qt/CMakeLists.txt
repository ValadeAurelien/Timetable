# Includes subdirs from here
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# All subdirs' sources
set(MAIN_WINDOW_SRC
  main_window/main_window.cpp
)

add_executable(main_frontend_qt 
  main.cpp 
  application/application.cpp 
  ${MAIN_WINDOW_SRC} 
) 

