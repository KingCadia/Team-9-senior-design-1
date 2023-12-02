classdef gamecontroller < handle
    % GAMECONTROLLER
    % make the decisions on where to move the pieces
    % for mini max X is mini O is max
    properties
        boardCon
        board
        playerPiece
        ComPiece
        background
        cam
        emptySpaces
    end
    
    methods(Access = public)
        function obj = gamecontroller(player, computer, board)
            %obj.boardCon = boardController();
            % note remember to put in the camera
            obj.board = board;
            obj.playerPiece = player;
            obj.ComPiece = computer;
            %webcamName = webcamlist;
            %obj.cam = webcam(webcamName(3));
            %obj.background = snapshot(obj.cam);
            % finds the number of empty spaces
            obj.emptySpaces = 0
            for i = 1:3
                for j = 1:3
                    if obj.board(i, j) == '0'
                        obj.emptySpaces = obj.emptySpaces + 1;
                    end
                end
            end
            
        end
        
        % makes move for the player if the move is legal will return 1 if
        % succesful returns -1 if not succesful
        function errorCode = makeMovePlayer(obj, x, y)
            % checks if the move is legal
            if obj.board(x, y) ~= '0' || obj.board(x, y) == obj.ComPiece
                errorCode = -1;
            else
                % use 1D indexing of a 2D arrayx, y
                obj.boardCon.grabPiece("player");
                obj.boardCon.move(x, y);
                obj.boardCon.dropPiece();
                obj.board(x, y) = obj.playerPiece;
                obj.emptySpaces = obj.emptySpaces - 1;
                errorCode = 1;
            end
        end
        
        % function that makes the move for the play completely in software
        % for testing
        function errorCode = makeMovePlayerTest(obj, x, y)
            % checks if the move is legal
            if obj.board(x, y) ~= '0' || obj.board(x, y) == obj.ComPiece
                errorCode = -1;
                return;
            else
                obj.board(x, y) = obj.playerPiece;
                obj.emptySpaces = obj.emptySpaces - 1;
                errorCode = 1;
                return;
            end
        end
        % makes move for the computer
        function errorCode = makeMoveCom(obj)
            % checks if the game can be won
            for i = 1:3
                for j = 1:3
                    % checks if a piece can be placed at (i, j)
                    if obj.board(i, j) == '0'
                        % copies board and places piece to check if the
                        % game can be won
                        cpyBoard = obj.board;
                        cpyBoard(i, j) = obj.ComPiece;
                        won = obj.isWon(cpyBoard, obj.ComPiece);
                        if won == 1
                            % grab piece, moves to (i, j), and drops piece
                            obj.boardCon.grabPiece("computer");
                            obj.boardCon.move(i, j);
                            obj.boardCon.dropPiece();
                            obj.board(i, j) = obj.ComPiece;
                            obj.emptySpaces = obj.emptySpaces - 1;
                            errorCode = 1;
                            return
                        end
                    end
                end
            end
        end
            
            % makes move for the computer
        function errorCode = makeMoveComTest(obj)
            % plays defensivly
            for i = 1:3
                for j = 1:3
                    cpyBoard = obj.board;
                    if cpyBoard(i, j) == '0'
                        % place player piece and see if the player wins
                        cpyBoard(i, j) = obj.playerPiece;
                        if obj.isWon(cpyBoard, obj.playerPiece)
                            % the player can win with that move so make
                            % that move
                            obj.board(i, j) = obj.ComPiece;
                            obj.emptySpaces = obj.emptySpaces - 1;
                            return;
                        end 
                    end
                end
            end

            % makes random move if needed
            if obj.emptySpaces > 5
                % makes random move
                moveMade = 0;
                while moveMade == 0
                    x = randi(3);
                    y = randi(3);
                    if obj.board(x, y) == '0'
                        obj.board(x, y) = obj.ComPiece;
                        obj.emptySpaces = obj.emptySpaces - 1;
                        return;
                    end
                end
            end
                        
            % makes the minimax tree
            [x, y] = obj.miniMax(obj.ComPiece);
            obj.board(x, y) = obj.ComPiece;
            obj.emptySpaces = obj.emptySpaces - 1;
            errorCode = 1;
        end
        
        % checks to see if the game is won
        function won = isWon(obj, board, piece)
            % really inefficent way to code this but its whatever
            % horizontals 
            if board(1, 1) == piece && board(1, 2) == piece && board(1, 3) == piece
                won = 1;
            elseif board(2, 1) == piece && board(2, 2) == piece && board(2, 3) == piece
                won = 1;
            elseif board(3, 1) == piece && board(3, 2) == piece && board(3, 3) == piece
                won = 1;
            % verticals
            elseif board(1, 1) == piece && board(2, 1) == piece && board(3, 1) == piece
                won = 1;
            elseif board(1, 2) == piece && board(2, 2) == piece && board(3, 2) == piece
                won = 1;
            elseif board(1, 3) == piece && board(2, 3) == piece && board(3, 3) == piece
                won = 1;
            % diagonals
            elseif board(1, 1) == piece && board(2, 2) == piece && board(3, 3) == piece
                won = 1;
            elseif board(1, 3) == piece && board(2, 2) == piece && board(3, 1) == piece
                won = 1;
            else
                won = 0;
            end
        end
        
    end
    
    methods(Access = private, Hidden = true)
        % uses the miniMax algorithm to make the best possible move
        function [x, y] = miniMax(obj, piece)
            % makes the miniMax tree
            boardCpy = obj.board;
            tre = obj.makeTree(boardCpy, obj.emptySpaces, obj.ComPiece, 0,0);
            % add in the if emptySpaces < 3 code here later
            % gets the best move the player can make
            if obj.playerPiece == 'O'
                tre.getMin();
                % finds the smallest node in the direct subtree
                weight = Inf;
                for i = 1:tre.numberOfNodes
                    holderNode = tre.Nodes(i);
                    holderNode.getMin();
                    if holderNode.weight < weight
                        node = holderNode;
                        weight = holderNode.weight;
                    end
                end
            else
                weight = -Inf;
                % finds the biggest node in the direct subtree
                for i = 1:tre.numberOfNodes
                    holderNode = tre.Nodes(i);
                    holderNode.getMax();
                    if holderNode.weight > weight
                        node = holderNode;
                        weight = holderNode.weight;
                    end
                end
            end
            
            x = node.i;
            y = node.j;

        end
        % recurrsive function that returns the tree resulting from the
        % board passed to it
        function miniMaxTree = makeTree(obj, board, emptySpaces, turn, i, j)
            % makes the root of the current tree
            miniMaxTree = treeNode(board, i, j);
            for i = 1:3
                for j = 1:3
                    if turn == 'X'
                        % fill in this row for X
                        if board(i, j) == '0'
                           cpyBoard = board;
                           cpyBoard(i, j) = 'X';
                           % checks if the game can be won with that move
                           if obj.isWon(cpyBoard, 'X')
                               % the game can be won with that move
                               leafNode = treeNode(cpyBoard, i, j);
                               leafNode.weight = (emptySpaces - 1) * -1;
                               miniMaxTree = miniMaxTree.add(leafNode);
                           else
                               % the game could not be won with the current
                               % move
                               % adds a sub-tree onto the current tree as a
                               % node
                               miniMaxTree = miniMaxTree.add(obj.makeTree(cpyBoard, emptySpaces - 1, 'O', i, j));
                           end
                        end
                    else
                        % fill in this row for O
                        if board(i, j) == '0'
                           cpyBoard = board;
                           cpyBoard(i, j) = 'O';
                           % checks if the game can be won with that move
                           if obj.isWon(cpyBoard, 'O')
                               % the game can be won with that move
                               leafNode = treeNode(cpyBoard, i, j);
                               leafNode.weight = (emptySpaces - 1);
                               miniMaxTree = miniMaxTree.add(leafNode);
                           else
                               % the game could not be won with the current
                               % move
                               % adds a sub-tree onto the current tree as a
                               % node
                               miniMaxTree = miniMaxTree.add(obj.makeTree(cpyBoard, emptySpaces - 1, 'X', i, j));
                           end
                        end
                    end
                end
            end

        end

    end

end


