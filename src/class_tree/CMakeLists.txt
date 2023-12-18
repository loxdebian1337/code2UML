file(GLOB_RECURSE HDRS CONFIGURE_DEPENDS "*.h")
file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS "*.cpp")

add_library(ClassTree
        ${HDRS}
        ${SRCS}
)


set_target_properties(ClassTree PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories( ClassTree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

