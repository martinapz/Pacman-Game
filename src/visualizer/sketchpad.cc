#include <visualizer/sketchpad.h>
#include <string>

namespace finalproject {

namespace visualizer {

using glm::vec2;

Sketchpad::Sketchpad(const vec2& top_left_corner, size_t num_pixels_per_side,
                     double sketchpad_size, double brush_radius)
    : top_left_corner_(top_left_corner),
      num_pixels_per_side_(num_pixels_per_side),
      pixel_side_length_(sketchpad_size / num_pixels_per_side) {}

void Sketchpad::draw() const {
    for (size_t row = 0; row < num_pixels_per_side_; ++row) {
        for (size_t col = 0; col < num_pixels_per_side_; ++col) {
            //Since this is a vector of pointers, you call the draw function on the element that the pointer
            //is pointing to.
            static_elements_[row][col] -> draw(row, col);
        }
    }
}

std::vector<std::vector<std::shared_ptr<StaticElement>>>& Sketchpad::GetStaticElements() {
    return static_elements_;
}

void Sketchpad::SetStaticElements(std::vector<std::vector<std::shared_ptr<StaticElement>>> elements) {
    static_elements_ = elements;
}

}  // namespace visualizer

}  // namespace finalproject
