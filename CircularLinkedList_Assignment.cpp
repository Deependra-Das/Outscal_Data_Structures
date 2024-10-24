#include <iostream>

class Node 
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList 
{
private:
    Node* head_node;

public:
    CircularLinkedList() : head_node(nullptr) {}

    void insertAtEnd(int value) 
    {
        Node* newNode = new Node(value);
        if (!head_node) 
        {
            head_node = newNode;
            newNode->next = head_node;
        }
        else 
        {
            Node* cur_node = head_node;
            while (cur_node->next != head_node)
            {
                cur_node = cur_node->next;
            }
            cur_node->next = newNode;
            newNode->next = head_node;
        }
    }

    void insertAtBeginning(int value) 
    {
        Node* newNode = new Node(value);
        if (!head_node) 
        {
            head_node = newNode;
            newNode->next = head_node;
        }
        else 
        {
            Node* cur_node = head_node;
            while (cur_node->next != head_node)
            {
                cur_node = cur_node->next;
            }
            cur_node->next = newNode;
            newNode->next = head_node;
            head_node = newNode;
        }
    }

    void deleteFromEnd() 
    {
        if (!head_node) return;

        Node* cur_node = head_node;
        if (cur_node->next == head_node)
        {
            delete head_node;
            head_node = nullptr;
            return;
        }

        while (cur_node->next->next != head_node)
        {
            cur_node = cur_node->next;
        }
        delete cur_node->next;
        cur_node->next = head_node;
    }

    void deleteFromBeginning() 
    {
        if (!head_node) return;

        Node* cur_node = head_node;
        if (cur_node->next == head_node)
        {
            delete head_node;
            head_node = nullptr;
            return;
        }

        Node* last = head_node;
        while (last->next != head_node) 
        {
            last = last->next;
        }
        head_node = head_node->next;
        last->next = head_node;
        delete cur_node;
    }

    void traverse() 
    {
        if (!head_node) return;

        Node* cur_node = head_node;
        do 
        {
            std::cout << cur_node->data << " ";
            cur_node = cur_node->next;
        } 
        while (cur_node != head_node);
        std::cout << std::endl;
    }

    void findTheMiddle() 
    {
        if (!head_node) return;

        Node* slow = head_node;
        Node* fast = head_node;

        do 
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != head_node && fast->next != head_node);

        std::cout << "Data on the Middle node: " << slow->data << std::endl;
    }

    void insertAtIndex(int index, int value) 
    {
        if (index == 0) 
        {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* cur_node = head_node;
        for (int i = 0; i < index - 1; i++) 
        {
            cur_node = cur_node->next;
            if (cur_node == head_node)
            {
                std::cout << "Index out of bounds." << std::endl;
                delete newNode;
                return;
            }
        }
        newNode->next = cur_node->next;
        cur_node->next = newNode;
    }

    void deleteFromIndex(int index) 
    {
        if (!head_node || index < 0) return;

        if (index == 0) 
        {
            deleteFromBeginning();
            return;
        }

        Node* cur_node = head_node;
        for (int i = 0; i < index - 1; i++) 
        {
            cur_node = cur_node->next;
            if (cur_node->next == head_node)
            {
                std::cout << "Index out of bounds." << std::endl;
                return;
            }
        }

        Node* toDelete = cur_node->next;
        if (toDelete == head_node) 
        {
            cur_node->next = head_node;
        }
        else 
        {
            cur_node->next = toDelete->next;
        }
        delete toDelete;
    }

    void reverse() 
    {
        if (!head_node) return;

        Node* prev = nullptr, * current = head_node, * next = nullptr;
        Node* tail = head_node;

        do 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head_node);

        head_node->next = prev;
        head_node = prev;
    }

    ~CircularLinkedList() 
    {
        while (head_node) 
        {
            deleteFromBeginning();
        }
    }
};

int main() 
{
    CircularLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.traverse();

    list.insertAtBeginning(0);
    list.traverse();

    list.deleteFromEnd();
    list.traverse();

    list.deleteFromBeginning();
    list.traverse();

    list.insertAtIndex(4, 5);
    list.traverse();

    list.findTheMiddle();

    list.reverse();
    list.traverse();

    return 0;
}
