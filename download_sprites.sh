#!/bin/bash
cd Sprites

if [ ! -e GelBlack.gif ]; then wget http://www.videogamesprites.net/Zelda1/Enemies/Gel%20-%20Black.gif -O GelBlack.gif; fi
if [ ! -e GelGreen.gif ]; then wget http://www.videogamesprites.net/Zelda1/Enemies/Gel%20-%20Green.gif -O GelGreen.gif; fi
if [ ! -e ZolGrey.gif ]; then wget http://www.videogamesprites.net/Zelda1/Enemies/Zol%20-%20Grey.gif -O ZolGrey.gif; fi
if [ ! -e ZolGreen.gif ]; then wget http://www.videogamesprites.net/Zelda1/Enemies/Zol%20-%20Green.gif -O ZolGreen.gif; fi
if [ ! -e KeeseRed.gif ]; then wget http://www.videogamesprites.net/Zelda1/Enemies/Keese%20-%20Red.gif -O KeeseRed.gif; fi
if [ ! -e KeeseBlue.gif ]; then wget http://www.videogamesprites.net/Zelda1/Enemies/Keese%20-%20Blue.gif -O KeeseBlue.gif; fi
if [ ! -e PatraRed.gif ]; then wget http://www.videogamesprites.net/Zelda1/Enemies/Patra%20-%20Red.gif -O PatraRed.gif; fi
if [ ! -e PatraBlue.gif ]; then wget http://www.videogamesprites.net/Zelda1/Enemies/Patra%20-%20Blue.gif -O PatraBlue.gif; fi

# Blue
if [ ! -e LinkBlueFrontSmallShield.gif ]; then wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Front%291.gif -O LinkBlueFrontSmallShield.gif; fi
if [ ! -e LinkBlueFrontSmallShield.gif ]; then wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Front%291.gif -O LinkBlueFrontSmallShield.gif; fi
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Front%292.gif -O LinkBlueFrontBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Left%291.gif -O LinkBlueLeftSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Left%292.gif -O LinkBlueLeftBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Back%29.gif -O LinkBlueBack.gif

# Green
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Front%291.gif -O LinkGreenFrontSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Front%292.gif -O LinkGreenFrontBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Left%291.gif -O LinkGreenLeftSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Left%292.gif -O LinkGreenLeftBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Back%29.gif -O LinkGreenBack.gif

# Overworld

if [ ! -e LinkBlueFrontSmallShield.gif ]; then wget http://www.spriters-resource.com/resources/sheets/8/8375.png -O OverworldAll32.png; fi
if [ ! -e DungeonsAll32.gif ]; then wget http://www.spriters-resource.com/resources/sheets/8/8376.gif -O DungeonsAll32.gif; fi

# Red
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Front%291.gif -O LinkRedFrontSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Front%292.gif -O LinkRedFrontBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Left%291.gif -O LinkRedLeftSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Left%292.gif -O LinkRedLeftBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Back%29.gif -O LinkRedBack.gif

# Triforce
wget http://www.videogamesprites.net/Zelda1/Objects/Triforce%20-%20Ground1.gif -O TriforceGround1.gif
wget http://www.videogamesprites.net/Zelda1/Objects/Triforce%20-%20Ground2.gif  -O TriforceGround2.gif
