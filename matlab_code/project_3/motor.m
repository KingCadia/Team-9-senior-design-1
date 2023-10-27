classdef motor
    %MOTOR Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        Mega
        IN1
        IN2
        Step_pin
        pulses_per_degree
        time_period
        duty_cycle
    end
    
    methods
        function obj = motor(mega, IN1, IN2, Step_pin, time_period, duty_cycle)
            % MOTOR Construct an instance of this class
            % sets up the pins for the motors
            obj.Mega = mega;
            obj.IN1 = IN1;
            obj.IN2 = IN2;
            obj.Step_pin = Step_pin;
            obj.pulses_per_degree = 5;
            obj.time_period = time_period;
            obj.duty_cycle = duty_cycle;
            writeDigitalPin(obj.Mega, obj.Step_pin, 0);
            writeDigitalPin(obj.Mega, obj.IN1, 1);
            writeDigitalPin(obj.Mega, obj.IN2, 0);
            
        end
        
        % moves the motor the amount of degrees passed to the fuction the
        % function is blocking my find a way to change that in the future
        function move(obj, degrees)
            stop_point = floor(degrees) * obj.pulses_per_degree;
            i = 0;
            while i < stop_point
                writeDigitalPin(obj.Mega, obj.Step_pin, 1);
                pause();
            end
        end
        
        
    end
end

