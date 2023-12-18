file(GLOB HDRS CONFIGURE_DEPENDS "*.h")
file(GLOB SRCS CONFIGURE_DEPENDS "*.cpp")

add_library(CppParser
        ${HDRS}
        ${SRCS}
)

target_include_directories( CppParser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory( CppParser )

target_link_libraries(CppParser PUBLIC ClassTree parsers )
target_link_libraries(CppParser PRIVATE cppparser gcov)

