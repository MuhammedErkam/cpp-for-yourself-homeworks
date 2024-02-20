#include "pixelate_image.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <filesystem>

//const std::filesystem::path image_path{"/home/erkam/Desktop/CppTuts/CodeForYourself/homeworks/homework5/pixelator/pixelator/test_data/test.png"};
const std::filesystem::path image_path{"../../pixelator/test_data/grumpy_little.png"};

TEST(PixelateImage, test1) {
    pixelator::Size s{98, 150};
    const pixelator::StbImageDataView image{image_path};
    const auto pixelated_image = pixelator::PixelateImage(image, s);

    bool empty = false;
    int row = 98;
    int col = 98;
    EXPECT_EQ(empty, pixelated_image.empty());
    EXPECT_EQ(row, pixelated_image.rows());
    EXPECT_EQ(col, pixelated_image.cols());

    const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};

    bool x = true;
    pixelated_image.at(4,2) = yellowish;

    const pixelator::Image image_copy{pixelated_image};

    image_copy.at(4,2) = yellowish;
    EXPECT_EQ(x, image_copy.at(4,2) == yellowish);

    const pixelator::Image image_move{std::move(pixelated_image)};

    image_move.at(4,2) = yellowish;
    EXPECT_EQ(x, image_move.at(4,2) == yellowish);
}