cmake_minimum_required(VERSION 3.10)

project(lib_test)

set(LIBRARY_SRC src/log.c)

include_directories("include/")

add_executable(app src/app.c)

# А можно еще и сабдиректории бахнуть для библиотек (add_subdirectory())
if (BUILD_STATIC)
    # STATIC log lib
    message("Build static")
    add_library(log STATIC ${LIBRARY_SRC})
    target_link_libraries(app log)
else ()
    # SHARED log lib
    message("Build shared")
    add_library(log SHARED ${LIBRARY_SRC})
    target_link_libraries(app log)
endif()

# Порядок линковки важен, но если лень думать в каком правильно порядке или есть циклические зависимости, то поможет -Wl
# target_link_libraries(app -Wl,--start-group -lm lib1 lib2 -Wl,--end-group)