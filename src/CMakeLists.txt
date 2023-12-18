target_sources(code2UML PRIVATE main.cpp)

target_include_directories(code2UML PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(class_tree)
target_link_libraries(code2UML PRIVATE ClassTree)

add_subdirectory(parsers)
target_link_libraries(code2UML PRIVATE parsers CppParser )

