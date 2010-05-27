add_definitions("-DPACKAGE_VERSION=\"0.1\"")

include_directories(${QORE_INCLUDE_DIR} )


set(dummy_LIB_SRCS
    dummy-module.cpp
)

SET (module_name "dummy")

add_library(${module_name} SHARED ${dummy_LIB_SRCS})
set_target_properties(${module_name} PROPERTIES PREFIX "" SUFFIX "-api-${QORE_API_VERSION}.qmod")

target_link_libraries(${module_name} ${QORE_LIBRARY} )

install( TARGETS ${module_name} DESTINATION ${QORE_MODULES_DIR})
