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
        mega
        x_location
        y_location
    end
    
    % public methods
    methods (Access = public)
        function obj = boardController()
            % defines the needed properties 
            obj.mega = arduino("COM3", "MEGA2560");
            obj.motor_vert = motor(obj.mega, "D4", "D5", "D6", .0000625, 50, "D7", "D8");
            obj.motor_horz = motor(obj.mega, "D11", "D12", "D13", .0000625, 50, "D14", "D15");
            
        end
        
        % grabs the piece assosiated with the player passed to the function
        function grabPiece(obj, player)
            
        end
        
        % moves the piece placer to the location indicated by the row and
        % col inputs
        function moveTo(obj, row, col)
            
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
        
    end
end

