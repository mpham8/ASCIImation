/*
  Michael Pham, Brandon Xu
  Fall 2022
*/

#include <stdexcept>
#include "linkedList.h"

using std::runtime_error;
using namespace std;

// This file defines the methods for two classes: LinkedListNode and LinkedList.

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

/*
 * Creates a new Linked List.
 */
template <typename T> LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

/*
 * Cleans up the resources used by a Linked List.
 */
template <typename T> LinkedList<T>::~LinkedList() {
    LinkedListNode<T>* temp = this->head;
    if (this->size>0){
        while (temp -> next != nullptr){
                LinkedListNode<T>* next = temp->next;
                delete temp;
                temp =  next;
        }
        }
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
}

/*
 * Checks invariants. Makes sure that both head and tail point to nullptr if size i
 * 0. Also makes sure that the size reflects the actual size of the list.
 */
template <typename T> void LinkedList<T>::checkInvariants() {
    if (this->size == 0 & (this->tail != nullptr or this->head != nullptr)){
        throw runtime_error("List size 0 must have head and tail pointing at nullptr");
    } if(this->size >0){
        int check_size_accum = 0;
        LinkedListNode<T>* current = this->head;
        while (current != nullptr){
                check_size_accum++;
                current = current -> next;
        }
        if (this->size != check_size_accum){
            throw runtime_error("incorrect size");
        }
    }
}

/*
 * Obtains size of the linked list.
 * @return the size of the linked list.
 */
template <typename T> int LinkedList<T>::getSize() {
    return this->size;
}

/*
 * Checks if the linked list is empty. 
 * @return bool value True if empty. Returns bool value False if not.
 */
template <typename T> bool LinkedList<T>::isEmpty() {
    if(this->size == 0){
        return true;
    } else {
        return false;
    }
}

/*
 * Obtains the value of the first element in the linked list. Will throw error if
 * the size of the list is 0.
 * @return The value of the first element in the list.
 */
template <typename T> T LinkedList<T>::getFirst() {
    if (this->size==0){
            throw runtime_error("empty list");
    }
    return this->head->value;
    // throw runtime_error("Not yet implemented: LinkedList::getFirst");
}

/*
 * Obtains the value of the last element in the linked list. Will throw error if
 * the size of the list is 0.
 * @return The value of the last element in the list.
 */
template <typename T> T LinkedList<T>::getLast() {
    if (this->size==0){
            throw runtime_error("empty list");
    }
            return this->tail->value;
        // throw runtime_error("Not yet implemented: LinkedList::getLast");
}

/*
 * Obtain the value of the element represented by the index. Will throw error if
 * the size of list is 0.
 * @param index The index of which member of the linked list the user wants.
 * @return The value of the element of the list the user wants
 */
template <typename T> T LinkedList<T>::get(int index) {
    if (this->size==0){
            throw runtime_error("empty list");
    }
    if (index>this->size-1 || index<0){
        throw runtime_error("out of index");
    }
    LinkedListNode<T>* current = this->head;
    for (int i = 0; i < index; i++){ //POTENIAL ERROR (< or this->index)
        current = current -> next;
    }
    return current->value;
    // throw runtime_error("Not yet implemented: LinkedList::get");
}

/*
 * Inserts an element to the front of the list.
 * @param value The value which the user wants stored in the first element of the
 *              list
 */
template <typename T> void LinkedList<T>::insertFirst(T value) {


    if (this->size == 0){
    LinkedListNode<T>* first_node = new LinkedListNode<T>(value, nullptr);

    this->tail = first_node;
    this->head = first_node;

    
    }

    if (this->size > 0){
    LinkedListNode<T>* first_node = new LinkedListNode<T>(value, this->head);
    this->head = first_node;
    }
    
    
    this->size++;
}

/*
 * Inserts an element to the back of the list.
 * @param value The value which the user wants stored in the last element of the 
 *              list
 */
template <typename T> void LinkedList<T>::insertLast(T value) {
    if (this->size == 0){
    LinkedListNode<T>* last_node = new LinkedListNode<T>(value, nullptr);

    this->tail = last_node;
    this->head = last_node;
    this->size++;

    
    } else {
    
    LinkedListNode<T>* last_node = new LinkedListNode<T>(value, nullptr);
    this->tail->next = last_node;
    this->tail = last_node;
    this->size++;
    }

}


/*
 * Deletes the first element of the list.
 * @return the value of the first element of the list.
 */
template <typename T> T LinkedList<T>::removeFirst() {
    if(this->size == 0){
        throw runtime_error("List of size 0");

    } if (this->size == 1){ //CHECK
        this->size --;
        T value = this->head->value;
        delete this->head; //HOW TO DELETE NODE
        
        this->head = nullptr;
        this->tail = nullptr;

        return value;
    } else {
        this->size --;
        T value = this->head->value;
        LinkedListNode<T>* temp = this->head->next;
        delete this->head;
        this->head=temp; //HOW TO DELETE NODE

        return value;

    }
}


/*
 * Deletes the last element of the list.
 * @return the value of the last element of the list.
 */
template <typename T> T LinkedList<T>::removeLast() {

    if(this->size == 0){
        throw runtime_error("List of size 0");

    } if (this->size == 1){ //CHECK
        T value = this->tail->value;
        delete this->tail; //HOW TO DELETE NODE
        
        this->head = nullptr;
        this->tail = nullptr;

        this->size --;
        return value;
    }
     else { //CHECK
        
        T value = this->tail->value;
        
        LinkedListNode<T>* temp = this->head;
        for(int i = 0; i <(this->size - 2); i++){
            temp = this->head->next;
        }
        
        this->tail=temp;
        delete this->tail->next;
        this->tail->next = nullptr;
        this->size --;
        return value;

    }
}

/*
 * Reverses list.
 * @return nothing.
 */
template <typename T> void LinkedList<T>::reverseIt(){
    

    LinkedListNode<T>* current = this->head;
    LinkedListNode<T>* next;
    LinkedListNode<T>* previous;
    
    for (int i = 0; i < this->size; i++){
        next = current->next;
        if (i==0){
            this->tail = current;
        }

        current->next = previous;
            
        previous = current;
        current = next;
        }
        
    this->head = previous;
}
