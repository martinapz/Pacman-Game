#pragma once

#include <types.h>
#include "cinder/gl/gl.h"
#include "elements/element_interfaces.h"

using namespace finalproject::elements;

namespace finalproject {

namespace visualizer {

/**
 * TODO write comment
 */
class Sketchpad {
 public:

  Sketchpad() = default;

  Sketchpad(const glm::vec2& top_left_corner, size_t num_pixels_per_side,
            double sketchpad_size, double brush_radius = 1.15);


  void draw() const;

  void HandleBrush(const glm::vec2& brush_screen_coords);


  void Clear();

  void SetStaticElements(std::vector<std::vector<std::shared_ptr<StaticElement>>> static_elements);

  std::vector<std::vector<std::shared_ptr<StaticElement>>> GetStaticElements();

 private:
  glm::vec2 top_left_corner_;

  size_t num_pixels_per_side_;

  /** Number of screen pixels in the width/height of one sketchpad pixel */
  double pixel_side_length_;

  double brush_radius_;

  std::vector<std::vector<std::shared_ptr<StaticElement>>> static_elements_;
};

}  // namespace visualizer

}  // namespace finalproject
