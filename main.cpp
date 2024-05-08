#include <iostream>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

// Estrutura para um nó
typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);

// Funções para a atividade
void swapPayload(Node*, Node*);
void bubbleSort(Node**);
void optimizedBubbleSort(Node**, int);
void selectionSort(Node**);
void optimizedSelectionSort(Node** head);
// Função auxiliar
Node* createRandomList(int);

int main()
{
    cout << "=====================================================================" << endl;
    cout << "\n";
    Node* node_1 = createRandomList(30000);

    auto timeStart = high_resolution_clock::now();
    bubbleSort(&node_1);
    auto timeStop = high_resolution_clock::now();

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado no bubbleSort: " << timeDuration.count() << " nanosegundos." << endl;

    cout << "\n";

    Node* node_2 = createRandomList(30000);

    timeStart = high_resolution_clock::now();
    optimizedBubbleSort(&node_2, 30000);
    timeStop = high_resolution_clock::now();

    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado no optimizedBubbleSort: " << timeDuration.count() << " nanosegundos." << endl;

    cout << "\n";
    cout << "=====================================================================" << endl;

    cout << "\n";

    Node* node_3 = createRandomList(30000);

    timeStart = high_resolution_clock::now();
    selectionSort(&node_3);
    timeStop = high_resolution_clock::now();

    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado no selectionSort: " << timeDuration.count() << " nanosegundos." << endl;

    cout << "\n";

    Node* node_4 = createRandomList(30000);

    timeStart = high_resolution_clock::now();
    optimizedSelectionSort(&node_4);
    timeStop = high_resolution_clock::now();

    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado no optimizedSelectionSort: " << timeDuration.count() << " nanosegundos." << endl;

    cout << "\n";
    cout << "=====================================================================" << endl;

    return 0;
}

Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));     
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

// Funções da atividade:

void swapPayload(Node* node1, Node* node2) 
{
    int iTemp = node1->iPayload;
    node1->iPayload = node2->iPayload;
    node2->iPayload = iTemp;
}

void bubbleSort(Node** head)
{
    for (Node* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        for (Node* current_2 = *head; current_2->ptrNext != nullptr; current_2 = current_2->ptrNext)
        {
            if (current_2->iPayload > current_2->ptrNext->iPayload)
            {
                swapPayload(current_2, current_2->ptrNext);
            }
        }
    }
}

void optimizedBubbleSort(Node** head, int iLength)
{
    bool bUnordered = false;

    for (int iOuterLoop = iLength-1; iOuterLoop > 0; iOuterLoop--)
    {
        bUnordered = false;

        Node* current_2 = *head;
        for (int iInnerLoop = 0; iInnerLoop < iOuterLoop; iInnerLoop++)
        {

            if (current_2->iPayload > current_2->ptrNext->iPayload)
            {
                swapPayload(current_2, current_2->ptrNext);
                bUnordered = true;
            }
            current_2 = current_2->ptrNext;
        }

        if (bUnordered == false) break;
    }
}

void selectionSort(Node** head)
{
    for (Node* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        for (Node* current_2 = current_1->ptrNext; current_2 != nullptr; current_2 = current_2->ptrNext)
        {
            if (current_1->iPayload > current_2->iPayload)
            {
                swapPayload(current_1, current_2);
            }
        }
    }
}

void optimizedSelectionSort(Node** head)
{
    int iMinValue = 0;
    Node* swapNode = nullptr;

    for (Node* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        iMinValue = current_1 -> iPayload;
        swapNode = current_1;

        for (Node* current_2 = current_1->ptrNext; current_2 != nullptr; current_2 = current_2->ptrNext)
        {
            if (iMinValue > current_2 -> iPayload)
            {
                iMinValue = current_2->iPayload;
                swapNode = current_2;
            }
        }
        swapPayload(current_1, swapNode);
    }
}

// Função auxiliar
Node* createRandomList(int iLength)
{
    Node* firstNode = createNode(rand()%100);
    Node* current = firstNode;

    for(int i = 1; i < iLength; i++)
    {
        current -> ptrNext = createNode(rand()%100);
        current = current -> ptrNext;
    }

    return firstNode;
}