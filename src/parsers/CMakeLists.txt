file(GLOB HDRS CONFIGURE_DEPENDS "*.h")
file(GLOB SRCS CONFIGURE_DEPENDS "*.cpp")

add_library(parsers
        ${HDRS}
        ${SRCS}
)

set_target_properties(parsers PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories( parsers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries( parsers PUBLIC ClassTree )

add_subdirectory( cpp_parser )

