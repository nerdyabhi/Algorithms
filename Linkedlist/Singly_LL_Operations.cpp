#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {

        this->next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *head = NULL;

int search(int n)
{
    node *p = head;
    int index = 1;

    while (p != NULL)
    {
        if (p->data == n)
            return index;
        index++;
        p = p->next;
    }

    return -1;
}

void print()
{

    if (head == NULL)
    {
        cout << "Please create a linked list first : " << endl;
        return;
    }
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << "  --> ";
        p = p->next;
    }
    cout << " NULL\n";
}

void create(int n)
{
    int data;
    node *p = head, *temp;

    if (n == 0)
    {
        cout << "Please Enter positive numbers only !! ";
        return;
    }

    cout << "Enter the data for element 1 : ";
    cin >> data;

    head = new node(data);
    p = head;

    for (int i = 2; i <= n; i++)
    {
        cout << "Please enter value for element : " << i << " : ";
        cin >> data;

        temp = new node(data);
        // temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
}

void insert_beg(int n)
{
    node *p = head;
    node *temp = new node(n);
    temp->next = p;
    head = temp;
}

void insert_end(int n)
{
    node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    node *temp = new node(n);
    p->next = temp;
}

int get_size()
{
    node *p = head;
    int size = 0;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }

    return size;
}

void insert_pos(int pos, int data)
{
    node *p = head;
    int size = get_size();
    if (pos > size || pos < 0)
    {
        cout << endl;
        cout << endl;
        cout << "Invalid position , Please enter position between 0 -" << size << "only !" << endl;

        cout << endl
             << endl;
        return;
    }

    if (pos == 1)
    {
        insert_beg(data);
        return;
    }

    if (pos == size)
    {
        insert_end(data);
        return;
    }

    while (pos != 2)
    {
        p = p->next;
        pos--;
    }

    node *temp = new node;
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
}

void delete_beg()
{
    node *p = head;

    if (head == NULL)
    {
        cout << "Please create a linkedlist first ";
        return;
    }

    int item = head->data;
    head = head->next;
    cout << "Successfully deleted : " << item << endl
         << endl;

    delete p;
}

void delete_end()
{
    node *p = head;
    if (head == NULL)
    {
        cout << "Please create a linkedlist first : ";
        return;
    }
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    int item = p->next->data;

    cout << "Successfully deleted : " << item << endl;

    p->next = NULL;
}

void delete_pos(int index)
{
    node *p = head;
    int pos = 1;
    node *prev;

    if (index == 1)
    {
        delete_beg();
        return;
    }
    while (pos != index)
    {
        prev = p;
        p = p->next;
        pos++;
    }
    cout << "Successfully Deleted : " << p->data << endl;
    prev->next = p->next;
}

void delete_num(int n)
{
    node *p = head;
    int index = search(n);

    if (index == -1)
    {
        cout << "Element not found  ! , Please enter Valid number " << endl;
        return;
    }

    delete_pos(index);
}

void reverse()
{
   node *old = NULL , *p = head , *next_node;
    

    while (p!=NULL)
    {
    next_node = p->next;
       p->next = old;
       old = p;
       p = next_node;
    }

    head = old;


}

int main()
{

    int choice, n, pos;

    while (true)
    {
        cout << "\n------------------\tLinked-List Menu :\t------------------------\n";
        cout << "\n1.Create a linked list\n2.Insert at beginning\n3.Insert at End\n4.Insert at Position\n5.Delete at beginning \n6.Delete last element \n7.Delete an Element \n8.Search an element\n 9. Reverse the linked list \n10.Get size of LinkedList \n11.Display\nYour choice :  ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter the size: ";
            cin >> n;
            create(n);
            break;

        case 2:
            cout << "Enter the data for the node : ";
            cin >> n;
            insert_beg(n);
            break;

        case 3:
            cout << "Enter the data for the node : ";
            cin >> n;
            insert_end(n);
            break;

        case 4:
            cout << "Enter the position for the element : ";
            cin >> pos;
            cout << "Enter the data for the node : ";
            cin >> n;
            insert_pos(pos, n);

        case 5:
            delete_beg();
            break;
        case 6:
            delete_end();
            break;

        case 7:
            cout << "Enter the number you want to delete : ";
            cin >> n;
            delete_num(n);
            break;

        case 8:
            cout << "Enter the element you want to search : ";
            cin >> n;
            pos = search(n);
            pos == -1 ? cout << "Element not found" : cout << "Element found at index :  " << pos << endl;
            break;

            case 9:
            reverse();
            break;

        case 10:
        cout<<"Size of linkedlist is : " << get_size();
        break;

        case 11:
            print();
            break;

        default:
            break;
        }
    }

    return 0;
}