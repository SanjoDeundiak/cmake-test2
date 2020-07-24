cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(foo VERSION 0.0.1 LANGUAGES C)

add_executable(bar src/main.c)

#add_compile_definitions(OCKAM_DISABLE_LOG)
add_compile_definitions(OCKAM_CUSTOM_LOG_FUNCTION=1)

find_package(ockam QUIET)

if(NOT ockam_FOUND)
    message(STATUS "OCKAM NOT FOUND")
    include(FetchContent)
    FetchContent_Declare(ockam
        GIT_REPOSITORY https://github.com/SanjoDeundiak/cmake-test1
        GIT_TAG master)

    FetchContent_GetProperties(ockam)
    if(NOT ockam_POPULATED)
        FetchContent_Populate(ockam)
        add_subdirectory(${ockam_SOURCE_DIR} ${googletest_BINARY_DIR})
    endif()

    # https://gitlab.kitware.com/cmake/cmake/-/issues/17735
    file(WRITE ${CMAKE_BINARY_DIR}/find/ockam/ockamConfig.cmake "")
    set(ockam_DIR ${CMAKE_BINARY_DIR}/find/ockam CACHE PATH "" FORCE)
endif()


target_link_libraries(bar ockam_memory ockam_vault ockam_memory_stdlib)