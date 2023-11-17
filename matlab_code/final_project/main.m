%% test to see if mini max tree works
game = gameController('X', 'O');

game.makeMovePlayerTest(1, 1);

game.makeMoveComTest();

%% testing the tree data structure
clear 
clc
board = ['O', 'O', 'X'; '0', 'X', '0'; '0', '0', '0'];
%game.board = board; 
game = gameController('X', 'O');
game.makeMoveComTest();
game.board

%% gonna figure out how to do an array of objects
clear 
clc
board = ['0', '0', '0'; '0', '0', '0'; '0', '0', '0'];
tre1 = treeNode(board, 0, 0);
tre2 = treeNode(board, 9, 1);
tre1 = tre1.add(tre2);
% array of trees now works
