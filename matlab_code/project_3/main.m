%% test for pulses per degree

% freqency = 16KHz
% time period = 0.0000625s
mega = arduino('COM3','MEGA2560');
stop = 0;
time_period = 0.0000625;
duty_cycle = 50;
% picks the direction
writeDigitalPin(mega, "D4", 1);
writeDigitalPin(mega, "D5", 0);
writeDigitalPin(mega, "D2", 0);
i = 0;
hall_1_state = readDigitalPin(mega, "D10");
hall_2_state = readDigitalPin(mega, "D11");
while stop == 0
    writeDigitalPin(mega, "D2", 1);
    pause(time_period * (duty_cycle / 100));
    writeDigitalPin(mega, "D2", 0);
    pause(time_period * ((100 - duty_cycle) / 100));
    current_1_state = readDigitalPin(mega, "D10");
    current_2_state = readDigitalPin(mega, "D11");
    if current_1_state ~= hall_1_state
        i = i + 1;
        hall_1_state = current_1_state;
    end
    if current_2_state ~= hall_2_state
        i = i + 1;
        hall_2_state = current_2_state;
    end
end
print(i);
%%
