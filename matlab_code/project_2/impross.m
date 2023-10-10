classdef impross
    %IMPROSS Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        background
        forground
        well_locs
    end
    
    methods
        function obj = impross(background, foreground)
            [height, width, depth] = size(foreground);
            subtraction = 255 - (background - foreground);
            subtraction2 = imsubtraction(subtraction, height, width);
            bw = imgetbw(subtraction2);
            % gets the centroid locs
            stats = regionprops(bw, 'Centroid');
            centroids = cat(1, stats.Centroid);
            well_locs = well_loc_find(background);
                        
        end
       
        function subtraction2 = imsubtraction(subtraction, height, width)
            %does the threshholding for the colors to brighten 
            subtraction2 = subtraction;
            for i = 1:height
                for j = 1:width
                    % check for red
                    if (subtraction(i,j,1) <= 255 && subtraction(i,j,1) >= 200) && ...
                       (subtraction(i,j,2) <= 225) && ...
                       (subtraction(i,j,3) <= 140)
                            % detected a red
                            subtraction2(i,j,1) = 255;
                            subtraction2(i,j,2) = 0;
                            subtraction2(i,j,3) = 0;
                    end

                    % checks for green
                    if ((subtraction(i, j, 1) >= 40) && (subtraction(i, j, 1) <= 140) ...
                       && (subtraction(i, j, 2) >= 100) && (subtraction(i, j, 2) <= 220) ...
                       && (subtraction(i, j, 3) >= 50) && (subtraction(i, j, 3) <= 150)) 
                            % detected a green
                            subtraction2(i,j,1) = 0;
                            subtraction2(i,j,2) = 255;
                            subtraction2(i,j,3) = 0;
                    end

                    % checks for blue
                    if ((subtraction(i,j,1) <= 140 && subtraction(i,j,1) >= 100) && ...
                       (subtraction(i,j,2) <= 160) && ...
                       (subtraction(i,j,3) <= 220))
                            % detected a blue
                            subtraction2(i,j,1) = 0;
                            subtraction2(i,j,2) = 0;
                            subtraction2(i,j,3) = 255;
                    end

                    % checks for yellow
                    if ((subtraction(i,j,1) <= 255 && subtraction(i,j,1) >= 220) && ...
                       (subtraction(i,j,2) <= 255 && subtraction(i,j,2) >= 240) && ...
                       (subtraction(i,j,3) <= 200 && subtraction(i,j,3) >= 140))
                            % detected a yellow
                            subtraction2(i,j,1) = 200;
                            subtraction2(i,j,2) = 200;
                            subtraction2(i,j,3) = 50;
                    end
                end
            end
        end
        
        % gets a clean black and white image with noise filtered out 
        function bw = imgetbw(sub)
            
            bw = im2bw(sub, .8);
            bw = ~bw;
            SE = strel('disk', 2);
            bw = imerode(bw, SE);

            SE = strel('disk', 6);
            bw = imdilate(bw, SE);
        end
        
        function well_loc_array = well_loc_find(background)
            [height, width, depth] = size(background);
            % gets all the well loc images
            im1 = imread('well_loc_1.jpg');
            im2 = imread('well_loc_2.jpg');
            im3 = imread('well_loc_3.jpg');
            im4 = imread('well_loc_4.jpg');
            im5 = imread('well_loc_5.jpg');
            im6 = imread('well_loc_6.jpg');
            im7 = imread('well_loc_7.jpg');
            im8 = imread('well_loc_8.jpg');
            
            well_loc_array = cat(im1, im2, im3, im4, ... 
            im5, im6, im7, im8);
            
            % gets a clean black/white images for all well locs
            for i = 1:size(well_loc_array)
                im = well_loc_array(i);
                im = 255 - (background - im);
                im = imsubtraction(im, height, width);
                im = imgetbw(im);
                well_loc_array(i) = im;
            end
        end
    end
end

