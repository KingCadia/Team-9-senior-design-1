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
            
        end
        
        % grabs the piece that is passed to this function
        function grabPiece(obj, piece)
            
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
            
        end
        
        % returns the current row location
        function getRow(obj)
            
        end
        
        % returns the current col location
        function getCol(obj)
            
        end
        
        

    end
    
    % private methods 
    methods (Access = private, Hidden = true)
        function moveWellLoc(wellLocs)
            
        end
    end
end

