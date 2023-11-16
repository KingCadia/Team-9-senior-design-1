classdef treeNode
    %TREE Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        numberOfNodes
        Nodes
        i
        j
        board
        weight
    end
    
    methods
        function obj = treeNode(board, x, y)
            %TREE Construct an instance of this class
            %   Detailed explanation goes here
            obj.numberOfNodes = 0;
            obj.board = board;
            obj.i = x;
            obj.j = y;
            obj.weight = 0;
            % inits the node array
            emptyBoard = ['0', '0', '0'; '0', '0', '0'; '0', '0', '0'];
            if x ~= -1
                tre1 = treeNode(emptyBoard, -1, -1);
                tre2 = treeNode(emptyBoard, -1, -1);
                tre3 = treeNode(emptyBoard, -1, -1);
                tre4 = treeNode(emptyBoard, -1, -1);
                tre5 = treeNode(emptyBoard, -1, -1);
                tre6 = treeNode(emptyBoard, -1, -1);
                tre7 = treeNode(emptyBoard, -1, -1);
                tre8 = treeNode(emptyBoard, -1, -1);
                tre9 = treeNode(emptyBoard, -1, -1);
            end
        end
        
        % adds a node to this node
        function add(obj, board, i, j)
            % case for there being no nodes on this subtree
            if obj.numberOfNodes == 0
                obj.numberOfNodes = 1;
                obj.Nodes(obj.numberOfNodes) = treeNode(board, i, j);
            else
                obj.numberOfNodes = obj.numberOfNodes + 1;
                obj.Nodes(obj.numberOfNodes) = treeNode(board, i, j);
            end
            return
        end
        
        % recurrsive function that gets the node with the minimum value in
        % the tree
        function node = getMin(obj)
            % base case
            if obj.numberOfNodes == 0
                node = obj;
                return
            end
            % loops through all the child nodes of the to find the node
            % with the minimum weight
            weight = Inf;
            for i = 1:obj.numberOfNodes
                holderNode = obj.Nodes(i);
                holderNode = holderNode.getMin();
                if holderNode.weight < weight
                    weight = holderNode.weight;
                end
            end
            obj.weight = weight;
            node = obj;
        end

        % recurrsive function that gets the node with the minimum value in
        % the tree
        function node = getMax(obj)
            % base case
            if obj.numberOfNodes == 0
                node = obj;
                return
            end
            % loops through all the child nodes of the to find the node
            % with the minimum weight
            weight = -Inf;
            for i = 1:obj.numberOfNodes
                holderNode = obj.Nodes(i);
                holderNode = holderNode.getMin();
                if holderNode.weight > weight
                    weight = holderNode.weight;
                end
            end
            obj.weight = weight;
            node = obj;
        end

    end
end

