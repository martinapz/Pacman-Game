#include "pacman_app.h"

using finalproject::PacmanApp;


void prepareSettings(PacmanApp::Settings* settings) {
  settings->setTitle( "PacMan" );
  settings->setWindowSize( 900, 900);
  settings->setFrameRate (5);
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(PacmanApp, ci::app::RendererGl, prepareSettings);
