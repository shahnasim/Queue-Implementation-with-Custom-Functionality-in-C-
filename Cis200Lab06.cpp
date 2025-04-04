#include<iostream>
#include<cassert>
using namespace std;

class arrayQueueType
{
public:

    arrayQueueType(int = 100);
    bool isEmpty();
    bool isFull();
    void addQueue(int);
    void deleteQueue();
    int front();
    int rear();
    void clearQueue();
    void moveNthFront(int c);
    void print();
private:
    int maxSize, length, queueFront, queueRear, * queue;
};

arrayQueueType::arrayQueueType(int size) //function for size
{
    if (size <= 0)
        maxSize = 100;
    else
        maxSize = size;

    length = 0;
    queue = new int[maxSize];
    queueFront = 0;
    queueRear = maxSize - 1;

}


bool arrayQueueType::isEmpty() //empty function
{
    return (length == 0);
}

bool arrayQueueType::isFull() //isfull function
{
    return (length == maxSize);
}

void arrayQueueType::deleteQueue()
{
    if (isEmpty())
        cout << "Empty Queue" << endl;
    else
    {
        queueFront = (queueFront + 1) % maxSize;
        length--;
    }
}
void arrayQueueType::addQueue(int item) //add queue function
{
    if (isFull())
        cout << "Full Queue" << endl;
    else
    {
        queueRear = (queueRear + 1) % maxSize;
        queue[queueRear] = item;
        length++;
    }

}
void arrayQueueType::print() //print the elements
{
    arrayQueueType qq;
    while (!isEmpty())
    {
        cout << front() << " ";
        qq.addQueue(front());
        deleteQueue();

    }
    while (!(qq.isEmpty()))
    {

        addQueue(qq.front());
        qq.deleteQueue();

    }
    cout << endl;
}

int arrayQueueType::front()
{
    assert(!isEmpty());
    return queue[queueFront];
}

int arrayQueueType::rear()
{
    assert(!isEmpty());
    return queue[queueRear];
}

void arrayQueueType::clearQueue()
{
    length = 0;
    queueFront = 0;
    queueRear = maxSize - 1;
}

void moveNthFront(int n, arrayQueueType& q) //move nth front function
{
    arrayQueueType qq;
    int temp;
    if (q.isEmpty())
        return;
    else
    {
        int i = 1;
        while (!q.isEmpty())
        {
            if (i == n)
            {
                temp = q.front();
                q.deleteQueue();
            }
            else
            {
                qq.addQueue(q.front());
                q.deleteQueue();
            }
            i++;
        }

        q.addQueue(temp);
        while (!qq.isEmpty())
        {
            q.addQueue(qq.front());
            qq.deleteQueue();
        }
    }
}
void arrayQueueType::moveNthFront(int n)
{
    int temp;
    int x = length;
    temp = queue[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        queueRear = (queueRear + 1) % maxSize;
        queue[queueRear] = queue[i];
        length++;
    }
    x = length - x;
    for (int i = 0; i < n; i++)
    {
        queueFront = (queueFront + 1) % maxSize;
        length--;
    }
    for (int i = 0; i < x; i++)
    {
        queueFront = (queueFront - 1) % maxSize;
        queue[queueFront] = queue[queueRear];
        length++;
        queueRear = (queueRear - 1) % maxSize;
        length--;
    }

    queueFront = (queueFront - 1) % maxSize;
    queue[queueFront] = temp;
    length++;
}
int main()
{
    int n, a;
    cout << "Please enter the number of elements :";
    cin >> n;

    arrayQueueType q(n);

    for (int i = 1; i <= n; i++)
    {
        q.addQueue(i);
    }
    cout << "print the elements: " << endl;
    q.print();
    cout << "And enter the position of move the element : ";
    cin >> a;
    moveNthFront(a, q); //calling move nth front function
    //q.moveNthFront(a);
    q.print();


    return 0;
}
