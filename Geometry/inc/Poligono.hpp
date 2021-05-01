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

    // Calculates the determinant given two Puntos.
    numType edgeDet(Punto<numType> *lp, Punto<numType> *rp) {
        return (rp->getX() - lp->getX()) * (rp->getY() + lp->getY());
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

    Node* getHead() const { return head;}
    int getSize() const { return size;}

    // Public addPunto method. Adds a Punto to the end of the list.
    void addPunto(Punto<numType> *p) {
        addPunto(p, head->prev);
        size++;
    }

    // Calculates the orientation determinant for the PoligonoList.
    numType orientationDet() {
        // Calculate for head edge first.
        numType result = edgeDet(head->p, head->next->p);
        Node* curr_node=head->next;

        // Calculate for the rest of the edges.
        while (curr_node != head) {
            result += edgeDet(curr_node->p, curr_node->next->p);
            curr_node = curr_node->next;
        }

        return result;
    }
};


template <class numType>
class Poligono {
    PoligonoList<numType> *poligono_list;
    numType orientationDet;

public:
    // Constructor
    Poligono(Punto<numType> *lp, Punto<numType> *mp, Punto<numType> *rp) : poligono_list(nullptr) {
        poligono_list = new PoligonoList<numType>(lp, mp, rp);
        orientationDet = poligono_list->orientationDet();
    }

    // Destructor
    ~Poligono() {
        delete poligono_list;
        free(this);
    }

    void addPunto(Punto<numType> *p) {
        poligono_list->addPunto(p);
        orientationDet = poligono_list->orientationDet();
    }

    // Getter
    PoligonoList<numType> getList() { return poligono_list; }

    // Boolean if Poligono is clockwise or counterclockwise.
    bool isCCW() { return (orientationDet < 0) ? true : false; }

    // Provides the area of the Poligono.
    numType area() { return abs(orientationDet)*0.5; }

};


#endif //POLIGONO_HPP
