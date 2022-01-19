set(controller_SRC
  Passthrough.cpp
)

set(controller_HDR
  Passthrough.h
)

add_controller(${PROJECT_NAME} ${controller_SRC} ${controller_HDR})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DPassthrough_EXPORTS")

