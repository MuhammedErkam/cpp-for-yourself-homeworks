add_executable(use_ftxui use_ftxui.cpp)
target_link_libraries(use_ftxui PRIVATE cxx_setup ftxui::screen)

add_executable(use_stb_image use_stb_image.cpp)
target_link_libraries(use_stb_image PRIVATE cxx_setup stb::stb)

add_executable(pixelate pixelate.cpp)
target_link_libraries(pixelate PRIVATE pixelate_image stb::stb ftxui::screen)

# TODO: Add your binaries here
# There must be a binary `pixelate` here
