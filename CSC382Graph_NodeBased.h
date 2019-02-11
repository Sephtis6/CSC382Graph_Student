//this list is a weighted directed list. This is due to the fact that there is a value of some type for each node and
//it is directed because the user can make the nodes go only in one direction
//opening statement
#pragma once
//what to let the system knoww you are using from various places
#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>

//using namespace std so don't have to write std:: at every line
using namespace std;
//creating the class that uses templated type of t
template <typename T>
class CSC382Graph_Vertex
{
	//private variables of the class that it uses
private:
	//using a data with type of T and creating the list of vertices
	T data;
	list<CSC382Graph_Vertex<T>*>* connected_vertices;
public:
	//constructor of the class
	CSC382Graph_Vertex()
	{
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();
		data = NULL;
	}
	//constructor that takes in node_data
	//and then creates a new list like the original but also adds the given data to the list
	CSC382Graph_Vertex(T node_data)
	{
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();
		data = node_data;
	}
	//deconstructor to delete the list for the class
	~CSC382Graph_Vertex()
	{
		delete connected_vertices;
	}

	//function to add an edge to the connected graphs by making one vertex act like the edge of anothe while still being a vertex
	void AddEdge(CSC382Graph_Vertex<T>* vertex_connection)
	{
		if (vertex_connection != this)
		{
			connected_vertices->push_back(vertex_connection);
		}
	}

	//function to loop through the list of connected vertices in order to find the vertex looked for
	//and returns true if it is in the list otherwise it returns false
	bool VertexConnected(CSC382Graph_Vertex<T>* vertex_to_find)
	{
		for(CSC382Graph_Vertex<T>* i : *connected_vertices)
		{
			if(i == vertex_to_find)
			{
				return true;
			}
		}
		return false;
	}

	//function in order to remove an edge from the list as long as it exists in the current list
	void RemoveEdge(CSC382Graph_Vertex<T>* edge_to_remove)
	{
		if (edge_to_remove != nullptr)
		{
			connected_vertices->remove(edge_to_remove);
		}
	}

	//returns the data of whatever is the node that it is pointing to
	T GetData()
	{
		return data;
	}

	//sets the data at that node to the inputed data
	void SetData(T data_param)
	{
		data = data_param;
	}

};

//templated class for the node list to be used for the graph
template <typename T>
class CSC382Graph_NodeBased
{
	//private variables and such of the class
private:
	//creating the list for the graph to use
	list<CSC382Graph_Vertex<T>*>* graph;

public:
	//constructor for the class
	CSC382Graph_NodeBased()
	{
		graph = new list<CSC382Graph_Vertex<T>*>;
	}

	//constructor that takes in one arguement for the initial vertex of the graph
	CSC382Graph_NodeBased(CSC382Graph_Vertex<T>* initial_vertex)
	{
		graph = new list<CSC382Graph_Vertex<T>*>;
		Insert(initial_vertex);
	}

	//deconstructor for the class that deletes the graph list
	~CSC382Graph_NodeBased()
	{
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			if (iter != nullptr && iter != NULL)
			{
				delete iter;
			}
		}
		delete graph;
	}

	//function to insert a vertex to the graph by way of built in push back it onto the list
	//also uses the arguement of a node templated pointer to a vertex
	CSC382Graph_Vertex<T>* Insert(CSC382Graph_Vertex<T>* vertex)
	{
		graph->push_back(vertex);
		return vertex;
	}

	//takes in given data and then creates a new node containing that data and then
	//calls the node based insert to add that created node to the list as a vertex
	CSC382Graph_Vertex<T>* Insert(T data)
	{
		CSC382Graph_Vertex<T>* new_node = new CSC382Graph_Vertex<T>(data);
		return Insert(new_node);
	}

	//calls a function  to find the vertex with the correct data
	//then calls the function to remove the vertex
	void RemoveVertex(T data)
	{
		CSC382Graph_Vertex<T>* vertex_to_remove = FindVertex(data);
		RemoveVertex(vertex_to_remove);
	}

	//function to temove the vertex by way of built in remove function
	void RemoveVertex(CSC382Graph_Vertex<T>* vertex_to_remove)
	{
		graph->remove(vertex_to_remove);
	}

	//function to add an edge by calling the built add edge function to the node class for the specified start vertex
	void AddEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)
	{
		start_vertex->AddEdge(end_vertex);
	}

	//function to remove an edge by calling the build remove edge function to the node class for the specified start vertex
	void RemoveEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)
	{
		start_vertex->RemoveEdge(end_vertex);
	}

	//function to search in a specified vertex to see if there is the wanted edge in that vertex
	bool IsEdge(CSC382Graph_Vertex<T>* vertex_to_search_in, CSC382Graph_Vertex<T>* edge_to_check_for)
	{
		return vertex_to_search_in->VertexConnected(edge_to_check_for);
	}

	//uses input data
	//function to loop through the graph list and check each node to see if the
	//looked for vertex has already been created and if so returns where it was found otherwise return nullptr
	CSC382Graph_Vertex<T>* FindVertex(T data_to_find)
	{
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			if (iter->GetData() == data_to_find)
			{
				return iter;
			}
		}
		return nullptr;
	}

	//uses input node
	//function to loop through the graph list and check each node to see if the
	//looked for vertex has already been created and if so returns where it was found otherwise return nullptr
	CSC382Graph_Vertex<T>* FindVertex(CSC382Graph_Vertex<T>* node_to_find)
	{
		for(CSC382Graph_Vertex<T>* iter : *graph)
		{
			if(iter == node_to_find)
			{
				return iter;
			}
		}
		return nullptr;
	}

	//function to get the size of the graph
	int Size()
	{
		return graph->size();
	}
};
