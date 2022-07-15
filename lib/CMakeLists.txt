set(LIB net)

add_library(${LIB} STATIC
	lib.cpp
	socket.cpp
)

target_compile_options(${LIB} PRIVATE -Wall -Wextra -Werror)
target_compile_options(${LIB} PRIVATE -Wno-unused -Wno-unused-parameter)
target_include_directories(${LIB} PUBLIC ../include)

target_link_libraries(${LIB} PUBLIC mrlog)
