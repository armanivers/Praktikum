#define queueSize 5

// const int queueSize = 2; funktioniert nicht!

int queue[queueSize];

int size = queueSize;
// Zeigt auf das erste Element
int front = -1;
// Zeigt auf das letzte Element
int rear = -1;

void enqueue(int i)
{
    if (isFull())
    {
        //printf("\n Queue is full!! \n");
    }
    else 
    {
    if (front == -1) front = 0;
    rear = (rear + 1) % queueSize;
    queue[rear] = i;
    //printf("\n Inserted -> %d", element);
  }
}

int dequeue()
{
    int element;
    if (isEmpty()) 
    {
    //printf("\n Queue is empty !! \n");
    return (-1);
    } else 
    {
    element = queue[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else 
    {
      front = (front + 1) % queueSize;
    }
    //printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

int isFull()
{
    if((front == rear + 1) || (front == 0 && rear == queueSize - 1)) return 1;
    return 0;
}
int isEmpty()
{
    if (front == -1) return 1;
    return 0;
}