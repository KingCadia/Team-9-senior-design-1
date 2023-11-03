classdef impross
    %IMPROSS Summary of this class goes here
    %   this class takes in a background image and a foreground image then
    %   makes a clean black and white image with the objects identified 
    
    properties
        background
        forground
        well_locs
        gamestate
        height
        width
        subtraction
        subtraction2
        bw
        stats
        colors
        shapes
        rows
        cols
    end
    
    methods
        % constructor 
        function obj = impross(background, foreground)
            obj.background = background;
            obj.forground = foreground;
            [obj.height, obj.width, depth] = size(foreground);
            sub = 255 - (background - foreground);
            obj.subtraction = sub;
            sub2 = obj.imsubtraction();
            obj.subtraction2 = sub2;
            bw = obj.imgetbw();
            obj.bw = bw;
            stats = obj.imfindobjects();
            obj.stats = stats;
            shapes = obj.imidentifyshapes();
            obj.shapes = shapes;
            colors = obj.imidentifycolors();
            obj.colors = colors;
            rows = obj.imidentifyrowlocation();
            obj.rows = rows;
            cols = obj.imidentifycollocation();
            obj.cols = cols;
        end
       
        % does the color threshholding to enhance the colors
        function sub2 = imsubtraction(obj)
            %does the threshholding for the colors to brighten 
            sub2 = obj.subtraction;
            for i = 1:obj.height
                for j = 1:obj.width
                    % check for red
                    if (obj.subtraction(i,j,1) <= 255 && obj.subtraction(i,j,1) >= 200) && ...
                       (obj.subtraction(i,j,2) <= 225) && ...
                       (obj.subtraction(i,j,3) <= 140)
                            % detected a red
                            sub2(i,j,1) = 255;
                            sub2(i,j,2) = 0;
                            sub2(i,j,3) = 0;
                    end

                    % checks for blue
                    if ((obj.subtraction(i,j,1) <= 100 && obj.subtraction(i,j,1) >= 35) && ...
                       (obj.subtraction(i,j,2) <= 100 && obj.subtraction(i, j, 2) >= 35) && ...
                       (obj.subtraction(i,j,3) <= 180 && obj.subtraction(i, j, 3) >= 100))
                            % detected a blue
                            sub2(i,j,1) = 0;
                            sub2(i,j,2) = 0;
                            sub2(i,j,3) = 255;
                    end
                    
                    % checks for green
                    if ((obj.subtraction(i, j, 1) >= 40) && (obj.subtraction(i, j, 1) <= 140) ...
                       && (obj.subtraction(i, j, 2) >= 100) && (obj.subtraction(i, j, 2) <= 220) ...
                       && (obj.subtraction(i, j, 3) >= 50) && (obj.subtraction(i, j, 3) <= 150)) 
                            % detected a green
                            sub2(i,j,1) = 0;
                            sub2(i,j,2) = 255;
                            sub2(i,j,3) = 0;
                    end
                    % checks for yellow
                    if ((obj.subtraction(i,j,1) <= 255 && obj.subtraction(i,j,1) >= 220) && ...
                       (obj.subtraction(i,j,2) <= 255 && obj.subtraction(i,j,2) >= 240) && ...
                       (obj.subtraction(i,j,3) <= 200 && obj.subtraction(i,j,3) >= 140))
                            % detected a yellow
                            sub2(i,j,1) = 200;
                            sub2(i,j,2) = 200;
                            sub2(i,j,3) = 50;
                    end
                end
            end
        end
        
        % gets a clean black and white image with noise filtered out 
        function bw = imgetbw(obj)
            
            bw = im2bw(obj.subtraction2, .8);
            bw = ~bw;
            SE = strel('disk', 2);
            bw = imerode(bw, SE);

            SE = strel('disk', 6);
            bw = imdilate(bw, SE);
        end
       
        % finds the centriod locations and the circularity values of each
        % object in the image and store them in the stats property
        function stats = imfindobjects(obj)
            stats = regionprops(obj.bw, "Centroid", "Circularity");
        end

        % finds the color, shape and centroid locations of each region and stores it in shapes
        % colors and centroid property arrays respectivly
        % note: store the centriod locations as int values that have been
        % rounded up
        function shapes = imidentifyshapes(obj)
            num = size(obj.stats);
            num = num(1);
            % looks through all of the objects found and finds there shapes
            for i = 1:num
                circ_val = obj.stats(i).Circularity;
                % checks for the circularity values and assinges a shape
                if circ_val >= .95 
                    % values for circle
                    shapes(i) = "Circle";
                elseif circ_val >= .8 && circ_val < .95 
                    % values for square
                    shapes(i) = "Square";
                else
                    % values for triangle
                    shapes(i) = "Triangle";
                end
            end
        end
        
        function colors = imidentifycolors(obj)
            num = size(obj.stats);
            num = num(1);
            % checks for the color of each centriod found
            for i = 1:num
                % gets the RGB values for the current centriod location
                point = obj.stats(i).Centroid;
                point(1) = ceil(point(1));
                point(2) = ceil(point(2));
                red = obj.subtraction2(point(2), point(1), 1);
                green = obj.subtraction2(point(2), point(1), 2);
                blue = obj.subtraction2(point(2), point(1), 3);
                
                 if red == 255
                    colors(i) = "red";
            
                % checks for green
                elseif green == 255
                    colors(i) = "green";

                % checks for blue
                elseif blue == 255
                    colors(i) = "blue";

                % checks for yellow
                 else
                    colors(i) = "yellow";

                 end
            end
        end
        
        % gets row location array
        function rows = imidentifyrowlocation(obj)
            num = size(obj.stats);
            num = num(1);
            
            for i = 1:num
                point = obj.stats(i).Centroid;
                rows(i) = ceil(point(1));     
            end
        end
        
        % gets col location array
        function cols = imidentifycollocation(obj)
            num = size(obj.stats);
            num = num(1);
            
            for i = 1:num
                point = obj.stats(i).Centroid;
                cols(i) = ceil(point(2));     
            end
        end
        
        % function that when given a shape and color will return the
        % centriod location of the first image object that matches that
        % shape and color if a shape matching the shape and color is not
        % found then return -1, -1
        function [row, col] = imgetcentriod(obj, color, shape)
            row = -1;
            col = -1;
            % loops through all of the objects to find one that matches
            num = size(obj.stats);
            num = num(1);
            for i =  1: num
                if obj.colors(i) == color
                    
                    if obj.shapes(i) == shape
                        
                        % found a matching object
                        row = obj.rows(i);
                        col = obj.cols(i);
                        break
                    end
                end
            end
        end
    end

end

