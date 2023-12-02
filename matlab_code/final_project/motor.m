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
        hall_sensor_1
        hall_sensor_2
        seconds_per_degree
    end
    
    methods
        % constuctor function
        %{
        inputs 
        mega = the arduino object controls the motor
        IN1 = the first direction pin name
        IN2 = the second direction pin name
        Step_pin = the name of the pin that the PWM signal will be put on
        time_period = the time period of the frequency that will be used 
        for the PWM signal
        duty_cycle = the duty cycle of the PWM signal (input as whole
        number not as a decimal or fraction)
        hall_sensor_1 = name of the pin that the first hall sensor is on
        hall_sensor_2 = name of the pin that the second hall sensor is on
        %}
        function obj = motor(mega, IN1, IN2, Step_pin, time_period, duty_cycle, hall_sensor_1, hall_sensor_2)
            % MOTOR Construct an instance of this class
            % sets up the pins for the motors
            obj.Mega = mega;
            obj.IN1 = IN1;
            obj.IN2 = IN2;
            obj.Step_pin = Step_pin;
            obj.pulses_per_degree = 5;
            obj.time_period = time_period;
            obj.duty_cycle = duty_cycle;
            obj.hall_sensor_1 = hall_sensor_1;
            obj.hall_sensor_2 = hall_sensor_2;
            obj.seconds_per_degree = .003194;
            writeDigitalPin(obj.Mega, obj.Step_pin, 0);
            writeDigitalPin(obj.Mega, obj.IN1, 1);
            writeDigitalPin(obj.Mega, obj.IN2, 0); 
        end
        %{
        moves the motor the amount of degrees passed to the fuction the
        function is blocking my find a way to change that in the future
        inputs
        degrees moves that number of degrees and stops 
        %}
        function move(obj, degrees)
            writeDigitalPin(obj.Mega, obj.Step_pin, 1);
            pause(degrees * obj.seconds_per_degree);
            writeDigitalPin(obj.Mega, obj.Step_pin, 0);
            
            % gonna try to do the PID stuff
%             traveled = 0;
%             % write the pwm voltage
%             readDigitalPin(obj.Mega, obj.hall_sensor_1);
%             while traveled < degrees
%                 c = clock(6);
%                 
%                 
%             end
%             
            % trying to do a duty cycle type thing
%             on_time = 0;
%             total_time = degrees * obj.seconds_per_degree;
%             
%             while on_time < total_time
%                 writeDigitalPin(obj.Mega, obj.Step_pin, 1);
%                 pause(obj.time_period * (obj.duty_cycle / 100));
%                 writeDigitalPin(obj.Mega, obj.Step_pin, 0);
%                 pause(obj.time_period * ((100 - obj.duty_cycle) / 100));
%                 on_time = on_time + (obj.time_period * (obj.duty_cycle / 100));
%             end
%          
            
            % code for the hall sensor stuff may look at later
%             stop_point = floor(degrees) * obj.pulses_per_degree;
%             i = 0;
%             hall_1_state = readDigitalPin(obj.Mega, obj.hall_sensor_1);
%             hall_2_state = readDigitalPin(obj.Mega, obj.hall_sensor_2);
%             while i < stop_point
%                 % does the PWM sequence 
%                 writeDigitalPin(obj.Mega, obj.Step_pin, 1);
%                 pause(obj.time_period * (obj.duty_cycle / 100));
%                 writeDigitalPin(obj.Mega, obj.Step_pin, 0);
%                 pause(obj.time_period * ((100 - obj.duty_cycle) / 100));
%                 % checks the 2 hall sensor
%                 current_hall_1 = readDigitalPin(obj.Mega, obj.hall_sensor_1);
%                 current_hall_2 = readDigitalPin(obj.Mega, obj.hall_sensor_2);
%                 % checks hall sensor 1
%                 if current_hall_1 ~= hall_1_state
%                     % count up i 
%                     i = i + 1;
%                     hall_1_state = current_hall_1;
%                 end
%                 
%                 % checks hall sensor 2
%                 if current_hall_2 ~= hall_2_state
%                     i = i + 1;
%                     hall_2_state = current_hall_2;
%                 end
%             end
        end

        % changes the direction of the motor
        function forward(obj)
            writeDigitalPin(obj.Mega, obj.IN1, 1);
            writeDigitalPin(obj.Mega, obj.IN2, 0);
        end
        
        function backwards(obj)
            writeDigitalPin(obj.Mega, obj.IN1, 0);
            writeDigitalPin(obj.Mega, obj.IN2, 1);
        end
  
    end
end

