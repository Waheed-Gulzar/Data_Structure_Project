                                //Waheed Gulzar 22i2526 SE-A
                              

#pragma once
#include<iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Function to set text color
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to reset text color
void resetTextColor() {
    HANDLE Default = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Default, 7);  // 7 is the default color
}
class node
{
public:
	int position;
	char shape;
	node* next;

};
class Hurdles_and_PowerUps
{
private:
	node* front;
	node* rear;
public:
	Hurdles_and_PowerUps()
	{

		front = NULL;
		rear = NULL;
	}
	void enqueue()
	{
		srand(static_cast<unsigned>(time(0)));
		char b;
		int a = rand() % 98;
		int check = rand() % 2;
		if (check == 0)
		{
			b = '#';
		}
		else
			b = '*';

		node* temp = new node;
		temp->position = a;
		temp->shape = b;

		temp->next = NULL;

		if (front == NULL)
		{
			front = temp;
			rear = temp;
		}
		else
		{
			rear = temp;
			rear->next = temp;
		}
	}

	bool empty()
	{
		if (front == NULL)
		{
			return 1;
		}
		return 0;
	}
	node* dequeue()
	{
		if (!empty()) {
			node* temp = front;
			node* prev = nullptr;

			// Traverse the queue to find the node before the rear
			while (temp->next != nullptr && temp->next != rear) {
				prev = temp;
				temp = temp->next;
			}

			// Create a new node to hold the data of the rear node
			node* New = new node;
			New->position = rear->position;
			New->shape = rear->shape;

			// Check if front is now equal to rear (i.e., only one node left in the queue)
			if (front == rear) {
				rear = nullptr;
			}
			else {
				// Delete the rear node and set the new rear
				delete rear;
				rear = prev;
				//rear->next = nullptr;
			}

			// Enqueue a new obstacle after dequeueing
			enqueue();

			return New;
		}

		return nullptr; 
	}



};

class Node {
public:
    int score;
   string Name;
    Node* next;

    Node(int value) : score(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the list
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to insert a node at the beginning of the list
    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head;
        cout << "Score :" << head->score;
        cout << endl;
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->score == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->score != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Value not found in the list." << endl;
        }
        else {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
    // Function to delete the last node in the list
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        if (head->next == nullptr) {
            // Only one node in the list
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        // Delete the last node
        delete current->next;
        current->next = nullptr;
    }

    // Function to search for a value in the list
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->score == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
  


};

struct Highest {
    string name;
    int score;
};

void fileWriting(string s, int a) {
    ofstream outputFile("EmployeeData_Output.csv", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Error opening the output file." << endl;
        return; // Exit with an error code
    }



    // Writing data to the CSV file
    string name = s;
    int score = a;

    // Writing data to the CSV file
    outputFile << name << "," << score << "\n";


    // Close the file
    outputFile.close();
}


struct adjNode {
    int v, w;
    adjNode* next;
};

class Graph {
    Hurdles_and_PowerUps obj;
    SinglyLinkedList link;
    int count;
    int currentNode;
    Graph()
    {
        count = 0;
        currentNode = 0;
    }
    adjNode* addVertices(int v, adjNode* head) {	//adding vertices without weights
        adjNode* newNode = new adjNode;
        newNode->v = v;
        newNode->next = head;
        return newNode;
    }
    // adding vertices with weights
    adjNode* addVerticesWeights(int v, adjNode* head, int w) {
        adjNode* newNode = new adjNode;
        newNode->v = v;
        newNode->w = w;
        newNode->next = head;
        return newNode;
    }
public:
    void set_count(int a)
    {
        currentNode = a;
    }
    int adjacencyList[100];
    adjNode** adjList;
    Graph(int V) {
        this->count = V;
        adjList = new adjNode * [V];
        for (int i = 0; i < V; i++) {
            adjList[i] = NULL;
        }
        for (int i = 0; i < V; i++) {
            adjacencyList[i] = 1;
        }
        srand(static_cast<unsigned>(time(0)));
        currentNode = 0;
        obj.enqueue();
        link.insertFront(0);
    }
    void addWeightedEdges(int src, int dest, int w) {
        adjList[src] = addVerticesWeights(dest, adjList[src], w);
        adjList[dest] = addVerticesWeights(src, adjList[dest], w);
    }

    void printWeightedGraph() {

        for (int i = 0; i < count; i++) {
            adjNode* data = adjList[i];
            cout << "\n Vertex " << i << " is linked to";
            while (data) {
                cout << " vertex " << data->v << " weight: " << data->w << ",";
                data = data->next;
            }
            cout << " NULL";
            cout << endl;
        }
    }
    void Nodes_Connections()
    {
        // Seed the random number generator
        srand(static_cast<unsigned>(time(0)));
        // Connect nodes 1-9 to a right node
        for (int i = 0; i <= count; ++i) {
            int weight = 0;
            if ((i % (count / 10) == ((count / 10) - 1)) && (i != (count - 1)))
            {
                int a = rand() % 2;
                if (a)
                {
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i, i + 10, weight);
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i + 10, i, weight);
                }
                else if (i == 89)
                {
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i, i + 10, weight);
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i + 10, i, weight);
                }
            }
            else if ((i < 9 || i % 10 == 0) && i != 90)
            {
                int r = rand() % 2;
                if (r==1)
                {
                    //random weight
                    //random weight
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i, i + 10, weight);
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i + 10, i, weight);
                }
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i, i + 1, weight);
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i + 1, i, weight);
            }
            else if ((i >= 90 && i < 99))
            {
                weight = rand() % 3 + 1;
                addWeightedEdges(i, i + 1, weight);
                weight = rand() % 3 + 1;
                addWeightedEdges(i + 1, i, weight);
            }
            else
            {
                int connections = rand() % 2;
                if (connections == 1)
                {
                    //random weight
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i, i + 1, weight);
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i + 1, i, weight);
                }
                else
                {
                    //random weight
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i, i + 1, weight);
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i + 1, i, weight);
                    //random weight
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i, i + 10, weight);
                    weight = rand() % 3 + 1;
                    addWeightedEdges(i + 10, i, weight);
                }
            }
        }
    }
    
    bool count_connections(int i) {
        adjNode* data = adjList[i];

        while (data) {
            // Check if data->v is within bounds
            if (data->v >= 0 && data->v < 100) {
                // Check if the adjacent node is i + 10
                if (data->v == i + 10) {
                    return true;
                }
            }

            data = data->next;
        }

        return false;
    }
    void displayGraph(int a, int end) {
        if (a % 3 == 0)
        {
            node* num = obj.dequeue();

            if (adjacencyList[num->position] == 1)
            {
                if (num->shape == '*')
                    adjacencyList[num->position] = 0;
                else if (num->shape == '#')
                    adjacencyList[num->position] = 2;

            }
            delete num;
        }
        system("cls");

        link.display();
        for (int i = 0; i < count; ++i) {
            if (i % (count / 10) == 0) {
                cout << endl;

                if (i >= (count / 10)) {

                    i -= 10;
                    for (int j = 0; j <= ((count / 10) - 1); ++j, i++) {
                        
                        if (count_connections(i) == 1)
                            cout << "|  ";
                        else
                            cout << "   ";


                    }

                    cout << endl;
                }
            }

            setTextColor(FOREGROUND_GREEN);

            if (i == currentNode) {

                setTextColor(FOREGROUND_RED);
                cout << "c";
                resetTextColor();
                setTextColor(FOREGROUND_GREEN);

            }
            else if ((i < (count / 10) || (i % (count / 10) == ((count / 10) - 1) && i != (count - 1)) || i % (count / 10) == 0 || i < (count))&&i!=end) {
                if (adjacencyList[i] == 1)
                    cout << "+";
                else if (adjacencyList[i] == 0)
                {
                    setTextColor(FOREGROUND_RED);
                    cout << "*";
                    setTextColor(FOREGROUND_GREEN);
                }
                else if (adjacencyList[i] == 2)
                {
                    setTextColor(FOREGROUND_RED);
                    cout << "#";
                    setTextColor(FOREGROUND_GREEN);
                }
            }

            if (i % (count / 10) != ((count / 10) - 1)) {
                cout << "--";
            }
            if (i == end - 1)
            {
                setTextColor(FOREGROUND_RED);
                cout << "F";
            }

        }


        cout << "\n";
        setTextColor(FOREGROUND_BLUE);
        cout << "^ ->arrow        Go Up\nv ->arrow        Go Down\n->  arrow        Go Right\n<-  arrow        Go left\n";
        resetTextColor();
    }

    bool Check_If_End(int a) {
        if (currentNode == a-1)
        {
            return true;
        }
        else
            return false;
    }
    int move(int direction, int count, int& score) {
        bool a = false;
        adjNode* data = adjList[currentNode];

        switch (direction) {

        case 72:  // Up

            while (data) {

                if ((currentNode > 9) && (currentNode - 10 == data->v)) {
                    if (adjacencyList[currentNode - 10] == 0) {
                        score = score * 2;
                        adjacencyList[currentNode - 10] = 1;

                        score = score + 1;
                        currentNode -= 10;

                    }

                    else if (adjacencyList[currentNode - 10] == 2)
                    {
                        cout << "You Hit A Hurdle \n";

                        score = score / 5;
                        currentNode -= 10;
                        // adjacencyList[currentNode - 10] = 1;
                    }
                    else if (adjacencyList[currentNode - 10] == 1)
                    {
                        currentNode -= 10;
                        score++;
                    }

                    break;
                }
                else
                    a = true;
                a = false;
                data = data->next;
            }
            if (a)
            {
                score = score / 5;
                cout << "There is no track \n";
                DWORD sleep = 500;
                Sleep(sleep);
            }

            break;
        case 80:  // Down
            while (data) {
                // cout << "Han bhai";
                if ((currentNode < 90) && (currentNode + 10 == data->v)) {
                    if (adjacencyList[currentNode + 10] == 0) {
                        score = score * 2;
                        adjacencyList[currentNode + 10] = 1;
                        score = score + 1;

                        currentNode += 10;
                    }
                    else if (adjacencyList[currentNode + 10] == 2)
                    {
                        cout << "You Hit A Hurdle \n";

                        score = score / 5;
                        currentNode += 10;
                        // adjacencyList[currentNode - 10] = 1;
                    }
                    else if (adjacencyList[currentNode + 10] == 1)
                    {
                        currentNode += 10;
                        score++;
                    }
                    a = false;
                    break;
                }
                else
                    a = true;

                data = data->next;

            }
            if (a)
            {
                score = score / 5;
                cout << "There is no track \n";
                DWORD sleep = 500;
                Sleep(sleep);
            }

            break;
        case 75:  // Left
            while (data) {
                if ((currentNode % 10 != 0) && (currentNode - 1 == data->v)) {
                    if (adjacencyList[currentNode - 1] == 0) {
                        score = score * 2;
                        adjacencyList[currentNode - 1] = 1;
                        score += 1;
                        currentNode--;
                    }
                    else if (adjacencyList[currentNode - 1] == 2)
                    {
                        cout << "You Hit A Hurdle \n";

                        score = score / 5;
                        currentNode--;
                        // adjacencyList[currentNode - 10] = 1;
                    }
                    else if (adjacencyList[currentNode - 1] == 1)
                    {
                        currentNode -= 1;
                        score++;
                    }
                    a = false;
                    break;
                }
                else
                    a = true;
                data = data->next;

            }
            if (a)
            {
                score = score / 5;
                cout << "There is no track \n";
                DWORD sleep = 500;
                Sleep(sleep);
            }

            break;
        case 77:  // Right
            while (data) {
                if ((currentNode % 10 != 9) && (currentNode + 1 == data->v)) {
                    if (adjacencyList[currentNode + 1] == 0) {
                        score = score * 2;
                        adjacencyList[currentNode + 1] = 1;
                        currentNode += 1;

                    }
                    else if (adjacencyList[currentNode + 1] == 2)
                    {
                        cout << "You Hit A Hurdle \n";

                        score = score / 5;
                        currentNode += 1;
                        // adjacencyList[currentNode - 10] = 1;
                    }
                    else if (adjacencyList[currentNode + 1] == 1)
                    {
                        currentNode += 1;
                        score++;
                    }
                    a = false;
                    // currentNode++;
                    break;
                }
                else
                    a = true;

                data = data->next;

            }
            if (a)
            {
                score = score / 5;
                cout << "There is no track \n";
                DWORD sleep = 500;
                Sleep(sleep);
            }

            break;
        default:
            break;
        }




        link.insertFront(score);

        count++;
        return count;
    }

};

class BinaryNode {
public:
    int s;
    string n;
    BinaryNode* left;
    BinaryNode* right;


    BinaryNode() {
        left = NULL;
        right = NULL;
        s = 0;
        n = "";
    }
};

class BST {
    BinaryNode* root;


public:
    BST() {
        root = NULL;
    }
    BinaryNode* getRoot() {
        return root;
    }
    void insertNode(string n, int s) {
        BinaryNode* newNode, * nodePtr; // Pointer to create new node & traverse tree

        newNode = new BinaryNode(); // Create a new node
        newNode->n = n;
        newNode->s = s;
        newNode->left = newNode->right = NULL;

        if (!root) {
            root = newNode;

        } // I f tree i s empty.
        else {
            // Tree i s not empty
            nodePtr = root;
            while (nodePtr != NULL) {
                if (s < nodePtr->s) {
                    // Left subtree
                    if (nodePtr->left) { nodePtr = nodePtr->left; }
                    else {
                        nodePtr->left = newNode;

                        break;
                    }
                }
                else if (s > nodePtr->s) {
                    // Right subtree
                    if (nodePtr->right) nodePtr = nodePtr->right;
                    else {
                        nodePtr->right = newNode;

                        break;
                    }
                }
                else { cout << " "; break; }

            }
        }
    }




    void display() {
        cout << "||=============Leader Board===========||\n\n";
        cout << "Name: " << root->n << "            Score: " << root->s << "  \n";
        cout << "Name: " << root->left->n << "          Score: " << root->left->s << "\n";
        cout << "Name: " << root->left->left->n << "            Score: " << root->left->left->s << "\n  ";
    }
};
void fileReading(Highest obj[], int a) {

    BST bst;
    ifstream inputFile("EmployeeData_Output.csv");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return; // Exit with an error code
    }

    // Read and parse the file line by line
    int i = 0;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;
        int col = 1;
        while (getline(ss, word, ',')) {
            if (col == 1) {

                obj[i].name = word;
            }
            else if (col == 2) {
                obj[i].score = stod(word);
            }

            col += 1;
        }
        i += 1;
    }
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (obj[j].score < obj[j + 1].score) {
                // Swap if the current element is less than the next element
                swap(obj[j], obj[j + 1]);
            }
        }
    }
    for (int i = 0; i < 10 - 1; ++i) {
        if (obj[i].score < 0)
            break;
        else
            bst.insertNode(obj[i].name, obj[i].score);
       
    }
    if (a == 0)
    {
        for (int i = 0; i < 10 - 1; ++i) {
            if (obj[i].score < 0)
                break;
            else
                bst.insertNode(obj[i].name, obj[i].score);
            cout << obj[i].name << "   " << obj[i].score << endl;
        }
    }
    else if(a==1)
    bst.display();
    // Close the file
    inputFile.close();
}
void menu(int selectedOption)
{
    system("cls"); // Clear the console screen
    setTextColor(FOREGROUND_RED);

    cout << "\n------->>Welcome to Car Game<<------\n\n\n\n";
    for (int i = 0; i < 4; ++i) {
        if (i == selectedOption) {
            setTextColor(FOREGROUND_RED | BACKGROUND_INTENSITY); // White rectangle background
        }

        // cout << "               "; // Some space before the text

        if (i != selectedOption) {
            setTextColor(FOREGROUND_GREEN);

        }

        switch (i) {
        case 0:
            cout << "*********Start Game*********\n";
            break;
        case 1:
            cout << "*******Players' Score*******\n";
            break;
        case 2:
            cout << "********Leader Board*******\n";
            break;
        case 3:
            cout << "************Help************\n";
            break;


            if (i == selectedOption) {
                setTextColor(FOREGROUND_GREEN | BACKGROUND_INTENSITY); // White rectangle background
            }

            //  cout << "               "; // Some space after the text

            if (i == selectedOption) {
                resetTextColor();
            }

            cout << "\n";
        }
    }
}
void GameMenu(int selectedOption)
{
    system("cls"); // Clear the console screen
    cout << "\n\n\n\n\n";
    for (int i = 0; i < 4; ++i) {
        if (i == selectedOption) {
            setTextColor(FOREGROUND_RED | BACKGROUND_INTENSITY); // White rectangle background
        }

        // cout << "               "; // Some space before the text

        if (i != selectedOption) {
            setTextColor(FOREGROUND_BLUE);

        }

        switch (i) {
        case 0:
            cout << "*********Manual*********\n";
            break;
        case 1:
            cout << "********AutoMatic********\n";
            break;
        case 2:
            cout << "*********Resume**********\n";
            break;
        case 3:
            cout << "**********Back***********\n";
            break;

        }

        if (i == selectedOption) {
            setTextColor(FOREGROUND_GREEN | BACKGROUND_INTENSITY); // White rectangle background
        }

        //  cout << "               "; // Some space after the text

        if (i == selectedOption) {
            resetTextColor();
        }

        cout << "\n";
    }
}
