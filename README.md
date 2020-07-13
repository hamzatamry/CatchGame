# catch-game

  # Game Presentation:
  
    A simple multiplayer offline game developped with C++ and SDL2.

    Each player controls a square. The red one try to touch the blue one before time reaches two minutes. If the blue one could hold for 2 minutes without being touched he wins. 

      How the red square move ?
        z: up.
        d: right.
        q: left.

     How the red square move ?
        key_up: up.
        key_right: right.
        key_left: left.

After cloning the project. you need to install SDL2 with SDL2_ttf and SDL2_image extensions.

To compile it and generate the executable file, navigate firstly inside the project and type this command:
  
    g++ *.cpp -o game -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -mwindows

To run it type this command 
    
    linux: ./game
    windows: game
    
or simply double click on the excecutable file.

# Download link: [catchMe](http://www.mediafire.com/file/jixlpi3tgu8ek1e/CatchMe.rar/file).

ENJOY IT.

