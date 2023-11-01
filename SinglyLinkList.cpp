#include <iostream>
using namespace std;

class Node{
    public:
        int data=0;
        Node * next = NULL;
};

class LinkList{
    public:
        
        LinkList(){}
        
        Node * createNode(int value);
        Node * insertAtBegg(Node * head, int value);
        Node * insertAtKthFromEnd(Node * head, int value, int k);
        Node * insertAtEnd(Node * head, int value);
        void searchInList(Node* head, int k);
        void deleteEnd(Node * head);
        Node * deleteBegg(Node * head);
        Node * deleteKthPositionFromStart(Node* head, int k);
        Node * reversLL(Node * head);
        
        void printList(Node * head);
        
        static int counter;
};

int LinkList::counter = 0;

Node * LinkList::createNode(int value){
    Node * newNode = new Node();
    
    LinkList::counter++;
    
    newNode->data = value;
    newNode->next = NULL;
    
    return newNode;
}

Node * LinkList::insertAtBegg(Node * head, int value){

    Node * newNode = createNode(value);
    
    if(head == NULL){
        head = newNode;
    } else {
        Node * firstNode = head;
        newNode->next = firstNode;
        head = newNode;
    }
    
    return head; 
}

Node * LinkList::insertAtEnd(Node * head, int value){

    Node * newNode = createNode(value);
    
    if(head == NULL){
        head = newNode;
    } else {
        Node * firstNode = head;
        
        while(firstNode->next != NULL){
            firstNode = firstNode->next;
        }
        
        firstNode->next = newNode;
    }
    return head; 
}

Node * LinkList::insertAtKthFromEnd(Node * head, int value, int k){
    
    int size = LinkList::counter;

    Node * newNode = createNode(value);
    
    if(head == NULL){
        head = newNode;
    } else {
        Node * firstNode = head;
        
        while(firstNode->next != NULL){
            firstNode = firstNode->next;
            if(((size - k) + 1) == k){
                newNode->next = firstNode->next;
                firstNode->next = newNode;
            }
            break;
        }
    }
    return head; 
}

void LinkList::searchInList(Node* head, int value){
    
    Node * tempNode = head;
    int count = 1;
    while(tempNode->next != NULL){
        if(tempNode->data == value){
            cout << value <<" is found at " << count << " position." << endl;
            return;
        } else {
            tempNode = tempNode->next;
            count++;
        }
    }
}

void LinkList::deleteEnd(Node* head)
{
    if(head == NULL){
        return;
    }
    
    if(head->next == NULL){
        delete head;
        free(head);
    }
    
    Node * secondLast = head;
    
    while(secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }
    
    delete (secondLast->next);
    secondLast->next = NULL;
}

Node * LinkList::deleteBegg(Node* head)
{
    Node * tempNode = head;
    
    if(head == NULL){
        return head;
    } else if(head->next == NULL){
        delete head;
    } else {
        head = tempNode->next;
    }
    return head;
}

Node * LinkList::deleteKthPositionFromStart(Node* head, int k)
{
    int size = LinkList::counter;
    Node * tempNode = head;
    Node * prevNode = NULL;
    
    while(--k){
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    prevNode->next = tempNode->next;
    
    delete tempNode;
    
    return head;
}

Node * LinkList::reversLL(Node * head)
{
    if (head == NULL) {
        return head;
    }
    
    Node * current = head;
    
    Node * next = NULL, *prev = NULL;
    
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
        head = prev;
    
    return head;
}

void LinkList::printList(Node * head){
    
    Node * node = head;
    
    if(node != NULL){
        while(node != NULL){
            cout << node->data;
            node = node->next;
            cout << " ---> ";
        }
        cout << endl;
    } else {
        cout << "List is empty";
    }
}

int main()
{
    LinkList *l1 = new LinkList();
    
    Node * head = NULL;
    
    head = l1->insertAtEnd(head,1);
    head = l1->insertAtEnd(head,2);
    head = l1->insertAtEnd(head,3);
    head = l1->insertAtBegg(head,4);
    head = l1->insertAtBegg(head,5);
    head = l1->insertAtKthFromEnd(head,6,3);
    
    l1->printList(head);
    
    l1->searchInList(head,6);
    
    l1->deleteEnd(head);
    cout << "List after deletion of last node: " << endl; 
    l1->printList(head);
    
    head = l1->deleteBegg(head);
    cout << "List after deletion of first node: " << endl; 
    l1->printList(head);

    head = l1->deleteKthPositionFromStart(head,2);
    cout << "List after deletion of kth node: " << endl; 
    l1->printList(head);
    
    head = l1->reversLL(head);
    cout << "Reverse link list: " << endl; 
    l1->printList(head);
    
    return 0;
}
