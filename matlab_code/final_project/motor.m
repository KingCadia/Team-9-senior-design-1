classdef motor < handle
   properties
       angle
       horz_vert
   end
   methods
       function obj = motor(horz_vert)
           obj.horz_vert = horz_vert;
           obj.angle = 0;
       end
   end
end

