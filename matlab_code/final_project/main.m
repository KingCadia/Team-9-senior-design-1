%% test to see if mini max tree works
game = gameController('X', 'O');

game.makeMovePlayerTest(1, 1);

game.makeMoveComTest();

%% testing the tree data structure
clear 
clc
board = ['0', '0', '0'; '0', '0', '0'; '0', '0', '0'];
tre = treeNode(board, 0, 0);
board(2, 2) = 'X';
tre.add(board, 2, 2);

%% gonna figure out how to do an array of objects
clear 
clc
board = ['0', '0', '0'; '0', '0', '0'; '0', '0', '0'];
tre1 = treeNode(board, 0, 0);
tre2 = treeNode(board, 0, 0);
array(1) = tre1;
array(2) = tre2;
