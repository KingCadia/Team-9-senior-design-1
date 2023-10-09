clc;
clear all;
close all;
%gets the images and sizes
background = imread('background.jpg');
foreground = imread('foreground.jpg');
[height, width, depth] = size(foreground);
subtraction = 255 - (background - foreground);
subtraction2 = subtraction;
% does the threshholding for the colors to brighten 
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
%imshow(subtraction2);


% gets a clean black and white image
bw = im2bw(subtraction2, .8);
bw = ~bw;
SE = strel('disk', 2);
erode = imerode(bw, SE);

SE = strel('disk', 6);
dialate = imdilate(erode, SE);

% gets the stats from the image
stats = regionprops(dialate, 'Centroid');
centroids = cat(1, stats.Centroid);
imshow(bw);
hold on
plot(centroids(:,1),centroids(:,2),'bl*')
hold off


%imshowpair(erode, dialate, 'montage');