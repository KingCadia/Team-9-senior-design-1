classdef treeNode
    %TREE Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        numberOfNodes
        Nodes
        ij
        board
        weight
    end
    
    methods
        function obj = treeNode(board, i, j)
            %TREE Construct an instance of this class
            %   Detailed explanation goes here
            obj.numberOfNodes = 0;
            obj.board = board;
            obj.ij = [i, j];
            obj.weight = 0;
            obj.Nodes = [];
        end
        
        % adds a node to this node
        function add(obj, node)
            newNode = treeNode(node.board, node.i, node.j);
            % case for there being no nodes on this subtree
            if obj.numberOfNodes == 0
                obj.numberOfNodes = 1;
                obj.Nodes(obj.numberOfNodes) = newNode;
            else
                obj.numberOfNodes = obj.numberOfNodes + 1;
                obj.Nodes(obj.numberOfNodes) = newNode;
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

