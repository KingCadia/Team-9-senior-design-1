clear
clc
mega = arduino("COM3", "MEGA2560");
vert = motor(mega, "D4", "D5", "D6", 0, 0, "D2", "D3");
%vert.backwards();
vert.move(380);