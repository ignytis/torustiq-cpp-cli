cmake_minimum_required(VERSION 3.20)

# Read project info
file(READ project.json PROJECT_INFO)
string(JSON APP_NAME GET ${PROJECT_INFO} name)
string(JSON APP_VERSION GET ${PROJECT_INFO} version)
string(JSON APP_DESCRIPTION GET ${PROJECT_INFO} description)

string(TOLOWER ${APP_NAME} APP_NAME_LOWERCASE)

project(${APP_NAME} VERSION ${APP_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "build")

# Helps with debugging
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# cmake_policy(SET CMP0135 NEW)

# find_package(wxWidgets COMPONENTS stc aui core base REQUIRED)
find_package(CLI11 REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${APP_NAME_LOWERCASE} ${SOURCES})

# if(WIN32)
#     target_sources(${APP_NAME_LOWERCASE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/resource.rc)
# endif()

target_include_directories(${APP_NAME_LOWERCASE} PRIVATE src)
# target_link_libraries(${APP_NAME_LOWERCASE} PRIVATE wxWidgets::wxWidgets nlohmann_json::nlohmann_json)

add_compile_definitions(APP_NAME="${APP_NAME}")
add_compile_definitions(APP_VERSION="${APP_VERSION}")
add_compile_definitions(APP_DESCRIPTION="${APP_DESCRIPTION}")

set_target_properties(${APP_NAME_LOWERCASE} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

