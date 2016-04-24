#!/bin/bash
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Front%291.gif -O LinkGreenFrontSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Front%292.gif -O LinkGreenFrontBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Left%291.gif -O LinkGreenLeftSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Left%292.gif -O LinkGreenLeftBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Back%29.gif -O LinkGreenBack.gif

convert  "LinkGreenFrontSmallShield.gif[0]" LinkGreenFrontSmallShield1.png
convert  "LinkGreenFrontSmallShield.gif[1]" LinkGreenFrontSmallShield2.png
convert  "LinkGreenLeftSmallShield.gif[0]" LinkGreenLeftSmallShield1.png
convert  "LinkGreenLeftSmallShield.gif[1]" LinkGreenLeftSmallShield2.png
convert  "LinkGreenBack.gif[0]" LinkGreenBack1.png
convert  "LinkGreenBack.gif[1]" LinkGreenBack2.png