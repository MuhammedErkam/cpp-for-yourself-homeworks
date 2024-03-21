#include "drawer.hpp"
#include "stb_image_data_view.hpp"
#include "pixelate_image.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

const std::filesystem::path image_path{"../../pixelator/test_data/test.png"};

using pixelator::Drawer;
using pixelator::PixelateImage;
using pixelator::StbImageDataView;

TEST(Drawer_Test, test1) {
    const std::string str = "\x1B[39m\x1B[40m  \x1B[39m\x1B[49m \r\n\x1B[39m\x1B[40m  \x1B[39m\x1B[49m \r\n\x1B[39m\x1B[107m  \x1B[39m\x1B[49m ";
    const StbImageDataView image{image_path};
    if (image.empty()) {
        std::cerr << "Image could not be loaded" << std::endl;
        exit(1);
    }
    Drawer drawer{ftxui::Dimension::Fixed(3)};
    drawer.Set(PixelateImage(image, drawer.size()));
    EXPECT_EQ(str, drawer.ToString());
}