#include "pixelator/drawer.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include "pixelator/pixelate_image.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

const std::filesystem::path image_path{"../../pixelator/test_data/test.png"};

using pixelator::Drawer;
using pixelator::PixelateImage;
using pixelator::StbImageDataView;

TEST(Drawe_Test, test1) {
    const StbImageDataView image{image_path};
    if (image.empty()) {
        std::cerr << "Image could not be loaded" << std::endl;
        exit(1);
    }
    Drawer drawer{ftxui::Dimension::Fixed(3)};
    drawer.Set(PixelateImage(image, drawer.size()));
    EXPECT_EQ(1,1);
}