#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
    private:
    Node *START;

    public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        //step 1: Allocate memory for new node
        Node *newNode = new Node();

        //step 2: Assign value to the data field
        newNode->noMhs = nim;

        //step 3: Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim<= START->noMhs);
        {
            if (START != NULL || nim <= START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //Step 4: newNode.next = START
            newNode->next = START;

            //STEP 5: START.prev = newNode (IF START exist)
            if (START != NULL)
                START->prev = newNode;

            //step 6: newNode.prev = NULL
            newNode->prev = NULL;

            //step 7: START = newNode
            START = newNode;
            return;
        }

        //insert in between node
        //step 8: locate position for insertion 
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        //step 9: Insert between current and current->next
        newNode->next = current->next; //step 9a: newNode.next = current.next
        newNode->prev = current;       //step 9b: newNode.prev = current

        //insert last node
        if(current->next != NULL)
            current->next->prev = newNode; //step 9c: current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        //step 1:Traverse the list to find the node 
        while(current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        //step 2: if node is at the beginning 
        if (current == START)
        {
            START = current->next; //step 2a: START=START.next
            if (START != NULL)
                START->prev = NULL; //step 2b : START.prev = NULL
        }
        else
        {
           //step 3: link previous node to next of current
           current->prev->next = current->next;

           //step 4: if current is not the last node
           if(current->next != NULL)
               current->next->prev = current->prev;
       }

       //step 5: delete the node
       delete current;
       cout << "Record with roll number " << rollNo << " deleted" << endl;
   }

   void traverse()
   {
       if (START == NULL)
       {
        cout << "\nList is empty" << endl;
        return;
       }

       //step 1: mark first node as current node
       Node *currentNode = START;
       //step 2: Repeat until currentNode == NULL
       cout << "\nRecords in ascending order of roll number are:\n";
       int i = 0;
       while (currentNode != NULL)
       {
        cout << 1 + 1 << ". " << currentNode->noMhs << " " << endl;
        //step 3: move to the next node 
        currentNode = currentNode->next;
        i++;
       }
   }

}; 


