//this list is a weighted directed list. This is due to the fact that there is a value of some type for each node and
//it is directed because the user can make the nodes go only in one direction
//opening statement
#pragma once
//stating that the following class is templated, and creating the class for the adj list
template <typename T>
class CSC382Graph_AdjacencyList
{
	//naming what is public for the class
public:

	//constructor to create/instantiate the list
	CSC382Graph_AdjacencyList()
	{
		graph_adjacencylist = new vector<list<T>*>();
	}

	//deconstructor for deleting/ending the list/class iteration
	~CSC382Graph_AdjacencyList()
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (iter != nullptr)
			{
				delete iter;
			}
		}
		delete graph_adjacencylist;
	}

	//adding a vertex to the graph list
	list<T>* AddVertex(T data)
	{
		// Attempt to find if the vertex is already in the graph
		if (IsVertex(data))
		{
			cout << "Vertex is already in the graph. Duplicate NOT added." << endl;
			return nullptr;
		}
		//otherwise does the following
		//it creates a new list for that vertex and it's edges
		else
		{

			list<T>* new_vertex = new list<T>();		// Create new list to house the vertex and its edges
			new_vertex->push_back(data);				// Data is added as the first element in the list
			graph_adjacencylist->push_back(new_vertex);	// list pointer is added to the graph
			return new_vertex;
		}
	}

	//if trying to add an edge it takes a input of which vertex through isvertex() and the data to enter
	bool AddEdge(list<T>* vertex, T data)
	{
		//if the vertex does not exist it will return false due to no vertex of that data being available
		if(!IsVertex(vertex))
		{
			cout << "Vertex specified does not exist. Cannot add edge to a non-existant vertex.";
			return false;
		}
		//checks to see if data exists if so it adds it to the vertex at the end with push back
		if (!IsVertex(data))		// Data must be an existing vertex or it will need to be created.
		{
			vertex->push_back(data);
			return true;
		}
		//otherwise it creates a new vertex and then pushes it back in the list and returns true
		else
		{
			list<T>* new_vertex = AddVertex(data);
			new_vertex->push_back(data);
			return true;
		}
	}

	//second entry value if the starting and end vertex are selected
	//if they are both available vertex the function will connect the two together by the way of edge/vertex
	//and making one act like both an edge and vertex at the same time
	bool AddEdge(list<T>* starting_vertex, list<T>* ending_vertex)
	{
		//if isvertex is the starting or end vertex it will not allow the data to be entered due to not having an existing vertex in the graph
		if (!IsVertex(starting_vertex) || !IsVertex(ending_vertex))
		{
			cout << "Cannot AddEdge because one of the specified vertices does not exist in the graph." << endl;
			return false;
		}
		if (!IsEdge(starting_vertex, ending_vertex->front()))		// Prevent adding duplicate edges
		{
			starting_vertex->push_back(ending_vertex->front());
			return true;
		}
		return false;
	}

	//bool for searching for a specific vertex based on input for the first calue in the list
	bool IsVertex(T data)
	{
		//loops through each list in the graph list
		for (list<T>* iter : *graph_adjacencylist)
		{
			// Check the first value in the list which is the primary vertex
			if (iter->front() == data)
			{
				return true;
			}
		}
		return false;
	}

	//bool for searching through the entire list in order to find a specific vertex on the graph
	//then returns true if found otherwise it is false
	bool IsVertex(list<T>* vertex_to_find)
	{
		//loops through each list in the graph list
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (iter == vertex_to_find)
			{
				return true;
			}
		}
		return false;
	}

	//searches for an edge by itself by looking at each vertex and their edges 
	//and if edge found returns true otherwise returns false due to no edge of that data amount found
	bool IsEdge(T edge_to_find)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (IsEdge(iter, edge_to_find))
			{
				return true;
			}
		}
		return false;
	}

	//bool for finding an edge based on the given vertex and the edge to find
	//looks throguh the list for each edge and then if found returns true
	//otherwise returns false
	bool IsEdge(list<T>* vertex, T edge_to_find)
	{
		for (T i : *vertex)
		{
			// skip checking the primary vertex and only check edges
			if (vertex->front() == i)
			{
				continue;
			}
			if (i == edge_to_find)
			{
				return true;
			}
		}
		return false;
	}

	//finding a specific vertex based on it's value
	//looks at the front node/vertex of each individual list
	//if vertex looking found return which iteration it was in
	//otherwise returns nullptr
	list<T>* FindVertex(T data)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (iter->front() == data)
			{
				return iter;
			}
		}
		return nullptr;
	}

	//void for showing the list
	//starts off with the first list in the graph and displays all it's nodes and then
	//continues on to the next lsit and repeats till all the lists/nodes are shown
	void PrintAdjacencyList()
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			for (T i : *iter)
			{
				// skip checking the primary vertex and only check edges
				if (iter->front() == i)		// Prints the Vertex 
				{
					cout << "Vertex = " << i << "   Edges = ";
				}
				else	// Prints the Edges
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}

	//looks through the graph for a specific vertex
	//then if that vertex is not nullptr will display how many edges/nodes are in that list
	int NumberOfEdges(T vertex_data)
	{
		list<T>* vertex = FindVertex(vertex_data);

		if(vertex != nullptr)
		{
			return NumberOfEdges(vertex);
		}
		return -1;
	}

	//takes the given vertex and displays how many nodes are there
	int NumberOfEdges(list<T>* vertex)
	{
		return vertex->size();
	}

	//int tos return how mane nodes are in the adj list
	int GraphSize()
	{
		return graph_adjacencylist->size();
	}
	//private variables of the list
private:
	//the vecotr list that the graph program uses.
	vector<list<T>*>* graph_adjacencylist;
};