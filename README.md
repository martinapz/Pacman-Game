# Overview

    I created the Pacman game. I have created two levels for the user to play through, and if they
    complete both of these levels then they win the game. The pacman has three lives throughout the 
    whole game, so if it is eaten be the ghosts three times, then the user loses. The user passes
    a level once the pacman eats all the coins on the board. Additionally, there are immunity coins 
    throughout the board. When the pacman passes through a tile with an immunity, the pacman is 
    immune to the ghosts for a certain period of time. 

# Requirements

    This project requires Cinder to run the program. 

# Installation

    The steps for installation are as follows: 
        1. git clone https://github.com/uiuc-sp21-cs126/final-project-martinapz
        2. Open in CLion or a similar IDE
        3. Run the program 

# Code Style

    For this project, I used the Google C++ Style Guide. 

# Demo

    The first demo shows a full run through of the game. 
    https://youtu.be/-sWwgRgHmlA

    The next demo shows the ghost movement and pacman movement. This example shows the score being updated, 
    the level the user is on being displayed, as well as the lives the pacman has left (the life its currently 
    on minus one). This example shows the pacman being eaten by a ghost and then restarting that same level 
    once the key 'p' is pressed. 
    
    pacman eaten by ghost:
    https://user-images.githubusercontent.com/69597141/116950073-9a861280-ac49-11eb-9865-5a4b6cb4edd2.mp4
    
    The next demo shows the pacman passing by an immunity tile. The ghosts become a different color, and the 
    pacman is able to pass by the ghost without losing a life.
    
    pacman passing immunity tile: 
    https://user-images.githubusercontent.com/69597141/116950278-1ed89580-ac4a-11eb-9f24-e4687c09ab98.mp4
