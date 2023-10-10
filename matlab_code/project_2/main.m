clear all;
clc
% makes the obj that holds the compareing images
background = imread('test_back.jpg');
foreground = imread('red.jpg');
im = impross(background, foreground);

% makes the gamestate struct
gamestate.original = background;
gamestate.well_color = [0, 0, 0, 0, 0, 0, 0, 0];
gamestate.curret = foreground;
gamestate.diffrence = im.subtraction;
gamestate.noise_removal = im.bw;
gamestate.pixel_locs = {[0,0], [0,0], [0,0], [0,0], [0,0], [0,0], [0,0], [0,0]};
% add in the key

% gets the centoid locations
stats = regionprops(im.bw, 'Centroid');
num = size(stats);
num = num(1);

% gets the well loc bw image
background = imread("well_loc_blank.jpg");
foreground = imread("well_loc_1.jpg");
im_holder = impross(background, foreground);
well_loc_1 = im_holder.bw;

background = imread("well_loc_blank.jpg");
foreground = imread("well_loc_2.jpg");
im_holder = impross(background, foreground);
well_loc_2 = im_holder.bw;

background = imread("well_loc_blank.jpg");
foreground = imread("well_loc_3.jpg");
im_holder = impross(background, foreground);
well_loc_3 = im_holder.bw;

background = imread("well_loc_blank.jpg");
foreground = imread("well_loc_4.jpg");
im_holder = impross(background, foreground);
well_loc_4 = im_holder.bw;

background = imread("well_loc_blank.jpg");
foreground = imread("well_loc_5.jpg");
im_holder = impross(background, foreground);
well_loc_5 = im_holder.bw;

background = imread("well_loc_blank.jpg");
foreground = imread("well_loc_6.jpg");
im_holder = impross(background, foreground);
well_loc_6 = im_holder.bw;

background = imread("well_loc_blank.jpg");
foreground = imread("well_loc_7.jpg");
im_holder = impross(background, foreground);
well_loc_7 = im_holder.bw;

background = imread("well_loc_blank.jpg");
foreground = imread("well_loc_8.jpg");
im_holder = impross(background, foreground);
well_loc_8 = im_holder.bw;

well_locs = {well_loc_1, well_loc_2, well_loc_3, well_loc_4, well_loc_5, well_loc_6, ...
    well_loc_7, well_loc_8};


for i = 1:num
    x = floor(stats(i).Centroid(2));
    y = floor(stats(i).Centroid(1));
    for j = 1:8
        % finds which cell centroid is in
        im_holder = well_locs{1, j};
        if im_holder(x, y) == 1
            % j is well_loc
            % finds the color of the well
            gamestate.pixel_locs{j} = [x, y];
            red = im.subtraction2(x, y, 1);
            green = im.subtraction2(x, y, 2);
            blue = im.subtraction2(x, y, 3);
            % checks for which color the centoid is
            % checks for red
            if red == 255
                gamestate.well_color(j) = 1;

            elseif green == 255
                gamestate.well_color(j) = 2;

            elseif blue == 255
                gamestate.well_color(j) = 3;

            elseif red == 200 && green == 200
                gamestate.well_color(j) = 4;

            end
        end
    end
end
gamestate




