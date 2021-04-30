/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#ifndef POLIGONO_HPP
#define POLIGONO_HPP

#include "Punto.hpp"


template <class numType>
class PoligonoList {
    int size;

    struct Node {
        Punto<numType> *p;
        Node *next;
        Node *prev;

        explicit Node(Punto<numType> *p) : p(p), next(nullptr), prev(nullptr) { }

        // Destructor, deletes the next node recursively until it finds a nullptr.
        ~Node() {
            if (next != nullptr) { delete next; }
            free(this);
        }

        // cout operator.
        friend std::ostream &operator<<( std::ostream &output, const Node &n ) {
            output << "Node: " << *n.p
            << "Next node: " << *n.next->p
            << "Prev node: " << *n.prev->p;
            return output;
        }
    };

    Node *head;

    // Adds a Punto next of input node n.
    void addPunto(Punto<numType> *p, Node *n) {
        Node *new_node = new Node(p);

        new_node->next = n->next;
        new_node->next->prev = new_node;

        new_node->prev = n;
        n->next = new_node;
    }

    /*
    // Removes a node. If the node is the head, it declares its next node as the head.
    void removePunto(Node *n) {
        if (size>3) {
            if (n==head) {
                head = n->next;
            }
            n->prev->next = n->next;
            n->next->prev = n->prev;
            free(n);
        }
    }
    /**/

public:
    // Constructor. A Poligono should only be initialized with 3 Puntos.
    PoligonoList(Punto<numType> *lp, Punto<numType> *mp, Punto<numType> *rp) {
        head = new Node(lp);
        head->next = new Node(mp);
        head->next->prev = head;
        head->next->next = head;
        head->prev = head->next;

        addPunto(rp, head->prev);
        size = 3;
    }

    // Destructor, breaks circularity and then calls head's destructor.
    ~PoligonoList() {
        head->prev->next = nullptr;
        delete head;
        free(this);
    }

    // Public addPunto method. Adds a Punto to the end of the list.
    void addPunto(Punto<numType> *p) {
        addPunto(p, head->prev);
        size++;
    }

    Node* getHead() const { return head;}
    int getSize() const { return size;}
};


#endif //POLIGONO_HPP
