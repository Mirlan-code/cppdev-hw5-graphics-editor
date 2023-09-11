cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION $ENV{RUN_NUMBER} CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(graphics_editor VERSION ${PROJECT_VESRION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(graphics_editor_cli main.cpp)
add_library(graphics_editor lib.cpp vector_graphics_editor.cpp vector_graphics_editor.h vector_image.cpp vector_image.h primitive.cpp primitive.h)
add_executable(test_version test_version.cpp)

set_target_properties(graphics_editor_cli graphics_editor test_version PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )
target_include_directories(graphics_editor
        PRIVATE "${CMAKE_BINARY_DIR}"
        )
set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(graphics_editor_cli PRIVATE
        graphics_editor
        )
target_link_libraries(test_version
        ${Boost_LIBRARIES}
        graphics_editor
        )

if (MSVC)
    target_compile_options(graphics_editor_cli PRIVATE
            /W4
            )
    target_compile_options(graphics_editor PRIVATE
            /W4
            )
    target_compile_options(test_version PRIVATE
            /W4
            )
else ()
    target_compile_options(graphics_editor_cli PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(graphics_editor PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(test_version PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()



install(TARGETS graphics_editor_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)