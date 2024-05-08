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
void insertEnd(Node**, int);

// Funções para a atividade
// TODO: Verificar se swapNode foi implementada da melhor forma
void swapPayload(Node*, Node*);
void displayList(Node*);
void bubbleSort(Node**);
void optimizedBubbleSort(Node**, int);
void selectionSort(Node**);
void optimizedSelectionSort(int[], int);
void optimizedSelectionSort(Node** head);

int main()
{
    cout << "==================== Teste para displayList ====================" << endl;
    Node* node_0 = nullptr;

    insertEnd(&node_0, 10);
    insertEnd(&node_0, 3);
    insertEnd(&node_0, 20);
    insertEnd(&node_0, 5);
    insertEnd(&node_0, 26);
    insertEnd(&node_0, 8);

    cout << "Lista original:" << endl;
    displayList(node_0);

    cout << "=================================================================" << endl;

    cout << "=================== Teste para ordenar a lista ==================" << endl;

    Node* node_1 = nullptr;

    insertEnd(&node_1, 10);
    insertEnd(&node_1, 3);
    insertEnd(&node_1, 20);
    insertEnd(&node_1, 5);
    insertEnd(&node_1, 26);
    insertEnd(&node_1, 8);

    // time_point<std::chrono::high_resolution_clock>
    auto timeStart = high_resolution_clock::now();
    bubbleSort(&node_1);
    auto timeStop = high_resolution_clock::now();

    cout << "Lista ordenada com bubbleSort:" << endl;
    displayList(node_1);

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;

    cout << "\n\n";

    Node* node_2 = nullptr;

    insertEnd(&node_2, 10);
    insertEnd(&node_2, 3);
    insertEnd(&node_2, 20);
    insertEnd(&node_2, 5);
    insertEnd(&node_2, 26);
    insertEnd(&node_2, 8);

    timeStart = high_resolution_clock::now();
    optimizedBubbleSort(&node_2, 6);
    timeStop = high_resolution_clock::now();

    cout << "Lista ordenada com optimizedBubbleSort:" << endl;
    displayList(node_2);

    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;

    cout << "\n\n";

    Node* node_3 = nullptr;

    insertEnd(&node_3, 10);
    insertEnd(&node_3, 3);
    insertEnd(&node_3, 20);
    insertEnd(&node_3, 5);
    insertEnd(&node_3, 26);
    insertEnd(&node_3, 8);

    timeStart = high_resolution_clock::now();
    selectionSort(&node_3);
    timeStop = high_resolution_clock::now();

    cout << "Lista ordenada com selectionSort:" << endl;
    displayList(node_3);

    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;

    
    cout << "=================================================================" << endl;

    Node* node_4 = nullptr;

    insertEnd(&node_4, 10);
    insertEnd(&node_4, 3);
    insertEnd(&node_4, 20);
    insertEnd(&node_4, 5);
    insertEnd(&node_4, 26);
    insertEnd(&node_4, 8);

    optimizedSelectionSort(&node_4);
    displayList(node_4);

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

void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Nao foi possivel realizar displayList" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Meio da Lista: Nao foi possivel realizar displayList" << endl;
        return;
    }

    Node* temp = node;

    cout << "Payload: ";

    //Percorremos a lista até o fim (ptrNext do último é NULL) 
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    //newNode->ptrNext = nullptr;

    if (*head == nullptr)
    {
        //newNode->ptrPrev = nullptr;   
        (*head) = newNode;
        return;            
    }

    Node* temp = (*head);

    //Percorremos a lista até o fim (ptrNext do último é NULL) 
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev = temp; //newNode aponta para o fim da lista
    temp->ptrNext = newNode; //antigo último elemento aponta para o novo nó

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
