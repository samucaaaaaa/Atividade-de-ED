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
void swapNode(Node*, Node*);
void displayList(Node*);
void bubbleSort(Node**);
void optimizedBubbleSort(Node**);
void selectionSort(Node**);
void optimizedSelectionSort(int[], int);

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

    cout << "====================== Teste para swapNode ======================" << endl;

    cout << "Lista com valores trocados:" << endl;
    swapNode(&node_0, 20, 8);
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
    optimizedBubbleSort(&node_2);
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

void swapNode(Node* node1, Node* node2) 
{
    // Se os valores forem iguais, não há troca
    if (node1->iPayload == node2->iPayload)
    {
        cout << "Os valores sao iguais! Nao ha troca!" << endl;
        return; 
    } 

    // Trocando os nós
    int tempPayload = node1->iPayload;
    node1->iPayload = node2->iPayload;
    node2->iPayload = tempPayload;
}

void bubbleSort(Node** head)
{
    for (Node* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        for (Node* current_2 = *head; current_2->ptrNext != nullptr; current_2 = current_2->ptrNext)
        {
            if (current_2->iPayload > current_2->ptrNext->iPayload)
            {
                swapNode(head, current_2, current_2->ptrNext);
            }
        }
    }
}

/*
void bubbleSort(Node** head) 
{
    // Se a lista estiver vazia ou conter apenas um nó
    if (*head == nullptr || (*head)->ptrNext == nullptr) return; 

    // Variável para indicar se houve alguma troca
    bool swapped = true; 

    while (swapped) {
        // Inicialmente, nenhuma troca foi feita durante esta passagem
        swapped = false;
        Node* current = *head;

        while (current->ptrNext != nullptr) {
            // Se os nós atuais e próximos precisam ser trocados
            if (current->iPayload > current->ptrNext->iPayload) {
                // Troca os valores dos nós
                swapNode(head, current->iPayload, current->ptrNext->iPayload);
                // Indica que uma troca foi feita
                swapped = true; 
            }
            current = current->ptrNext;
        }
    }
}
*/

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
                swapNode(head, current_2->iPayload, current_2->ptrNext->iPayload);
                bUnordered = true;
            }
            current_2 = current_2->ptrNext;
        }

        if (bUnordered == false) break;
    }
}


/*
void optimizedBubbleSort(Node** head) 
{
    // Se a lista estiver vazia ou conter apenas um nó
    if (*head == nullptr || (*head)->ptrNext == nullptr) return; 

    // Mantém o último nó ordenado
    Node* lastSorted = nullptr; 
    // Indica se houve alguma troca durante a passagem atual
    bool unordered = true; 

    while (unordered) {
        // Inicialmente, nenhuma troca foi feita durante esta passagem
        unordered = false; 
        Node* current = *head;

        while (current->ptrNext != lastSorted) {
            // Se os nós atuais e próximos precisam ser trocados
            if (current->iPayload > current->ptrNext->iPayload) {
                // Troca os valores dos nós usando a função swapNode
                swapNode(head, current->iPayload, current->ptrNext->iPayload);
                // Indica que uma troca foi feita
                unordered = true; 
            }
            current = current->ptrNext;
        }
        // Atualiza o último nó ordenado
        lastSorted = current; 
    }
}
*/

void selectionSort(Node** head)
{
    for (Node* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        for (Node* current_2 = current_1->ptrNext; current_2 != nullptr; current_2 = current_2->ptrNext)
        {
            if (current_1->iPayload > current_2->iPayload)
            {
                swapNode(head, current_1->iPayload, current_2->iPayload);
            }
        }
    }
}