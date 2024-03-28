#include <iostream>
using namespace std;

class heap
{
public:
    int size = 0;
    int *arr; // array pointer , later we will allocate dynamic memory to it  :

    heap(int n) // constructor for heap class :)
    {
        size = 0;
        arr = new int[n + 1];
        arr[0] = -1;
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int num)
    {
        size++;
        int index = size;
        arr[index] = num;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] < arr[parent])
                break;

            else
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
        }
    }

    void deletion()
    {
        // exception case :
        if (size == 1)
        {
            size--;
            return;
        }

        if (size <= 0)
        {
            cout << "heap underflow" << endl;
            return;
        }

        // Note - Only root node can be deleted so deletion :)
        /*
             can be perfomed in two easy peasy steps:
             1- replace root node with last node  and delete last node
             2- place root to it's correct position
        */

        // Replacing root with last element :
        int temp = arr[1];
        arr[1] = arr[size--]; // arr[1] = root , and arr[size]

        // find correct position for root node :
        int index = 1;
        while (index < size)
        {
            int left_index = 2 * index; // find left and right index
            int right_index = 2 * index + 1;
            int largest_index = index;
            // out of left and right child , choose the biggest one and replace it with root
            if (left_index <= size && arr[largest_index] < arr[right_index])
            {
                largest_index = right_index;
            }

            if (right_index <= size && arr[largest_index] < arr[left_index])
            {
                largest_index = left_index;
            }

            if (largest_index == index)
                return;
            else
            {
                swap(arr[index], arr[largest_index]);
                index = largest_index;
            }
        }
        cout << "Successfully Deleted : " << temp << endl; // easy laif
    }
};
int main()
{
    int Heapsize;
    cout << "Enter the size for heap : ";
    cin >> Heapsize;

    heap h(Heapsize);

    while (1)
    {
        int num, choice;
        cout << "1-Insertion\n2-Deletion\n3-Print\n4-Exit\n\tYour Choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element you want to insert : ";
            cin >> num;
            h.insert(num);
            h.print();
            break;
        case 2:
            h.deletion();
            break;

        case 3:
            h.print();
            break;
        case 4:
            exit(1);

        default:
            cout << "error !" << endl;
            break;
        }
    }
}