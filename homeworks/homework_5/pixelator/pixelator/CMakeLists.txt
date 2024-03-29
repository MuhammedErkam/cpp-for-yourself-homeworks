# TODO: Add your libraries here
# You must have the following libraries:
# - stb_image_data_view
# - drawer
# - image
# - pixelate_image

add_library(size_str INTERFACE)
target_link_libraries(size_str INTERFACE cxx_setup)

add_library(stb_image_data_view INTERFACE)
target_link_libraries(stb_image_data_view INTERFACE size_str cxx_setup ftxui::screen stb::stb)

add_library(image INTERFACE)
target_link_libraries(image INTERFACE size_str cxx_setup ftxui::screen)

add_library(pixelate_image INTERFACE)
target_link_libraries(pixelate_image INTERFACE image stb_image_data_view)

add_library(drawer INTERFACE)
target_link_libraries(drawer INTERFACE image ftxui::screen)

if (BUILD_TESTING) 
    add_executable(image_test image_test.cpp)
    target_link_libraries(image_test PRIVATE cxx_setup image ftxui::screen GTest::gtest_main)

    add_executable(stb_image_data_view_test stb_image_data_view_test.cpp)
    target_link_libraries(stb_image_data_view_test PRIVATE cxx_setup stb_image_data_view stb::stb ftxui::screen GTest::gtest_main)

    add_executable(pixelate_image_test pixelate_image_test.cpp)
    target_link_libraries(pixelate_image_test PRIVATE cxx_setup pixelate_image stb::stb ftxui::screen GTest::gtest_main)

    add_executable(drawer_test drawer_test.cpp)
    target_link_libraries(drawer_test PRIVATE cxx_setup drawer stb::stb ftxui::screen GTest::gtest_main)
    
    include(GoogleTest) 

    gtest_discover_tests(image_test) 
    gtest_discover_tests(stb_image_data_view_test) 
    gtest_discover_tests(pixelate_image_test) 
    gtest_discover_tests(drawer_test) 

endif()