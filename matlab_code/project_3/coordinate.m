classdef coordinate
    % this class contains mostly static methods to calculate things related
    % to the rectangular coordinate system and angles of the rectangular
    % coordinates
    methods(Static)
        % function to nornamlize image pixels into retancular coordinates
        % inputs 
        % row = the row that the pixel is in
        % col = the colum that the pixel is in
        % x_size = number of colums 
        % y_size number of rows
        % return values 
        % x = rectangular x coordinate
        % y = rectangular y coordinate
        function [x, y] = normalize_image_coor(row, col, x_size, y_size)
            y_0 = x_size / 2;
            x_0 = y_size / 2;
        
            x = row - y_0;
            y = -1 * (col - x_0);
        end
    
        % function that gives the polar coordinate theta of the rectangular 
        % coordinates passed to it 
        % inputs 
        % x = x rectangular coordinate
        % y = y rectangular coordinate
        % return values
        % angle = polar theta value
        function angle = get_angle(x, y)
            [theta, rho] = cart2pol(x, y);
            angle = rad2deg(theta);
            angle = ceil(angle);
        end
    end
end
