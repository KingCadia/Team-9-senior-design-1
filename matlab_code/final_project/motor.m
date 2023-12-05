classdef motor < handle
   properties
       loc
       horz_vert
       locationAngles
       simName
   end
   methods
       % constuctor method
       function obj = motor(horz_vert, simName)
           obj.horz_vert = horz_vert;
           obj.simName = simName;
           if horz_vert == 0
               % this motor is the horz motor
               obj.locationAngles(1) = 0;
               obj.locationAngles(2) = 420;
               obj.locationAngles(3) = 750;
               obj.loc = 1;

           else
               % this motor is the vert motor
               obj.locationAngles(1) = -1000;
               obj.locationAngles(2) = -750;
               obj.locationAngles(3) = -420;
               obj.loc = -1;
           end
       end
    
       function move(obj, loc)
           if obj.horz_vert == 0
               % this is the horz motor
               set_param([obj.simName '/horzAngle'], 'Value', int2str(obj.locationAngles(loc)));
               
               obj.loc = loc;
           else
                % this is the vert motor
                if loc == -1
                    set_param([obj.simName '/vertAngle'], 'Value', int2str(0));
                    obj.loc = -1;
                else
                    set_param([obj.simName '/vertAngle'], 'Value', int2str(obj.locationAngles(loc)));
                    obj.loc = loc;
                end
           end
       end
    
   end
end

