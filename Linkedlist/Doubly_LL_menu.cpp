#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
};

node *head = NULL;

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
    int item;
    head = new node(item);
    node *p = head, *temp;

    if (n <= 0)
    {
        cout << "Please Enter Number >= to 1 only " << endl;
        return;
    }

    cout << "Enter the data for element 1 : ";
    cin >> item;
    p->data = item;

    for (int i = 2; i <= n; i++)
    {
        cout << "Enter the data for element " << i << " : ";
        cin >> item;
        temp = new node();
        temp->data = item;
        p->next = temp;
        temp->prev = p;
        p = temp;
    }

    p->next = NULL;
}

void insert_beg(int data)
{

    if (head == NULL)
    {
        head = new node(data);
    }

    node *p = head;

    node *temp = new node(data);
    temp->next = p;
    p->prev = temp;
    temp->prev = NULL;

    head = temp;
}

void insert_end(int data)
{
    node *p = head, *temp = new node(data);

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = temp;
    temp->prev = p;
}

int get_size()
{
    node *p = head;
    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }

    return length;
}

void insert_pos(int pos, int data)
{
    node *p = head;
    int size = get_size();

    if (pos == 1)
    {
        insert_beg(data);
        return;
    }

    while (pos != 2)
    {
        p = p->next;
        pos--;
    }

    node *temp = new node(data);
    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;
}

void delete_beg()
{
    node *p = head->next;
    cout << "Successfully Deleted:  " << head->data << endl;
    head = p;
    p->prev = NULL;
}

void delete_end()
{
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    node *old = p->prev;
    old->next = NULL;
    cout << "successfully deleted :" << p->data << endl;
}

int search(int n)
{
    cout<<"In search" <<endl;
    node *p = head;
    int index = 1;
    while (p != NULL)
    {
        if (p->data == n)
            return index;

            p = p->next;
        index++;
    }

    return -1;
}

void delete_num(int n)
{

    int index = search(n);
    if (index == -1)
    {
        cout << "Element not found to delete : " << endl;
        return;
    }

    cout << "ELement found at index : " << index << endl;

    if (index == get_size())
    {
        delete_end();
        return;
    }

    if (index == 1)
    {
        delete_beg();
        return;
    }

    node *p = head, *old;

    for (int i = 1; i < index; i++)
    {
        p = p->next;
    }

    old = p->prev;
    p->next->prev = old;
    old->next = p->next;
}


void reverse()
{
    node*p = head , *old = NULL , *next_node;
     while(p!=NULL)
      {
          next_node = p ->next;
          p ->next = old;
          p ->prev = next_node;
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