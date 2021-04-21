#pragma once

#ifndef PACMAN_APP_H
#define PACMAN_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace finalproject {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
class PacmanApp : public ci::app::App {
 public:
  /**
   * Default constructor for ideal gas app.
   */
  PacmanApp() = default;

  void setup() override;
  void draw() override;
  void update() override;
  void keyDown(cinder::app::KeyEvent event) override;

 private:

};

}  // namespace finalproject

#endif  // PACMAN_APP_H
