// GraphTutorial.cpp : Creates a directed, unweighted graph.
//

//includes for the main function to run properly
#include "stdafx.h"
#include <iostream>
#include "CSC382Graph_NodeBased.h"
#include "CSC382Graph_AdjacencyList.h"
//using namespace std
using namespace std;
//function for testing the node based list
bool Testing_NodeBased()
{
	// Test CSC382Graph_NodeBased Constructor(s)
	CSC382Graph_NodeBased <int> node_list;
	if (node_list.Size() != 0)
	{
		cout << "Fail - list was not created properly" << endl;
	}
	else
	{
		cout << "Success - list was created properly" << endl;
	}
	//Test functions of the CSC382Graph_NodeBased class and affiliated classes
	cout << "Testing the functions of the class" << endl;
	node_list.AddEdge(node_list.FindVertex(10), node_list.FindVertex(10));
	node_list.FindVertex(10);
	node_list.RemoveEdge(node_list.FindVertex(10), node_list.FindVertex(10));
	node_list.RemoveVertex(10);
	node_list.Size();
	node_list.Insert(10);
	node_list.Insert(10);
	node_list.Insert(-10);
	node_list.AddEdge(node_list.FindVertex(10), node_list.FindVertex(10));
	node_list.AddEdge(node_list.FindVertex(-10), node_list.FindVertex(10));
	cout << " " << node_list.FindVertex(10) << endl;
	cout << " " << node_list.FindVertex(-10) << endl;
	node_list.RemoveEdge(node_list.FindVertex(10), node_list.FindVertex(15));
	node_list.RemoveEdge(node_list.FindVertex(10), node_list.FindVertex(10));
	node_list.RemoveVertex(10);
	int S = node_list.Size();
	cout << "Size of graph is " << S << endl;

	//Test creating lots of nodes and edges
	cout << "Adding 20 nodes and 20 edges to graph" << endl;
	//creating 20 nodes
	node_list.Insert(15);
	node_list.Insert(20);
	node_list.Insert(25);
	node_list.Insert(30);
	node_list.Insert(35);
	node_list.Insert(40);
	node_list.Insert(45);
	node_list.Insert(50);
	node_list.Insert(55);
	node_list.Insert(60);
	node_list.Insert(65);
	node_list.Insert(70);
	node_list.Insert(75);
	node_list.Insert(80);
	node_list.Insert(85);
	node_list.Insert(90);
	node_list.Insert(95);
	node_list.Insert(100);
	node_list.Insert(-15);
	node_list.Insert(-20);
	//adding 20 edges to the list
	node_list.AddEdge(node_list.FindVertex(15), node_list.FindVertex(15));
	node_list.AddEdge(node_list.FindVertex(20), node_list.FindVertex(30));
	node_list.AddEdge(node_list.FindVertex(25), node_list.FindVertex(25));
	node_list.AddEdge(node_list.FindVertex(30), node_list.FindVertex(30));
	node_list.AddEdge(node_list.FindVertex(35), node_list.FindVertex(35));
	node_list.AddEdge(node_list.FindVertex(40), node_list.FindVertex(40));
	node_list.AddEdge(node_list.FindVertex(45), node_list.FindVertex(45));
	node_list.AddEdge(node_list.FindVertex(50), node_list.FindVertex(50));
	node_list.AddEdge(node_list.FindVertex(55), node_list.FindVertex(55));
	node_list.AddEdge(node_list.FindVertex(60), node_list.FindVertex(60));
	node_list.AddEdge(node_list.FindVertex(65), node_list.FindVertex(65));
	node_list.AddEdge(node_list.FindVertex(70), node_list.FindVertex(70));
	node_list.AddEdge(node_list.FindVertex(75), node_list.FindVertex(75));
	node_list.AddEdge(node_list.FindVertex(80), node_list.FindVertex(80));
	node_list.AddEdge(node_list.FindVertex(85), node_list.FindVertex(85));
	node_list.AddEdge(node_list.FindVertex(90), node_list.FindVertex(90));
	node_list.AddEdge(node_list.FindVertex(95), node_list.FindVertex(95));
	node_list.AddEdge(node_list.FindVertex(100), node_list.FindVertex(100));
	node_list.AddEdge(node_list.FindVertex(-15), node_list.FindVertex(-15));
	node_list.AddEdge(node_list.FindVertex(-20), node_list.FindVertex(-20));

	//showing the graph size and removing some items and redisplaying the graph size
	cout << "More testing of the functions" << endl;
	S = node_list.Size();
	cout << "Size of graph is " << S << endl;
	node_list.RemoveEdge(node_list.FindVertex(15), node_list.FindVertex(15));
	node_list.RemoveVertex(15);
	S = node_list.Size();
	cout << "New size of graph is " << S << endl;
	node_list.FindVertex(-20);
	node_list.RemoveEdge(node_list.FindVertex(-20), node_list.FindVertex(-20));
	node_list.RemoveVertex(-20);
	S = node_list.Size();
	cout << "New size of graph is " << S << endl;
	//displaying all nodes from the list
	cout << " " << node_list.FindVertex(15) << endl;
	cout << " " << node_list.FindVertex(20) << endl;
	cout << " " << node_list.FindVertex(25) << endl;
	cout << " " << node_list.FindVertex(30) << endl;
	cout << " " << node_list.FindVertex(35) << endl;
	cout << " " << node_list.FindVertex(40) << endl;
	cout << " " << node_list.FindVertex(45) << endl;
	cout << " " << node_list.FindVertex(50) << endl;
	cout << " " << node_list.FindVertex(55) << endl;
	cout << " " << node_list.FindVertex(60) << endl;
	cout << " " << node_list.FindVertex(65) << endl;
	cout << " " << node_list.FindVertex(70) << endl;
	cout << " " << node_list.FindVertex(75) << endl;
	cout << " " << node_list.FindVertex(80) << endl;
	cout << " " << node_list.FindVertex(85) << endl;
	cout << " " << node_list.FindVertex(90) << endl;
	cout << " " << node_list.FindVertex(95) << endl;
	cout << " " << node_list.FindVertex(100) << endl;
	cout << " " << node_list.FindVertex(-15) << endl;
	cout << " " << node_list.FindVertex(-20) << endl;


	system("pause");
	return false;
}
//function for testing the adj list
bool Testing_AdjacencyList()
{
	// Test CSC382Graph_AdjacencyList Constructor(s)
	CSC382Graph_AdjacencyList <int> adj_list;
	if (adj_list.GraphSize() != 0)
	{
		cout << "Fail - list was not created properly" << endl;
	}
	else
	{
		cout << "Success - list was created properly" << endl;
	}

	// Test functions of the CSC382Graph_AdjacencyList class
	cout << "Testing the functions of the class" << endl;
	adj_list.PrintAdjacencyList();
	adj_list.GraphSize();
	adj_list.NumberOfEdges(11);
	adj_list.FindVertex(10);
	adj_list.AddEdge(adj_list.FindVertex(10), adj_list.FindVertex(13));
	adj_list.AddEdge(adj_list.FindVertex(11), 12);
	adj_list.AddVertex(15);
	adj_list.AddVertex(-15);
	adj_list.FindVertex(10);
	adj_list.AddEdge(adj_list.FindVertex(10), 13);
	adj_list.AddEdge(adj_list.FindVertex(10), adj_list.FindVertex(13));
	adj_list.AddEdge(adj_list.FindVertex(10), adj_list.FindVertex(15));
	adj_list.IsEdge(13);
	adj_list.NumberOfEdges(10);
	adj_list.GraphSize();
	adj_list.PrintAdjacencyList();

	// Test creating lots of nodes and edges
	cout << "Adding 20 vertex and 20 edges to graph" << endl;
	//creating twenty nodes/vertex to test
	adj_list.AddVertex(16);
	adj_list.AddVertex(20);
	adj_list.AddVertex(25);
	adj_list.AddVertex(30);
	adj_list.AddVertex(35);
	adj_list.AddVertex(40);
	adj_list.AddVertex(45);
	adj_list.AddVertex(50);
	adj_list.AddVertex(55);
	adj_list.AddVertex(60);
	adj_list.AddVertex(70);
	adj_list.AddVertex(75);
	adj_list.AddVertex(80);
	adj_list.AddVertex(85);
	adj_list.AddVertex(90);
	adj_list.AddVertex(95);
	adj_list.AddVertex(100);
	adj_list.AddVertex(105);
	adj_list.AddVertex(110);
	adj_list.AddVertex(115);
	//creating twenty edges to test
	adj_list.AddEdge(adj_list.FindVertex(16), 200);
	adj_list.AddEdge(adj_list.FindVertex(16), 10);
	adj_list.AddEdge(adj_list.FindVertex(16), 13);
	adj_list.AddEdge(adj_list.FindVertex(10), 13);
	adj_list.AddEdge(adj_list.FindVertex(20), 13);
	adj_list.AddEdge(adj_list.FindVertex(25), 13);
	adj_list.AddEdge(adj_list.FindVertex(30), 13);
	adj_list.AddEdge(adj_list.FindVertex(35), 13);
	adj_list.AddEdge(adj_list.FindVertex(40), 200);
	adj_list.AddEdge(adj_list.FindVertex(45), 200);
	adj_list.AddEdge(adj_list.FindVertex(50), 200);
	adj_list.AddEdge(adj_list.FindVertex(55), 200);
	adj_list.AddEdge(adj_list.FindVertex(60), 200);
	adj_list.AddEdge(adj_list.FindVertex(65), adj_list.FindVertex(70));
	adj_list.AddEdge(adj_list.FindVertex(75), adj_list.FindVertex(80));
	adj_list.AddEdge(adj_list.FindVertex(85), adj_list.FindVertex(90));
	adj_list.AddEdge(adj_list.FindVertex(95), adj_list.FindVertex(100));
	adj_list.AddEdge(adj_list.FindVertex(105), adj_list.FindVertex(110));
	adj_list.AddEdge(adj_list.FindVertex(110), adj_list.FindVertex(115));
	adj_list.AddEdge(adj_list.FindVertex(115), adj_list.FindVertex(16));
	//displaying the list size and all nodes in the lsit
	adj_list.GraphSize();
	adj_list.PrintAdjacencyList();

	system("pause");
	return false;
}

int main()
{
	// Call testing functions
	cout << "Testing Adjacency list" << endl;
	Testing_AdjacencyList();
	cout << "Testing NodeBased list" << endl;
	Testing_NodeBased();

    return 0;
}

