#!/bin/bash
cd Sprites

# Blue
convert  "LinkBlueFrontSmallShield.gif[0]" PNG8:LinkBlueFrontSmallShield1.png
convert  "LinkBlueFrontSmallShield.gif[1]" PNG8:LinkBlueFrontSmallShield2.png
convert  "LinkBlueLeftSmallShield.gif[0]" PNG8:LinkBlueLeftSmallShield1.png
convert  "LinkBlueLeftSmallShield.gif[1]" PNG8:LinkBlueLeftSmallShield2.png
convert  "LinkBlueBack.gif[0]" PNG8:LinkBlueBack1.png
convert  "LinkBlueBack.gif[1]" PNG8:LinkBlueBack2.png

convert -flop LinkBlueLeftSmallShield1.png PNG8:LinkBlueRightSmallShield2.png
convert -flop LinkBlueLeftSmallShield2.png PNG8:LinkBlueRightSmallShield1.png

# Green
convert  "LinkGreenFrontSmallShield.gif[0]" PNG8:LinkGreenFrontSmallShield1.png
convert  "LinkGreenFrontSmallShield.gif[1]" PNG8:LinkGreenFrontSmallShield2.png
convert  "LinkGreenLeftSmallShield.gif[0]" PNG8:LinkGreenLeftSmallShield1.png
convert  "LinkGreenLeftSmallShield.gif[1]" PNG8:LinkGreenLeftSmallShield2.png
convert  "LinkGreenBack.gif[0]" PNG8:LinkGreenBack1.png
convert  "LinkGreenBack.gif[1]" PNG8:LinkGreenBack2.png

convert -flop LinkGreenLeftSmallShield1.png PNG8:LinkGreenRightSmallShield2.png
convert -flop LinkGreenLeftSmallShield2.png PNG8:LinkGreenRightSmallShield1.png

# Overworld

convert OverworldAll32.png PNG8:OverworldAll.png

convert DungeonsAll32.gif PNG8:DungeonsAll.png

# Red
convert  "LinkRedFrontSmallShield.gif[0]" PNG8:LinkRedFrontSmallShield1.png
convert  "LinkRedFrontSmallShield.gif[1]" PNG8:LinkRedFrontSmallShield2.png
convert  "LinkRedLeftSmallShield.gif[0]" PNG8:LinkRedLeftSmallShield1.png
convert  "LinkRedLeftSmallShield.gif[1]" PNG8:LinkRedLeftSmallShield2.png
convert  "LinkRedBack.gif[0]" PNG8:LinkRedBack1.png
convert  "LinkRedBack.gif[1]" PNG8:LinkRedBack2.png

convert -flop LinkRedLeftSmallShield1.png PNG8:LinkRedRightSmallShield2.png
convert -flop LinkRedLeftSmallShield2.png PNG8:LinkRedRightSmallShield1.png

# Triforce
convert TriforceGround1.gif PNG8:TriforceGround1.png
convert TriforceGround2.gif PNG8:TriforceGround2.png