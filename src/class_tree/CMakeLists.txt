file(GLOB HDRS CONFIGURE_DEPENDS "*.h")
file(GLOB SRCS CONFIGURE_DEPENDS "*.cpp")

add_library(ClassTree
        ${HDRS}
        ${SRCS}
)

set_target_properties(ClassTree PROPERTIES LINKER_LANGUAGE CXX)

