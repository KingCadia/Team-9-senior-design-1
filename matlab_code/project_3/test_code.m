%% test for pulses per degree

clear 
% freqency = 16KHz
% time period = 0.0000625s
% seconds per degree 0.002722
seconds_per_degree = .002722;
mega = arduino('COM3','MEGA2560');
stop = 0;
time_period = 0.0000002;
duty_cycle = 1;
% picks the direction
writeDigitalPin(mega, "D4", 1);
writeDigitalPin(mega, "D5", 0);
writeDigitalPin(mega, "D2", 0);
i = 0;
hall_1_state = readDigitalPin(mega, "D10");
hall_2_state = readDigitalPin(mega, "D11");
writeDigitalPin(mega, "D2", 1);
pause(.90);
writeDigitalPin(mega, "D2", 0);



% while i < 15
%     writeDigitalPin(mega, "D2", 1);
%     pause(time_period * (duty_cycle / 100));
%     writeDigitalPin(mega, "D2", 0);
%     pause(time_period * ((100 - duty_cycle) / 100));
%     current_1_state = readDigitalPin(mega, "D10");
%     current_2_state = readDigitalPin(mega, "D11");
%     i = i + 1;
% %     if current_1_state ~= hall_1_state
% %         i = i + 1;
% %         hall_1_state = current_1_state;
% %     end
% %     if current_2_state ~= hall_2_state
% %         i = i + 1;
% %         hall_2_state = current_2_state;
% %     end
% end

%% another test for the motors
clear
mega = arduino('COM3','MEGA2560');
pointer = motor(mega, "D4", "D5", "D2", .0000625, 50, "D10", "D11");
pointer.move(360);

%% test for the image shape stuff
clear
clc
foreground = imread('test1.jpg');
background = imread('back2.jpg');

obj = impross(background, foreground);

[row, col] = obj.imgetcentriod("red", "Square");

[x, y] = coordinate.normalize_image_coor(row, col, obj.width, obj.height);


theata = coordinate.get_angle(x, y);




