# Pokemon Game

This Pokemon Game was created as a project for my software engineering class, its main goal is using my knowlwdge in c++ to build something visual and that can be used by an user like a videogame. Another main goal of this project is learninh how to properly use classes in c++. 
This video gamea is a “simulation” that involves Pokemon battles consisting of objects located in a two-dimensional world that move around and behave in various ways. The user enters commands to tell the objects what to do, and they behave in simulated time. Time is frozen when the user enter command and it then advance ont tick at the time when the user is playing. 

How to Play:
You are a Pokemon Trainer. You are trying to defeat the gyms but you need your Pokemon to stay healthy. You must go to gyms and earn experience by battling. However, you also need to periodically get potions if you want to make sure your Pokemon don’t faint. You “win” the game by defeating all the gyms without having your Pokemon faint. 

How to install:
Install all the file in the same environemnt, then run the makefile on the terminal and the game should start. 

How to use:
Here is a description of the commands and their input values:
-m ID x y, "move": command Trainer ID to move to location (x, y)
-c ID1 ID2, "move towards a PokemonCenter”: command Trainer ID1 to start heading to
-PokemonCenter ID2., g ID1 ID2, “move towards a PokemonGym”: command Trainer ID1 to start heading towards
PokemonGym ID2.
-s ID, "stop": command Trainer ID to stop doing whatever it is doing
-p ID potion_amount, “buy potions”: command Trainer ID to buy potion_amount of potion at a PokemonCenter.
-b ID battle_amount, “complete battle_amount battles at a PokemonGym”: command Trainer ID toomplete battle_amount of battles at a PokemonGym.
-a, "advance": advance one-time step by updating each object once.
-r, "run": advance one-time step and update each object, and repeat until either the update function returns true for at least one of the objects, or 5 time steps have been done.
- q, "quit": terminate the program


