cmake_minimum_required(VERSION 3.28)

project(Skatepark VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions(UNICODE _UNICODE WIN32_LEAN_AND_MEAN)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/skatepark/include)
include_directories(${CMAKE_SOURCE_DIR}/library/glm)
include_directories(${CMAKE_SOURCE_DIR}/library/glew/include)
include_directories(${CMAKE_SOURCE_DIR}/library/freeglut/include)

file(GLOB SRC_FILES skatepark/src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/skatepark/include)

set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/resource)
set(FREEGLUT_DIR ${CMAKE_SOURCE_DIR}/library/freeglut)
set(GLEW_DIR ${CMAKE_SOURCE_DIR}/library/glew)

target_link_libraries(${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${FREEGLUT_DIR}/lib/x64/freeglut.lib
    ${GLEW_DIR}/lib/Release/x64/glew32.lib
)

include_directories("${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${FREEGLUT_DIR}/bin/x64/freeglut.dll"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLEW_DIR}/bin/Release/x64/glew32.dll"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>"

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${RESOURCE_DIR}"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resource"
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
)

install(FILES
    "${FREEGLUT_DIR}/bin/x64/freeglut.dll"
    "${GLEW_DIR}/bin/Release/x64/glew32.dll"
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)

install(DIRECTORY "${RESOURCE_DIR}/"
    DESTINATION ${CMAKE_INSTALL_PREFIX}/resource
    FILES_MATCHING PATTERN "*"
)