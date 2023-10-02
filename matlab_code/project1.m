mega = arduino('COM3','MEGA2560');
% configures the pins
configurePin(mega, 'A0', 'AnalogInput');
configurePin(mega, 'D5', 'DigitalOutput');
hard_switch = 0;
% loop to control the accuation of e mag
threshhold = 1.0;
voltage = 0.0;
writeDigitalPin(mega, 'D5', 0);
while 1
    voltage = readVoltage(mega, 'A0');
    if voltage >= threshhold
        writeDigitalPin(mega, 'D5', 1);
    else
        writeDigitalPin(mega, 'D5', 0); 
    end
end
