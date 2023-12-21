file(GLOB_RECURSE HDRS CONFIGURE_DEPENDS "*.h")
file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS "*.cpp")

add_library(UmlGenerator
        ${HDRS}
        ${SRCS}
)

set_target_properties(UmlGenerator PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories( UmlGenerator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries( UmlGenerator PUBLIC ClassTree )