"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-02-06"
------------------------------------------------------------------------
"""
from Priority_Queue_array import Priority_Queue
from Graph import Graph, Edge

def pq_split_key(source, key):
    """
    -------------------------------------------------------
    Splits a priority queue into two depending on an external
    priority key. The source priority queue is empty when the method
    ends.
    Use: target1, target2 = pq_split_key(source, key)
    -------------------------------------------------------
    Parameters:
        source - a priority queue (Priority_Queue)
        key - a data object (?)
    Returns:
        target1 - a priority queue that contains all values
            with priority higher than key (Priority_Queue)
        target2 - priority queue that contains all values with
            priority lower than or equal to key (Priority_Queue)
    -------------------------------------------------------
    """
    target1 = Priority_Queue()
    target2 = Priority_Queue()
    
    while not source.is_empty():
        if(source.peek() > key):
            target1.insert(source.remove())
        else:
            target2.insert(source.remove())
    return target1, target2

def pq_split_alt(source):
    """
    -------------------------------------------------------
    Splits a priority queue into two with values going to alternating
    priority queues. The source priority queue is empty when the method
    ends. The order of the values in source is preserved.
    Use: target1, target2 = pq_split_alt(source)
    -------------------------------------------------------
    Parameters:
        source - a priority queue (Priority_Queue)
    Returns:
        target1 - a priority queue that contains alternating values
            from source (Priority_Queue)
        target2 - priority queue that contains  alternating values
            from source (Priority_Queue)
    -------------------------------------------------------
    """
    target1 = Priority_Queue()
    target2 = Priority_Queue()
    while not source.is_empty():
        if(len(source)%2 == 0):
            target1.insert(source.remove())
        else:
            target2.insert(source.remove())
    return target1, target2
    
def prims(graph, start_node):
    """
    -------------------------------------------------------
    Applies Prim's Algorithm to a graph.
    Use: edges, total = prims(graph, node)
    -------------------------------------------------------
    Parameters:
        graph - graph to evaluate (Graph)
        start_node - name of node to start evaluation from (str)
    Returns:
        edges - the list of the edges traversed (list of Edge)
        total - total distance of all edges traversed (int)
    -------------------------------------------------------
    """
    path = [start_node]
    edge_queue = Priority_Queue()
    edges = []
    total = 0
    
    for i in graph.edges_by_node(start_node):
        edge_queue.insert(i)
        
    print(' ',edge_queue.peek())
    
    while len(path) < len(graph):
        if(edge_queue.peek() in edges):
            edge_queue.remove(edge_queue.peek())
        else:
            edges.append(edge_queue.peek())
            for i in graph.edges_by_node(edge_queue.peek().end()):
                    edge_queue.insert(i)

            
    
    
    
    
    
        