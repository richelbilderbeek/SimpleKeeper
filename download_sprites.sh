#!/bin/bash
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Front%291.gif -O LinkFrontSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Front%292.gif -O LinkFrontBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Left%291.gif -O LinkLeftSmallShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Left%292.gif -O LinkLeftBigShield.gif
wget http://www.videogamesprites.net/Zelda1/Link/Link%20%28Normal%29%20%28Back%29.gif -O LinkBack.gif

convert  "LinkFrontSmallShield.gif[0]" LinkFrontSmallShield1.png
convert  "LinkFrontSmallShield.gif[1]" LinkFrontSmallShield2.png
convert  "LinkLeftSmallShield.gif[0]" LinkLeftSmallShield1.png
convert  "LinkLeftSmallShield.gif[1]" LinkLeftSmallShield2.png
convert  "LinkBack.gif[0]" LinkBack1.png
convert  "LinkBack.gif[1]" LinkBack2.png