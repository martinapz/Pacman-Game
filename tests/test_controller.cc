#include <catch2/catch.hpp>
#include "controller.h"
#include "game_instructions.h"

TEST_CASE("Loading level correctly and sets up game") {
    finalproject::Controller controller;
    controller.setUpGame();
    REQUIRE(controller.getGame().number_of_coins_ == 221);
    REQUIRE(controller.getGame().pacman_.getPosition().getX() == 2);
    REQUIRE(controller.getGame().pacman_.getPosition().getY() == 10);
}

TEST_CASE("Update direction when pacman tries to change to valid direction") {
    finalproject::Controller controller;
    controller.setUpGame();
    SECTION("Moves left") {
        controller.processMove(finalproject::Direction::LEFT);
        REQUIRE(controller.getGame().pacman_.getDirection() == finalproject::Direction::LEFT);
    }
    SECTION("Moves right") {
        controller.processMove(finalproject::Direction::RIGHT);
        REQUIRE(controller.getGame().pacman_.getDirection() == finalproject::Direction::RIGHT);
    }
    SECTION("Moves down") {
        controller.processMove(finalproject::Direction::DOWN);
        REQUIRE(controller.getGame().pacman_.getDirection() == finalproject::Direction::DOWN);
    }
}

TEST_CASE("Does not update direction when pacman tries to change to invalid direction") {
    finalproject::Controller controller;
    controller.setUpGame();
    SECTION("Moves up to wall tile") {
        controller.processMove(finalproject::Direction::UP);
        REQUIRE(controller.getGame().pacman_.getDirection() == finalproject::Direction::RIGHT);
    }
}

TEST_CASE("Update position of pacman correctly") {
    finalproject::Controller controller;
    controller.setUpGame();
    controller.processAction(finalproject::Action::START);
    SECTION("Updates position correctly") {
        controller.update();
        REQUIRE(controller.getGame().pacman_.getPosition().getX() == 3);
        REQUIRE(controller.getGame().pacman_.getPosition().getY() == 10);
    }
}

TEST_CASE("Does not update position of pacman when trying to move to invalid spot") {
    finalproject::Controller controller;
    controller.setUpGame();
    SECTION("Pacman trying to move to a wall tile") {
        controller.processMove(finalproject::Direction::UP);
        controller.update();
        REQUIRE(controller.getGame().pacman_.getPosition().getX() == 2);
        REQUIRE(controller.getGame().pacman_.getPosition().getY() == 10);
    }
}

TEST_CASE("Update position when a ghost moves to a valid position") {
    finalproject::Controller controller;
    controller.setUpGame();
    controller.processAction(finalproject::Action::START);
    REQUIRE(controller.getGame().ghosts_[0].getPosition().getX() == 10);
    REQUIRE(controller.getGame().ghosts_[0].getPosition().getY() == 11);
    SECTION("Moves right") {
        // Sleep for 3 seconds so that ghost container door opens and allows ghosts to move.
        std::this_thread::sleep_for (std::chrono::seconds(3));
        controller.update();
        REQUIRE(controller.getGame().ghosts_[0].getPosition().getX() == 11);
        REQUIRE(controller.getGame().ghosts_[0].getPosition().getY() == 11);
    }
}

TEST_CASE("When pacman lands on coin tile, tile becomes empty"){
    finalproject::Controller controller;
    controller.setUpGame();
    REQUIRE(controller.getGame().number_of_coins_ == 221);
    controller.processAction(finalproject::Action::START);
    controller.update();
    REQUIRE(controller.getGame().number_of_coins_ == 220);
}


