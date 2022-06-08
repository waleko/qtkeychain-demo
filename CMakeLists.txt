cmake_minimum_required(VERSION 3.22)
project(qtkeychain_test)

set(CMAKE_CXX_STANDARD 17)

set(QT_MAJOR_VERSION 5 CACHE STRING "Qt Major Version (e.g. Qt5/Qt6)")

message("Using Qtkeychain from submodules...")
if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/third_party/qtkeychain/CMakeLists.txt)
    message(SEND_ERROR "Unable to add a dependency locally!\nHave you tried running:  git submodule update --init --recursive")
endif()

add_subdirectory(third_party/qtkeychain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt${QT_MAJOR_VERSION} REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


include_directories(${CMAKE_BINARY_DIR}
        controllers
        models
        views
        )

aux_source_directory(views VIEWS_DIR)
aux_source_directory(entities ENTITIES_DIR)

add_executable(qtkeychain_test main.cpp)

target_link_libraries(qtkeychain_test PRIVATE Qt${QT_MAJOR_VERSION}::Widgets)
target_link_libraries(qtkeychain_test PRIVATE qt${QT_MAJOR_VERSION}keychain)
target_include_directories(qtkeychain_test PRIVATE "${PROJECT_SOURCE_DIR}/third_party/qtkeychain")

add_compile_definitions(QTKEYCHAIN_NO_EXPORT)