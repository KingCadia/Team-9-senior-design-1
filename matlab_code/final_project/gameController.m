classdef gameController < handle
    % GAMECONTROLLER
    % make the decisions on where to move the pieces
    
    properties
        boardCon
        board
        playerPiece
        ComPiece
        background
        cam
    end
    
    methods
        function obj = gameController(player, computer)
            obj.boardCon = boardController();
            % note remember to put in the camera
            obj.board = ['0', '0', '0'; '0', '0', '0'; '0', '0', '0'];
            obj.playerPiece = player;
            obj.ComPiece = computer;
            webcamName = webcamlist;
            obj.cam = webcam(webcamName(3));
            obj.background = snapshot(obj.cam);
        end
        
        % makes move for the player if the move is legal will return 1 if
        % succesful returns -1 if not succesful
        function errorCode = makeMovePlayer(obj, x, y)
            % checks if the move is legal
            if obj.board[i] ~= '0' || obj.board[i] == obj.ComPiece
                errorCode = -1;
            else
                % use 1D indexing of a 2D arrayx, y
                obj.boardCon.grabPiece("player");
                obj.boardCon.move(x, y);
                obj.boardCon.dropPiece();
                obj.board(x, y) = obj.playerPiece;
                errorCode = 1;
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
                        end
                    end
                end
            end
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
end

