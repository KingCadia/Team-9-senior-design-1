mega = arduino('COM3', 'Mega2560');
time_period = 0.0000625;
duty_cycle = 50;

dir = 1;

while 1
    if dir == 1
        writeDigitalPin(mega, 'D4', 1);
        writeDigitalPin(mega, 'D5', 0);
    else
        writeDigitalPin(mega, 'D4', 0);
        writeDigitalPin(mega, 'D5', 1);
    end
    writeDigitalPin(mega, 'D2', 1);
    pause(time_period * (duty_cycle / 100));
    writeDigitalPin(mega, 'D2', 0);
    pause(time_period * ((100 - duty_cycle) / 100));
end
