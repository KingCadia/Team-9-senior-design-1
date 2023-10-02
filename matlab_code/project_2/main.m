background = imread('background.jpg');
foreground = imread('foreground.jpg');
subtraction = background - foreground;
imshow(subtraction);