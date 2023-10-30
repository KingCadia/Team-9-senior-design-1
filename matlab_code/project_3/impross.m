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
        locations
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
                    if ((obj.subtraction(i,j,1) <= 160 && obj.subtraction(i,j,1) >= 100) && ...
                       (obj.subtraction(i,j,2) <= 180 && obj.subtraction(i, j, 2) >= 120) && ...
                       (obj.subtraction(i,j,3) <= 240 && obj.subtraction(i, j, 3) >= 100))
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
        function imfindobjects(obj)
            
        end

        % finds the color, shape and centroid locations of each region and stores it in shapes
        % colors and centroid property arrays respectivly
        % note: store the centriod locations as int values that have been
        % rounded up
        function imidentifyobjects(obj)

        end
        
        % function that when given a shape and color will return the
        % centriod location of the first image object that matches that
        % shape and color if a shape matching the shape and color is not
        % found then return -1, -1
        function [row, col] = imgetcentriod(obj, color, shape)

        end
    end

end

