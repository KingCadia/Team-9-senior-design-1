mega = arduino('COM3','MEGA2560');
% configures the pins
configurePin(mega, 'A0', 'AnalogInput');
configurePin(mega, 'D5', 'DigitalOutput');

% loop to control the accuation of e mag
threshhold = 2.5;
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
