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
            
        end
        
        
    end
end

