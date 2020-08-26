# Cyborg-1.5-Oled-Eye-RasperryPi
Displays an eye with natural random movement on an 1.5" Oled connected to the pi. Made it for a Cyberpunk / Cyborg costume 



## Setup
1. Call Pi Setup-Script: install_dependencies_on_pi.sh to automatically setup your pi:
(Requires sshpass to be installed on your local machine: ```sudp apt install sshpass```
Call it with the ip address of your pi and your ssh password as arguments:

``` install_dependencies_on_pi.sh 192.168.128.XX raspberry```

2. Call Cross Compile environment Setup-Script: setup_cross_compile_environment.sh to automatically setup your cross compile environment:
Call it with the ip address of your pi and your ssh password as arguments:

``` setup_cross_compile_environment.sh 192.168.128.XX raspberry```

(if you need to update your cross compile environment at any point add the "update" argument to the call:
``` setup_cross_compile_environment.sh 192.168.128.XX raspberry update```