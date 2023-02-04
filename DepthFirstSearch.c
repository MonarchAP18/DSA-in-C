#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue
{
    int object[SIZE];
    int frontside;
    int rearend;
};

struct queue *createQueue();
void enqueue(struct queue *c, int);
int dequeue(struct queue *c);
void display(struct queue *c);
int isEmpty(struct queue *c);
void printQueue(struct queue *c);
struct node
{
    int vertex;
    struct node *next;
};

struct node *createNode(int);
struct Graph
{
    int numVertices;
    struct node **adjcentLists;
    int *visited;
};

void bfs(struct Graph *graph, int startVertex)
{
    struct queue *c = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(c, startVertex);
    while (!isEmpty(c))
    {
        printQueue(c);
        int currentVertex = dequeue(c);
        printf("DONE VISITING %d\n", currentVertex);
        struct node *temp = graph->adjcentLists[currentVertex];
        while (temp)
        {
            int adjcentVertex = temp->vertex;
            if (graph->visited[adjcentVertex] == 0)
            {
                graph->visited[adjcentVertex] = 1;
                enqueue(c, adjcentVertex);
            }
            temp = temp->next;
        }
    }
}

struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjcentLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjcentLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}



struct queue *createQueue()
{
    struct queue *c = malloc(sizeof(struct queue));
    c->frontside = -1;
    c->rearend = -1;
    return c;
}

void addEdge(struct Graph *graph, int source, int destination)
{
    struct node *newNode = createNode(destination);
    newNode->next = graph->adjcentLists[source];
    graph->adjcentLists[source] = newNode;
    newNode = createNode(source);
    newNode->next = graph->adjcentLists[destination];
    graph->adjcentLists[destination] = newNode;
}

int dequeue(struct queue *c)
{
    int item;
    if (isEmpty(c))
    {
        printf("EMPTY QUEUE");
        item = -1;
    }
    else
    {
        item = c->object[c->frontside];
        c->frontside++;
        if (c->frontside > c->rearend)
        {
            printf("CLEARING QUEUE ");
            printf("");
            c->frontside = c->rearend = -1;
        }
    }
    return item;
}

int isEmpty(struct queue *c)
{
    if (c->rearend == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *c, int value)
{
    if (c->rearend == SIZE - 1)
        printf("\n QUEUE IS FULL!");
    else
    {
        if (c->frontside == -1)
            c->frontside = 0;
        c->rearend++;
        c->object[c->rearend] = value;
    }
}



void printQueue(struct queue *c)
{
    int i = c->frontside;
    if (isEmpty(c))
    {
        printf("EMPTY QUEUE");
    }
    else
    {
        printf("\n Queue contains \n");
        for (i = c->frontside; i < c->rearend + 1; i++)
        {
            printf("%d ", c->object[i]);
        }
    }
}

int main()
{
    struct Graph *graph = createGraph(6);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 2, 5);
    addEdge(graph, 6, 5);
    bfs(graph, 0);
    return 0;
}