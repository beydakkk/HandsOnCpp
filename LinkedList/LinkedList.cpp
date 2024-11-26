#include <iostream>
#include <stdio.h> 
using namespace std;

class Node{
public:
	int data;
	Node* next;

	// Constructor
	Node(int value){
	   	data = value;
	   	next = nullptr;
	}	  		 
};

class LinkedList{
private:
		Node* head;
public:
	// Constructor
	LinkedList(){
			head = nullptr;
	}
	   
    void insertAtBeginning(int value){
  		Node* newNode = new Node(value);	
  		newNode->next = head;
  		head = newNode;
    }
	   
	void insertAtEnd(int value){
		Node* newNode = new Node(value);
		if(head == nullptr)
		    head = newNode;
		else{
			Node* tmp = head;
			while(tmp->next != nullptr)
    			tmp = tmp->next;
		        tmp->next = newNode;   
		    }   
    }
	   
	void insertFromMiddle(int value, int index){
		Node* newNode = new Node (value);
	   		
		if(index == 0){
	 	    newNode->next = head;
		    head = newNode;
		    return;
		}
			
   		Node* tmp = head;
   		int counter = 0;
   		while(tmp->next != nullptr && counter < index-1){
			tmp = tmp->next;
			counter++;
		}
		if(counter != index-1){
			cout << "Invalid index! Couldn't insert value " << value << endl;
			delete newNode;
			return;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	   
    int searchByValue(int value) {
    	Node* tmp = head;
	    int index = 0;
	
	    while (tmp != nullptr) { 
	        if (tmp->data == value) {
	            cout << "Value found at index " << index << "." << endl;
	            return index;
            }
        tmp = tmp->next;
        index++;
	    }
	    cout << "Value not found in the list." << endl;
	    return -1;
	}

	void deleteByValue(int value){ 	
		int index = searchByValue(value);
		if(index == -1){
            cout << "Value not found in the list!" << endl;
            return;
		}
		if(index == 0){
            Node* tmp = head;
            head = head->next;
            delete tmp;
            cout << "Value " << value << " deleted from the list." << endl;
            return;
		}
		   
		Node* tmp = head;
        for(int i = 0; i < index-1; i++){
		    tmp = tmp->next;		   
		}
		Node* nodeToDelete = tmp->next;
		tmp->next = nodeToDelete->next;
		delete nodeToDelete;
		cout << "Value " << value << " deleted from the list." << endl; 
	}
  		
    void display(){
		if(head == nullptr){
		    cout << "The list is empty." << endl;
			return;	   
	    }
	    Node* tmp = head;
		while(tmp != nullptr){
		    cout << tmp->data << "->";
			tmp = tmp->next;				   
		}	
		cout << "nullptr" << endl;
	}
       
    void reverse(){
        Node* previous = nullptr;
        Node* current = head;
        Node* next = nullptr;
           
        while(current != nullptr){
			next = current->next;
            current->next = previous;
            previous = current;
            current = next;
		}
		head = previous;
		cout << "List reversed." << endl;
	}
       
    int calculateLength(){
	    Node* tmp = head;
	    int length = 0;
		while(tmp != nullptr){
	        length++;
		    tmp = tmp->next;	 
		}
		return length ; 
    }
       
    // Destructor to free memory
    ~LinkedList(){
	    Node* tmp;
		while(head != nullptr){
		    tmp = head;
			head = head->next;
			delete tmp;		
		}		 
    }
};
	  

int main(){
    
    LinkedList list;
    
    list.display();

    list.insertAtBeginning(10);
    list.display();

    list.insertAtEnd(20);
    list.display();

    list.insertAtEnd(30);
    list.display();

    list.insertFromMiddle(15, 1);
    list.display();

    list.insertFromMiddle(40, 30); // occurs "Invalid index" error.
    list.display();
    
    
    return 0;
}
