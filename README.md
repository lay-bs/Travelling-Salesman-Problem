# Travelling-Salesman-Problem

What it is?

The traveling salesman problem is a computational problem studied for many years, starting in the 1800s by mathematicians. However, by the late 1980s, the problem became of interest to computer engineers and programmers as well, leading to the creation of various resolution methods through specific algorithms and optimizations were made until the optimal solution was reached through proper modeling.

Thus, the traveling salesman problem involves searching for an optimal path where the shortest possible route is sought between N cities (in the context, these would be the cities where the salesman needs to pass to sell/deliver products), starting from the point where the salesman is at the beginning of the journey and returning to that same point at the end of the journey. Additionally, the problem has easily observable characteristics to reach a good solution, such as the fact that having no intersections between paths to the cities already makes the route shorter, hence this would be a possibility that would not need to be analyzed.

Tree algorithm analysis 

Time Complexity:

- The initialization of the distance and visited arrays has a time complexity of O(numCities), as it traverses the total number of cities.
- The `findMin` function is called `(numCities - 1)` times in the main loop of `findShortestPath`, resulting in a time complexity of O(numCities^2).
- The inner loop in `findShortestPath` traverses all cities, resulting in a time complexity of O(numCities^2).
- The outer loop in `findShortestPath` executes `(numCities - 1)` times, resulting in a time complexity of O(numCities^2).
- Therefore, the total time complexity of the algorithm is O(numCities^2).

Space Complexity:

- The space needed for the visited, distances, and parent arrays is O(numCities), as each of them has a size of `numCities`.
- Additional space is used for the `City` structure to represent the coordinates of the cities.
- Therefore, the total space complexity is O(numCities).

Additional Analysis:

- The code uses the value INF (999999) to represent an infinite distance between cities.
- The algorithm finds the shortest path starting from city 0 and visiting all other cities.
- The shortest path is calculated using the Euclidean distance between the coordinates of the cities.
- The shortest path found is printed, along with the total distance traveled.

It can be observed that the time and space efficiency of the created code is not ideal for solving the traveling salesman problem in its classic form, where all cities must be visited once, and the shortest path must be found. 

Considering that the time complexity of the code is dominated by the `findShortestPath()` function, which has a time complexity of O(numCities^2), this complexity is quadratic in relation to the number of cities, meaning that the algorithm's execution time increases rapidly as the number of cities grows. This makes the code inefficient for problems with a large number of cities, as explained earlier for the brute force method.

Furthermore, the current implementation does not use a specific algorithm for the traveling salesman problem, such as the Branch and Bound algorithm or the Nearest Neighbor algorithm. Therefore, the code does not leverage more advanced optimization techniques that could significantly improve time efficiency. However, this was the purpose of this implementation, to analyze and understand why it is not a commonly used method; at no point was it expected to be an optimal code for the problem.

Regarding space efficiency, the program uses an amount of memory proportional to the provided number of cities. While this may be suitable for a reasonable number of cities, problems with a large number of cities may require a significant amount of memory, which can be a limitation on systems with limited resources.

Therefore, if the goal is to efficiently solve the traveling salesman problem on large instances, it would be recommended to use more sophisticated algorithms such as the Branch and Bound algorithm, genetic algorithm, or algorithms based on dynamic programming, which are designed to find optimized solutions for the traveling salesman problem.

Graph algorithm analysis

After implementing the algorithm, I conducted an analysis regarding the efficiency of the code in various important aspects. They are:

Time Efficiency:

Input Reading: Reading the number of vertices and the adjacency matrix of the graph has a time complexity of O(num_vertices^2) because it involves reading all elements of the matrix.
Nearest Neighbor Algorithm: The algorithm traverses all vertices once, looking for the unvisited neighbor with the lowest cost. Therefore, the outer loop has a time complexity of O(num_vertices). Within this loop, the inner loop searches for the unvisited neighbor with the lowest cost, which has a time complexity of O(num_vertices). Overall, the algorithm has a time complexity of O(num_vertices^2).
Therefore, the time complexity of the code is O(num_vertices^2).

Space Efficiency:

Local Variables: The code uses several local variables, such as `graph`, `visited`, `path`, and `total_cost`. The size of these variables is determined by the number of vertices, i.e., `num_vertices`. Therefore, the space used is proportional to `num_vertices`, resulting in a space efficiency of O(num_vertices).

Overall, the time efficiency of the code is reasonable since it has a quadratic complexity in relation to the number of vertices. However, it is important to note that the algorithm used is a simplified heuristic and does not guarantee the optimal solution to the traveling salesman problem. For large instances with a large number of vertices, the execution time can be considerable. Additionally, space efficiency is good because memory consumption is proportional to the number of vertices.

To obtain an optimal solution for the traveling salesman problem, it is necessary to use more advanced algorithms such as dynamic programming or genetic algorithms, which can provide better time efficiency and find more optimized solutions, as mentioned in the analysis for the binary tree algorithm.

Additional Analysis:

It can be observed that the time and space efficiency of the code for solving the traveling salesman problem is not considered good, especially for large instances of the problem. I will detail the reasons:

Time Efficiency:

The implemented algorithm uses the nearest neighbor method to find an approximate solution to the traveling salesman problem. However, this algorithm has a quadratic time complexity in relation to the number of vertices (O(num_vertices^2)). This occurs due to the nested loops used to traverse the vertices and find the unvisited neighbor with the lowest cost. As the number of vertices increases, the algorithm's execution time grows rapidly. Therefore, in large instances of the problem, the time required to find a solution can be significant.

Space Efficiency:

The code uses an adjacency matrix to represent the graph and other arrays to store information about visited vertices, the path traveled, and the total cost. The space required for these arrays is proportional to the number of vertices (O(num_vertices)). Therefore, space efficiency is considered reasonable because memory consumption increases linearly with the number of vertices.

In summary, although the code provides an approximate solution to the traveling salesman problem, its time efficiency is not adequate for large instances of the problem. More advanced algorithms such as dynamic programming or genetic algorithms are generally preferred to obtain optimal or better approximations to the problem. These algorithms have more efficient time and space complexities and can handle larger instances of the traveling salesman problem.

