# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

add_executable(Uhr
  window.cpp
  glew.c
  Uhr.cpp
  vec2.cpp)
target_link_libraries(Uhr
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(Uhr glfw nanovg ${COPY_BINARY})
# Build tests
add_executable(tests
  tests.cpp
  vec2.cpp)
target_link_libraries(tests
  ${GLFW_LIBRARIES})


