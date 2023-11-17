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
                array(1) = tre1;
                array(2) = tre1;
                array(3) = tre1;
                array(4) = tre1;
                array(5) = tre1;
                array(6) = tre1;
                array(7) = tre1;
                array(8) = tre1;
                array(9) = tre1;
                obj.Nodes = array;
            end
        end
        
        % adds a node to this node
        function obj = add(obj, node)
            % case for there being no nodes on this subtree
            if obj.numberOfNodes == 0
                obj.numberOfNodes = 1;
                obj.Nodes(obj.numberOfNodes) = node;
            else
                obj.numberOfNodes = obj.numberOfNodes + 1;
                obj.Nodes(obj.numberOfNodes) = node;
            end
            return
        end
        
        % recurrsive function that gets the node with the minimum value in
        % the tree
        function getMin(obj)
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
                holderNode = holderNode.getMax();
                if holderNode.weight > weight
                    weight = holderNode.weight;
                end
            end
            obj.weight = weight;
            node = obj;
        end

    end
end

