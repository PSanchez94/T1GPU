/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#ifndef POLIGONO_HPP
#define POLIGONO_HPP

#include "Punto.hpp"


template <class numType>
class PoligonoList {

    struct Node {
        Punto<numType> *p;
        Node *next;
        Node *prev;

        explicit Node(Punto<numType> *p) : p(p), next(nullptr), prev(nullptr) { }

        // cout operator
        friend std::ostream &operator<<( std::ostream &output, const Node &n ) {
            output << "Node: " << *n.p
            << "Next node: " << *n.next->p
            << "Prev node: " << *n.prev->p;
            return output;
        }
    };

    Node *head;
    int size;
    // Node* tail; // Do I need a tail?

    void addPunto(Punto<numType> *p, Node *n) {
        Node *new_node = new Node(p);

        new_node->next = n->next;
        new_node->next->prev = new_node;

        new_node->prev = n;
        n->next = new_node;
    }

public:
    PoligonoList(Punto<numType> *lp, Punto<numType> *mp, Punto<numType> *rp) {
        head = new Node(lp);
        head->next = new Node(mp);
        head->next->prev = head;
        head->next->next = head;
        head->prev = head->next;

        addPunto(rp, head->prev);

        size = 3;
    }

    void addPunto(Punto<numType> *p) {
        addPunto(p, head->prev);
        size++;
    }

    Node* getHead() const { return head;}
    int getSize() const { return size;}

    /*
    void addPoint(Point<numType> *p) {
        new Node(InitData)
        newNode.next  := node.next
    }


    insert(Node node, Node newNode)
    newNode.next  := node.next
    newNode.prev  := node
    node.next.prev  := newNode
    node.next       := newNod
    /**/

    /*
    void empty(void) {
        head->prev->next = nullptr; // Break forward-circularity.
        head->delete(); // Call recursive deleter.
    }

    void delete(void) {
        if(next != nullptr) next->delete();
        delete this;
    }
    /**/

};
/**/
#endif //POLIGONO_HPP
