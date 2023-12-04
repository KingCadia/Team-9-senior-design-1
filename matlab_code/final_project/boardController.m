classdef boardController < handle
   %{
    This class controlls the position of the motors on the board and by
    extention the head of the piece placer
    %}
    
    % public properties
    properties (Access = public)
       
    end
    
    % private properties
    properties (Access = private)
        motor_vert 
        motor_horz
        x_location
        y_location
        mag
    end
    
    % public methods
    methods (Access = public)
        function obj = boardController()
            % defines the needed properties 
            obj.mag = 0;
            obj.motor_horz = motor(0);
            obj.motor_vert = motor(1);
            obj.x_location = 1;
            obj.y_location = -1;
            assignin('base', 'mag', 0);
        end
        
        % grabs the piece that is passed to this function
        function grabPiece(obj, piece)
            % goes to the piece location
            % moves to the X position
            if piece == 'X'
               obj.moveTo(1, -1);
               obj.x_location = 1;
               obj.y_location = -1;
            else
               obj.moveTo(2, -1); 
               obj.x_location = 2;
               obj.y_location = -1;
            end
            % turns on the magnet
            assignin('base', 'mag', 1);
        end
        
        % moves the piece placer to the location indicated by the row and
        % col inputs
        function moveTo(obj, x, y)
           % moves to the x location first
           if x ~= obj.x_location
               obj.motor_horz.move(x);
               pause(3);
               obj.x_location = x;
           end
           % moves the motor to the y location
           if y ~= obj.y_location
               obj.motor_vert.move(y);
               pause(3);
               obj.y_location = y;
           end
        end
        
        % drops the piece that the actuator is currently holding
        function dropPiece(obj)
            assignin('base', 'mag', 0);
        end
        
        % returns the current row location
        function x = getRow(obj)
            x = obj.x_location;
        end
        
        % returns the current col location
        function y = getCol(obj)
            y = obj.y_location;
        end
        
        

    end
    
end

