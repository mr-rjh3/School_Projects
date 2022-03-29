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

from Graph import Graph, Edge
from functions import prims

data = (
    (['A', 'B'], 2), (['A', 'C'], 3), (['A', 'D'], 7), (['B', 'C'], 6),
    (['B', 'G'], 4), (['C', 'E'], 1), (['C', 'F'], 8), (['D', 'E'], 5),
    (['E', 'F'], 4), (['F', 'G'], 2)
)
edges = []
for i in data:
    edges.append(Edge(i[0], i[1]))

for i in edges:
    print(i)


graph = Graph(edges)

prims(graph, 'A')

