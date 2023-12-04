file(GLOB HDRS CONFIGURE_DEPENDS "*.h")
file(GLOB SRCS CONFIGURE_DEPENDS "*.cpp")

add_library(CppParser
        ${HDRS}
        ${SRCS}
)
