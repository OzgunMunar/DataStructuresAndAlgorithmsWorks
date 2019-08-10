#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *next;

}*root;

int Check();
int Search(struct node*, int);
void GenerateFirstElement(int);

void GenerateDefaultList();

void ToList();
void ToAdd(int);
void ToInsert(int, int);
void ToAddSequential(int);
void ToRemove(int);
void Pop();
void Push(int);
void EnQue(int);
void DeQue();

void InsertionSort();
void SelectionSort();
void BubbleSort();

void LinearSearch();

void main()
{

    int chose, number, limit;

    GenerateDefaultList();
    printf("\n");
    printf("\n");
    
    printf("Default linked list is: \n");
    ToList();
    
    printf("\n");
    printf("\n");

    while(1)
    {
        
        printf("Please select a process:\n");
        printf("Press '1' to Add\n");
        printf("Press '2' to Insert\n");
        printf("Press '3' to Add Sequential\n");
        printf("Press '4' to Remove\n");
        printf("Press '5' to Pop\n");
        printf("Press '6' to Push\n");
        printf("Press '7' to Enque\n");
        printf("Press '8' to Deque\n");
        printf("Press '9' to Insertion Sort\n");
        printf("Press '10' to Selection Sort\n");
        printf("Press '11' to Bubble Sort\n");
        printf("Press '12' to Linear Search\n");
        printf("Press '0' to Quit\n\n");
        printf("Enter a number to make a chose: ");
        scanf("%d", &chose);
        printf("\n");

        switch (chose)
        {
            
            case 1:

                printf("Please enter a number to add into linked list:");
                scanf("%d", &number);

                ToAdd(number);

                break;

            case 2:

                if (!Check()) { break; }

                printf("Please enter a number to add before the limit that you'll select:");
                scanf("%d", &number);

                printf("\n");

                printf("Please enter a member of linked list, so program adds given number before that:");
                scanf("%d", &limit);

                ToInsert(number, limit);

                break;

            case 3:
                
                if (!Check()) { break; }

                printf("Please enter a number, so program adds the number before first value that bigger than that:");
                scanf("%d", &number);

                ToAddSequential(number);

                break;

            case 4:

                if (!Check()) { break; }

                printf("Please enter a number to remove from linked list:");
                scanf("%d", &number);

                ToRemove(number);
                break;
            
            case 5:
                
                if (!Check()) { break; }

                Pop();
                break;

            case 6:

                printf("Please enter a number to Push:");
                scanf("%d", &number);

                Push(number);
                break;

            case 7:

                printf("Please enter a number for Enque:");
                scanf("%d", &number);

                EnQue(number);
                break;

            case 8:

                DeQue();
                break;
                
            case 9:

                InsertionSort();
                break;

            case 10:

                SelectionSort();
                break;

            case 11:

                BubbleSort();
                break;
            case 12:

                LinearSearch();
                break;
            case 0: 
            
                break;

            default:

                printf("\nPlease make a chose in range.");
                break;

        }
        
        if(chose == 0) { break; }

        number = 0; limit = 0;
            
        printf("\n\nCurrent linked list is: \n");
        ToList();
            
        printf("\n\n");

    }  
            
    printf("\n\nLast version of linked list is: \n");
    ToList();

    printf("\n\n");

}

int Check()
{

    if (root == NULL)
    {
        
        printf("\nERROR! Linked List is empty.\n");
        return 0;

    }
    
    return 1;

}

int Search(struct node* node, int value)
{

    if(node -> next == NULL && node -> data != value)
    {

        printf("\nERROR! Unfortunately, program couldn't find the value in linked list that you entered.\n");
        return 0;

    }

    return 1;

}

void GenerateFirstElement(int number)
{

    root = (struct node*) malloc(sizeof(struct node));
    root -> data = number;
    root -> next = NULL;

}

void GenerateDefaultList()
{

    int i = 1;
    struct node *iter;

    root = (struct node*) malloc(sizeof(struct node));
    root -> data = 5;
    root -> next = NULL;

    iter = root;

    for(i; i <= 5; i++)
    {

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode -> data = i * 10;
        newNode -> next = NULL;
        iter -> next = newNode;
        iter = iter -> next;
        
    }

}

void ToList()
{

    struct node* iter = root;

    while(iter != NULL)
    {
        
        printf("| %d |", iter -> data);
        iter = iter -> next;

    }

}

void ToAdd(int number)
{

    struct node* iter;
    
    if(root == NULL) { GenerateFirstElement(number); return; }

    iter = root;

    while(iter->next != NULL)
    {

        iter = iter -> next;

    }

    iter -> next = (struct node*) malloc(sizeof(struct node));
    iter -> next -> data = number;
    iter -> next -> next = NULL;

}

void ToInsert(int number, int limit)
{

    struct node* iter = root;

    while(iter -> next != NULL && iter -> data != limit)
    {
        iter = iter -> next;
    }

    if(!Search(iter, limit)) { return; }
    else
    {
        struct node* newNode = (struct node*) malloc(sizeof(struct node));

        newNode -> next = iter;
        newNode -> data = number;
        root = newNode;
    }

}

void ToAddSequential(int number)
{

    struct node* iter = root;
    
    while(iter -> next != NULL && iter -> next -> data < number)
    {
        
        iter = iter -> next;

    }

    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = number;

    if(iter -> data >= number)
    {

        newNode -> next = iter;
        root = newNode;

    }
    else
    {
        
        if(iter -> next == NULL)
        {
            
            iter -> next = newNode;
            newNode -> next = NULL;
            
        }
        else
        {
            
            newNode -> next = iter -> next;
            iter -> next = newNode;

        }
        
    }

}

void ToRemove(int number)
{

    struct node *iter;
    struct node *temp;
    
    iter = root;

    if(root -> data == number)
    {
        
        root = root -> next;
        free(iter);
        return;

    }

    while(iter -> next -> next != NULL && iter -> next -> data != number)
    {
        
        iter = iter -> next;

    }

    if(!Search(iter -> next, number)) { return; }

    if(iter -> next -> data == number)
    {

        temp = iter -> next;
        iter -> next = iter -> next -> next;
        free(temp);

    }

}

void Push(int number)
{

    struct node* iter;

    if(root == NULL) { GenerateFirstElement(number); return; }

    iter = root;

    while(iter -> next != NULL)
    {

        iter = iter -> next;
        
    }

    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = number;

    iter -> next = (struct node*) malloc(sizeof(struct node));
    iter -> next = newNode;
    newNode -> next == NULL;

}

void Pop()
{

    struct node* iter;
    struct node* temp;

    iter = root;

    if(iter -> next == NULL)
    {
        
        root = root -> next;
        free(iter);
        return;

    }

    while(iter -> next -> next != NULL)
    {

        iter = iter -> next;

    }

    temp = iter -> next;
    iter -> next = iter -> next -> next;
    free(temp);
    

}

void EnQue(int number)
{

    struct node* iter;
    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    if(root == NULL) { GenerateFirstElement(number); return;}

    iter = root;

    while(iter ->next != NULL)
    {
        iter = iter -> next;
    }

    iter -> next = newNode;
    newNode->data = number;
    newNode -> next = NULL;

}

void DeQue()
{
    struct node *temp = root;
    root = root->next;
    free(temp);
}

void InsertionSort()
{

    struct node *iter;
    struct node *iter2;

    int tempValue;

    iter = root -> next;
    iter2 = root;

    while(iter != NULL)
    {

        while(iter2 != iter)
        {

            if(iter -> data < iter2 -> data)
            {

                tempValue = iter2 -> data;
                iter2 -> data = iter -> data;
                iter -> data = tempValue;

            }
            iter2 = iter2 -> next;
        }
        iter = iter -> next;
        iter2 = root;
    }

}

void SelectionSort()
{

    struct node *iter;
    struct node *iter2;
    struct node *temp;

    iter = root;
    iter2 = root -> next;

    int minValue = root -> data;
    int tempValue;
    
    while(iter -> next != NULL)
    {

        while(iter2 != NULL)
        {

            if(iter2-> data <= minValue)
            {

                minValue = iter2->data;
                temp = iter2;

            }

            iter2 = iter2 -> next;
        }

        if(minValue != iter -> data)
        {

            tempValue = iter -> data;
            iter -> data = minValue;
            temp -> data = tempValue;

        }

        iter = iter -> next;
        minValue = iter -> data;
        iter2 = iter -> next;
    }

}

void BubbleSort()
{

    struct node *iter;

    int swapProcess=1;
    int tempValue;
    
    while(swapProcess != 0)
    {

        swapProcess = 0;
        iter = root;

        while(iter -> next != NULL)
        {

            if(iter -> next -> data < iter -> data)
            {
                
                tempValue = iter -> data;
                iter -> data = iter -> next -> data;
                iter -> next -> data = tempValue;
                swapProcess++;

            }
            
            iter = iter -> next;

        }

    }
    
}

void LinearSearch()
{

    struct node *iter;

    int desiredNumber;
    int couldFind = 0;
    int index = 0;

    iter = root;

    printf("Please enter a number you want to search:");
    scanf("%d", &desiredNumber);

    while(iter != NULL)
    {

        index++;

        if(iter -> data == desiredNumber)
        {

            printf("Number(%d) has found in %d. index.\n", desiredNumber, index);
            couldFind++;

        }

        iter = iter -> next;

    }

    if(couldFind == 0)
    {

        printf("\nERROR! Unfortunately, program couldn't have found the number that you're seeking.\n");

    }

}