#!/bin/bash

# Red
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Front%291.gif -O LinkRedFrontSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Front%292.gif -O LinkRedFrontBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Left%291.gif -O LinkRedLeftSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Left%292.gif -O LinkRedLeftBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Red%29%20%28Back%29.gif -O LinkRedBack.gif

convert  "LinkRedFrontSmallShield.gif[0]" PNG8:LinkRedFrontSmallShield1.png
convert  "LinkRedFrontSmallShield.gif[1]" PNG8:LinkRedFrontSmallShield2.png
convert  "LinkRedLeftSmallShield.gif[0]" PNG8:LinkRedLeftSmallShield1.png
convert  "LinkRedLeftSmallShield.gif[1]" PNG8:LinkRedLeftSmallShield2.png
convert  "LinkRedBack.gif[0]" PNG8:LinkRedBack1.png
convert  "LinkRedBack.gif[1]" PNG8:LinkRedBack2.png

# Green
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Front%291.gif -O LinkGreenFrontSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Front%292.gif -O LinkGreenFrontBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Left%291.gif -O LinkGreenLeftSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Left%292.gif -O LinkGreenLeftBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Back%29.gif -O LinkGreenBack.gif

convert  "LinkGreenFrontSmallShield.gif[0]" PNG8:LinkGreenFrontSmallShield1.png
convert  "LinkGreenFrontSmallShield.gif[1]" PNG8:LinkGreenFrontSmallShield2.png
convert  "LinkGreenLeftSmallShield.gif[0]" PNG8:LinkGreenLeftSmallShield1.png
convert  "LinkGreenLeftSmallShield.gif[1]" PNG8:LinkGreenLeftSmallShield2.png
convert  "LinkGreenBack.gif[0]" PNG8:LinkGreenBack1.png
convert  "LinkGreenBack.gif[1]" PNG8:LinkGreenBack2.png

# Blue
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Front%291.gif -O LinkBlueFrontSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Front%292.gif -O LinkBlueFrontBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Left%291.gif -O LinkBlueLeftSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Left%292.gif -O LinkBlueLeftBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Blue%29%20%28Back%29.gif -O LinkBlueBack.gif

convert  "LinkBlueFrontSmallShield.gif[0]" PNG8:LinkBlueFrontSmallShield1.png
convert  "LinkBlueFrontSmallShield.gif[1]" PNG8:LinkBlueFrontSmallShield2.png
convert  "LinkBlueLeftSmallShield.gif[0]" PNG8:LinkBlueLeftSmallShield1.png
convert  "LinkBlueLeftSmallShield.gif[1]" PNG8:LinkBlueLeftSmallShield2.png
convert  "LinkBlueBack.gif[0]" PNG8:LinkBlueBack1.png
convert  "LinkBlueBack.gif[1]" PNG8:LinkBlueBack2.png