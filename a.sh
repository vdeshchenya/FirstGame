#!/bin/bash

sudo g++ Game.cpp Menu_scene.cpp Scene_manager.cpp main.cpp Scene.cpp Quad.cpp Point.cpp MainPlayer.cpp Game_scene.cpp Block.cpp BlockPlayer.cpp List.cpp -c
sudo g++ Game.o Menu_scene.o Scene_manager.o main.o Scene.o Quad.o Point.o MainPlayer.o Game_scene.o Block.o BlockPlayer.o List.o -o a.out -lsfml-graphics -lsfml-window -lsfml-system
sudo ./a.out
