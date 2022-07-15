set(EXEC server.out)

add_executable(${EXEC}
	main.cpp
)

target_link_libraries(${EXEC} PUBLIC net)
target_link_libraries(${EXEC} PUBLIC mrlog)
