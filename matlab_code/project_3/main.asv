
prossim = impross(background, foreground);
pointer = motor(mega, "D4", "D5", "D2", .0000625, 50, "D10", "D11");

current_angle = 0;

[row, col] = prossim.imgetcentriod(color, shape);

if row == -1
    % move forward and backwards
    pointer.move(360);
    pause(.001);
    pointer.backwards();
    pointer.move(360);
else
    [x, y] = coordinate.normalize_image_coor(row, col, prossim.width, prossim.height);
    angle = coordinate.get_angle(x, y);
    if angle < 0
        pointer.backwards();
        angle = angle * -1;
        pointer.move(angle);
        pause(5);
        pointer.forward();
        pointer.move(angle);
    else
        pointer.forward();
        pointer.move(angle);
        pause(5);
        pointer.backwards();
        pointer.move(angle);
    end
end

