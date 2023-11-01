classdef impross
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
    end
    
    methods
        function obj = impross(background, foreground)
            obj.background = background;
            obj.forground = foreground;
            [obj.height, obj.width, ~] = size(foreground);
            sub = 255 - (background - foreground);
            obj.subtraction = sub;
            sub2 = obj.imsubtraction();
            obj.subtraction2 = sub2;
            bw = obj.imgetbw();
            obj.bw = bw;
        end

        function sub2 = imsubtraction(obj)
            sub2 = obj.subtraction;
            for i = 1:obj.height
                for j = 1:obj.width
                    if (obj.subtraction(i,j,1) <= 255 && obj.subtraction(i,j,1) >= 200) && ...
                       (obj.subtraction(i,j,2) <= 225) && ...
                       (obj.subtraction(i,j,3) <= 140)
                            sub2(i,j,1) = 255;
                            sub2(i,j,2) = 0;
                            sub2(i,j,3) = 0;
                    end

                    if ((obj.subtraction(i,j,1) <= 160 && obj.subtraction(i,j,1) >= 100) && ...
                       (obj.subtraction(i,j,2) <= 180 && obj.subtraction(i, j, 2) >= 120) && ...
                       (obj.subtraction(i,j,3) <= 240 && obj.subtraction(i, j, 3) >= 100))
                            sub2(i,j,1) = 0;
                            sub2(i,j,2) = 0;
                            sub2(i,j,3) = 255;
                    end
                    
                    if ((obj.subtraction(i, j, 1) >= 40) && (obj.subtraction(i, j, 1) <= 140) ...
                       && (obj.subtraction(i, j, 2) >= 100) && (obj.subtraction(i, j, 2) <= 220) ...
                       && (obj.subtraction(i, j, 3) >= 50) && (obj.subtraction(i, j, 3) <= 150)) 
                            sub2(i,j,1) = 0;
                            sub2(i,j,2) = 255;
                            sub2(i,j,3) = 0;
                    end

                    if ((obj.subtraction(i,j,1) <= 255 && obj.subtraction(i,j,1) >= 220) && ...
                       (obj.subtraction(i,j,2) <= 255 && obj.subtraction(i,j,2) >= 240) && ...
                       (obj.subtraction(i,j,3) <= 200 && obj.subtraction(i,j,3) >= 140))
                            sub2(i,j,1) = 200;
                            sub2(i,j,2) = 200;
                            sub2(i,j,3) = 50;
                    end
                end
            end
        end

        function bw = imgetbw(obj)
            bw = im2bw(obj.subtraction2, 0.8);
            bw = ~bw;
            SE = strel('disk', 2);
            bw = imerode(bw, SE);

            SE = strel('disk', 6);
            bw = imdilate(bw, SE);
        end

        function detectShapesAndColors(obj)
            binaryImage = obj.bw < 100;
            binaryImage = bwareaopen(binaryImage, 300);
            [labeledImage, numberOfObjects] = bwlabel(binaryImage);
            blobMeasurements = regionprops(labeledImage, 'Perimeter', 'Area', 'Centroid');
            colorLabels = {'Red', 'Blue', 'Green', 'Yellow'};

            for blobNumber = 1:numberOfObjects
                circularity = (blobMeasurements(blobNumber).Perimeter^2) / (4 * pi * blobMeasurements(blobNumber).Area);
                colorLabel = obj.getColorLabel(obj.subtraction2(blobMeasurements(blobNumber).Centroid(2), blobMeasurements(blobNumber).Centroid(1), :));

                if circularity < 1.19
                    shapeLabel = 'Circle';
                elseif circularity < 1.53
                    shapeLabel = 'Rectangle';
                else
                    shapeLabel = 'Triangle';
                end

                message = sprintf('Detected a %s %s at centroid (%.2f, %.2f)', colorLabel, shapeLabel, blobMeasurements(blobNumber).Centroid(1), blobMeasurements(blobNumber).Centroid(2));
                FPRINTF(message);
            end
        end

        function colorLabel = getColorLabel(obj, pixelColor)
            redValue = pixelColor(1);
            greenValue = pixelColor(2);
            blueValue = pixelColor(3);

            if redValue > 200 && greenValue <= 225 && blueValue <= 140
                colorLabel = 'Red';
            elseif redValue >= 100 && redValue <= 160 && greenValue >= 120 && greenValue <= 180 && blueValue >= 100 && blueValue <= 240
                colorLabel = 'Blue';
            elseif redValue >= 40 && redValue <= 140 && greenValue >= 100 && greenValue <= 220 && blueValue >= 50 && blueValue <= 150
                colorLabel = 'Green';
            elseif redValue >= 220 && greenValue >= 240 && blueValue >= 140
                colorLabel = 'Yellow';
            else
                colorLabel = 'Unknown';
            end
        end
    end
  end
