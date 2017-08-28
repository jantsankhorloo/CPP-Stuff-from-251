#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include "heap.h"
#include <cstdio>
#include <list>

using namespace std;



//MAXHEAP
//==============================================================

struct node
{
    
    int value;
    int value1;
    struct node * parent;
    struct node * leftChild = NULL;
    struct node * rightChild = NULL;
};

struct node * findLastNode(struct node * BinaryHeap, int size)
{
    list<int> Stack;
  
    // Getting the binary representation of the size
    while (size != 0) {
        if (size & 1) {
            Stack.push_front(true);
        } else {
            Stack.push_front(false);
        }
  
        size = size >> 1;
    }
  
    // Omit the first bit
    Stack.pop_front();
  
    struct node * traverse = BinaryHeap;
    bool temp;
  
    while (Stack.size() != 0) {
        temp = Stack.front();
        Stack.pop_front();
  
        if (temp) {
            traverse = traverse->rightChild;
        } else {
            // go to leftChild
            traverse = traverse->leftChild;
        }
    }
  
    return traverse;
}
  
void bubbleUp(struct node * heap)
{
    if (heap->parent == NULL) {
        return;
    }
  
    if (heap->parent->value < heap->value) {
        int temp = heap->value;
        int temp1 = heap->value1;
        heap->value = heap->parent->value;
        heap->value1 = heap->parent->value1;
        heap->parent->value = temp;
        heap->parent->value1 = temp1;
        bubbleUp(heap->parent);
    }
}
  
struct node * insertUtil(struct node * BinaryHeap, int value, int value1, list<bool> * Stack)
{
    bool temp;
    if ((*Stack).size() == 1) {
        temp = (*Stack).front();
        (*Stack).pop_front();
    
        if (temp) {
            // create new node as the right child
            BinaryHeap->rightChild = (struct node *) calloc(1, sizeof(struct node));
            BinaryHeap->rightChild->parent = BinaryHeap;
            BinaryHeap = BinaryHeap->rightChild;
            BinaryHeap->value = value;
            BinaryHeap->value1 = value1;
        } else {
            BinaryHeap->leftChild = (struct node *) calloc(1, sizeof(struct node));
            BinaryHeap->leftChild->parent = BinaryHeap;
            BinaryHeap = BinaryHeap->leftChild;
            BinaryHeap->value = value;
            BinaryHeap->value1 = value1;
        }
    } else {
        temp = (*Stack).front();
        (*Stack).pop_front();

  
        if (temp) {
            // encountered 1
            // go to rightChild
            BinaryHeap = insertUtil(BinaryHeap->rightChild, value, value1, Stack);
        } else {
            // encountered 0
            // go to leftChild
        
            BinaryHeap = insertUtil(BinaryHeap->leftChild, value, value1, Stack);
        }
    }
    return BinaryHeap;
}

void insertIntoHeap(struct node * BinaryHeap, int value, int value1 ,list<bool> * Stack)
{
    (*Stack).pop_front(); // Omit the first bit
    struct node * newNode;
    newNode = insertUtil(BinaryHeap, value, value1, Stack);
    bubbleUp(newNode);
}

struct node * getBinaryHeap(int value, int value1)
{
    struct node * BinaryHeap = (struct node *) calloc(1, sizeof(struct node));
  
    BinaryHeap->value = value;
    BinaryHeap->value1 = value1;
  
    return BinaryHeap;
}

void print(struct node * BinaryHeap)
{
    printf("%d %d\n", BinaryHeap->value, BinaryHeap->value1);
}
  
void inOrderTraversal(struct node * BinaryHeap)
{
    if (BinaryHeap == NULL) {
        return;
    }
  
    inOrderTraversal(BinaryHeap->leftChild);
    print(BinaryHeap);
    inOrderTraversal(BinaryHeap->rightChild);
}

void preOrderTraversal(struct node * BinaryHeap)
{
    if (BinaryHeap == NULL) {
        return;
    }
  
    print(BinaryHeap);
    inOrderTraversal(BinaryHeap->leftChild);
    inOrderTraversal(BinaryHeap->rightChild);
}

void heapify(struct node * BinaryHeap)
{
    if (BinaryHeap->leftChild != NULL && BinaryHeap->rightChild != NULL) {  
        if (BinaryHeap->value < BinaryHeap->leftChild->value && BinaryHeap->value < BinaryHeap->rightChild->value) {
            if (BinaryHeap->leftChild->value > BinaryHeap->rightChild->value) {
  
                int temp = BinaryHeap->value;
                int temp1 = BinaryHeap->value1;
                BinaryHeap->value = BinaryHeap->leftChild->value;
                BinaryHeap->value1 = BinaryHeap->leftChild->value1;
                BinaryHeap->leftChild->value = temp;
                BinaryHeap->leftChild->value1 = temp1;
  
                heapify(BinaryHeap->leftChild);
            } else {
  
                int temp = BinaryHeap->value;
                int temp1 = BinaryHeap->value1;
                BinaryHeap->value = BinaryHeap->rightChild->value;
                BinaryHeap->value1 = BinaryHeap->rightChild->value1;
                BinaryHeap->rightChild->value = temp;
                BinaryHeap->rightChild->value1 = temp1;
  
                heapify(BinaryHeap->rightChild);
            }
        } else if (BinaryHeap->value < BinaryHeap->leftChild->value && BinaryHeap->value > BinaryHeap->rightChild->value) {
  
            int temp = BinaryHeap->value;
            int temp1 = BinaryHeap->value1;
            BinaryHeap->value = BinaryHeap->leftChild->value;
            BinaryHeap->value1 = BinaryHeap->leftChild->value1;
            BinaryHeap->leftChild->value = temp;
            BinaryHeap->leftChild->value1 = temp1;
  
            heapify(BinaryHeap->leftChild);
        } else if (BinaryHeap->value > BinaryHeap->leftChild->value && BinaryHeap->value < BinaryHeap->rightChild->value) {
  
            int temp = BinaryHeap->value;
            int temp1 = BinaryHeap->value1;
            BinaryHeap->value = BinaryHeap->rightChild->value;
            BinaryHeap->value1 = BinaryHeap->rightChild->value1;
            BinaryHeap->rightChild->value = temp;
            BinaryHeap->rightChild->value1 = temp1;
  
            heapify(BinaryHeap->rightChild);
        }
    } else if (BinaryHeap->rightChild == NULL && BinaryHeap->leftChild != NULL) {
  
        if (BinaryHeap->leftChild->value > BinaryHeap->value) {
  
            int temp = BinaryHeap->leftChild->value;
            int temp1 = BinaryHeap->leftChild->value1;
            BinaryHeap->leftChild->value = BinaryHeap->value;
            BinaryHeap->leftChild->value1 = BinaryHeap->value1;
            BinaryHeap->value = temp;
            BinaryHeap->value1 = temp1;
        }
    }
}
  
pair<int,int> extractMax(struct node * BinaryHeap, struct node * lastNode)
{
    if (BinaryHeap == NULL) {
        return pair<int,int>(-1, -1);;
    }
  
    if (BinaryHeap == lastNode) {
        // A corner case where only one node exists
        int max = BinaryHeap->value;
        int max1 = BinaryHeap->value1;
        free(BinaryHeap);     
        return pair<int,int>(max, max1);
    }
  
    int max = BinaryHeap->value;
    int max1 = BinaryHeap->value1;

    int temp = BinaryHeap->value;
    int temp1 = BinaryHeap->value1;

    BinaryHeap->value = lastNode->value;
    BinaryHeap->value1 = lastNode->value1;

    lastNode->value = temp;
    lastNode->value1 = temp1;
  
    // Making its parent point to NULL appropriately
    struct node * parent = lastNode->parent;
  
    if (parent->leftChild == lastNode) {
        parent->leftChild = NULL;
    } else {
        parent->rightChild = NULL;
    }
  
    // Deleting the lastNode
    free(lastNode);
    heapify(BinaryHeap);    // making adjustments
  
    return pair<int,int>(max, max1);
}

//================================================




//MINHEAP
//==================================================
  
void bubbleDown(struct node * heap)
{
    if (heap->parent == NULL) {
        return;
    }
  
    if (heap->parent->value > heap->value) {
        int temp = heap->value;
        int temp1 = heap->value1;
        heap->value = heap->parent->value;
        heap->value1 = heap->parent->value1;
        heap->parent->value = temp;
        heap->parent->value1 = temp1;
  
        bubbleDown(heap->parent);
    }
}
  
struct node * insertUtilDown(struct node * BinaryHeap, int value, int value1, list<bool> * Stack)
{
    bool temp;
    if ((*Stack).size() == 1) {
        temp = (*Stack).front();
        (*Stack).pop_front();
    
        if (temp) {
            // create new node as the right child
            BinaryHeap->rightChild = (struct node *) calloc(1, sizeof(struct node));
            BinaryHeap->rightChild->parent = BinaryHeap;
            BinaryHeap = BinaryHeap->rightChild;
            BinaryHeap->value = value;
            BinaryHeap->value1 = value1;
        } else {
            // create new node as the left child
            BinaryHeap->leftChild = (struct node *) calloc(1, sizeof(struct node));
            BinaryHeap->leftChild->parent = BinaryHeap;
            BinaryHeap = BinaryHeap->leftChild;
            BinaryHeap->value = value;
            BinaryHeap->value1 = value1;
        }
    } else {
        temp = (*Stack).front();
        (*Stack).pop_front();

  
        if (temp) {
            // encountered 1
            // go to rightChild
            BinaryHeap = insertUtilDown(BinaryHeap->rightChild, value, value1, Stack);
        } else {
            BinaryHeap = insertUtilDown(BinaryHeap->leftChild, value, value1, Stack);
        }
    }
    return BinaryHeap;
}
  
void insertIntoHeapDown(struct node * BinaryHeap, int value, int value1 ,list<bool> * Stack)
{
    (*Stack).pop_front(); // Omit the first bit
    struct node * newNode;
    newNode = insertUtilDown(BinaryHeap, value, value1, Stack);
    bubbleDown(newNode);
}

void heapifyDown(struct node * BinaryHeap)
{
    if (BinaryHeap->leftChild != NULL && BinaryHeap->rightChild != NULL) {
        // both children exist
  
        if (BinaryHeap->value > BinaryHeap->leftChild->value && BinaryHeap->value > BinaryHeap->rightChild->value) {
            if (BinaryHeap->leftChild->value < BinaryHeap->rightChild->value) {
                // leftChild is lesser
  
                int temp = BinaryHeap->value;
                int temp1 = BinaryHeap->value1;
                BinaryHeap->value = BinaryHeap->leftChild->value;
                BinaryHeap->value1 = BinaryHeap->leftChild->value1;
                BinaryHeap->leftChild->value = temp;
                BinaryHeap->leftChild->value1 = temp1;
  
                heapifyDown(BinaryHeap->leftChild);
            } else {
                // rightChild is lesser
  
                int temp = BinaryHeap->value;
                int temp1 = BinaryHeap->value1;
                BinaryHeap->value = BinaryHeap->rightChild->value;
                BinaryHeap->value1 = BinaryHeap->rightChild->value1;
                BinaryHeap->rightChild->value = temp;
                BinaryHeap->rightChild->value1 = temp1;
  
                heapifyDown(BinaryHeap->rightChild);
            }
        } else if (BinaryHeap->value > BinaryHeap->leftChild->value && BinaryHeap->value < BinaryHeap->rightChild->value) {
            // leftChild is lesser & rightChild is greater than parent
  
            int temp = BinaryHeap->value;
            int temp1 = BinaryHeap->value1;
            BinaryHeap->value = BinaryHeap->leftChild->value;
            BinaryHeap->value1 = BinaryHeap->leftChild->value1;
            BinaryHeap->leftChild->value = temp;
            BinaryHeap->leftChild->value1 = temp1;
  
            heapifyDown(BinaryHeap->leftChild);
        } else if (BinaryHeap->value < BinaryHeap->leftChild->value && BinaryHeap->value > BinaryHeap->rightChild->value) {
            // rightChild is lesser & leftChild is greater than parent
  
            int temp = BinaryHeap->value;
            int temp1 = BinaryHeap->value1;
            BinaryHeap->value = BinaryHeap->rightChild->value;
            BinaryHeap->value1 = BinaryHeap->rightChild->value1;
            BinaryHeap->rightChild->value = temp;
            BinaryHeap->rightChild->value1 = temp1;
  
            heapifyDown(BinaryHeap->rightChild);
        }
    } else if (BinaryHeap->rightChild == NULL && BinaryHeap->leftChild != NULL) {
        // Only the leftChild exists
  
        if (BinaryHeap->leftChild->value < BinaryHeap->value) {
            // The existing leftChild is lesser than parent
  
            int temp = BinaryHeap->leftChild->value;
            int temp1 = BinaryHeap->leftChild->value1;
            BinaryHeap->leftChild->value = BinaryHeap->value;
            BinaryHeap->leftChild->value1 = BinaryHeap->value1;
            BinaryHeap->value = temp;
            BinaryHeap->value1 = temp1;
        }
    }
}
  
pair<int,int> extractMin(struct node * BinaryHeap, struct node * lastNode)
{
    if (BinaryHeap == NULL) {
        return pair<int,int>(-1, -1);;
    }
  
    if (BinaryHeap == lastNode) {
        // A corner case where only
        // one node exists
  
        int min = BinaryHeap->value;
        int min1 = BinaryHeap->value1;
        free(BinaryHeap);
        
        return pair<int,int>(min, min1);
    }
  
    int min = BinaryHeap->value;
    int min1 = BinaryHeap->value1;
  
    // Swap root node and last node
    int temp = BinaryHeap->value;
    int temp1 = BinaryHeap->value1;
    BinaryHeap->value = lastNode->value;
    BinaryHeap->value1 = lastNode->value1;
    lastNode->value = temp;
    lastNode->value1 = temp1;

    struct node * parent = lastNode->parent;
  
    if (parent->leftChild == lastNode) {
        parent->leftChild = NULL;
    } else {
        parent->rightChild = NULL;
    }
  
    // Deleting the lastNode
    free(lastNode);
    heapifyDown(BinaryHeap);    // making adjustments
  
    return pair<int,int>(min, min1);
}
//========================================================

void BinaryHeap1() {
    // TODO : add your logic here.
    int n, ismaxheap;;
    char command;
    bool flag = true;
    
    cin >> n >> command >> ismaxheap;
    if (command == 'c') {
        n--;
    }

    if (ismaxheap == 1) { 
        int i = 0, j, k, HeapSize = 0;
        struct node * BinaryHeap;
        list<bool> Stack;
        
        while (n--) {
            cin >> command;
            if (command == 'i') {
                int key, val;
                cin >> key >> val;            
                ++HeapSize;
                if (i == 0) {
                    BinaryHeap = getBinaryHeap(key, val);
                    i++;
                    continue;
                }
                Stack.clear();
                j = HeapSize;
          
                while (j != 0) {
                    if (j & 1) {
                        Stack.push_front(true);
                    } else {
                        Stack.push_front(false);
                    }
                    j = j >> 1;
                }
                insertIntoHeap(BinaryHeap, key, val, &Stack);
            }
            else if (command == 'p') {
                if (HeapSize == 0) {
                    cout << "empty" << endl;
                }
                int key = BinaryHeap->value;
                int val = BinaryHeap->value1;
                cout << key << " " << val << endl;
            }
            else if (command == 'e') {
                struct node * lastnode;
                lastnode = findLastNode(BinaryHeap, HeapSize);
                pair<int,int> temp = extractMax(BinaryHeap, lastnode);
                HeapSize--;
                cout << temp.first << " " << temp.second << endl;
            }
            else if (command == 'h') {
                int sizearray;
                cin >> sizearray;
                for (; i < sizearray; ++i) {
                    int key;
                    cin >> key;
                    ++HeapSize;
                    if (i == 0) {
                        BinaryHeap = getBinaryHeap(key, 0);
                        continue;
                    }
                    Stack.clear();
                    j = HeapSize;
              
                    while (j != 0) {
                        if (j & 1) {
                            Stack.push_front(true);
                        } else {
                            Stack.push_front(false);
                        }
                        j = j >> 1;
                    }    
                    insertIntoHeap(BinaryHeap, key, 0, &Stack); 
                }
            }
            else if (command == 's') {
                cout << HeapSize << endl;
                cout << endl;
            }
        }
    }


    if (ismaxheap == 2) {
        int i = 0, j, k, HeapSize = 0;
        struct node * BinaryHeap;
        list<bool> Stack;
        
        while (n--) {
            cin >> command;
            if (command == 'i') {
                int key, val;
                cin >> key >> val;            
                ++HeapSize;
                if (i == 0) {
                    BinaryHeap = getBinaryHeap(key, val);
                    i++;
                    continue;
                }
                
                Stack.clear();

                j = HeapSize;
          
                while (j != 0) {
                    if (j & 1) {
                        Stack.push_front(true);
                    } else {
                        Stack.push_front(false);
                    }
                    j = j >> 1;
                }
                insertIntoHeapDown(BinaryHeap, key, val, &Stack);
            }
            else if (command == 'p') {
                if (HeapSize == 0) {
                    cout << "empty" << endl;
                }
                else {
                    int key = BinaryHeap->value;
                    int val = BinaryHeap->value1;
                    cout << key << " " << val << endl;
                }
            }
            else if (command == 'e') {
                struct node * lastnode;
                lastnode = findLastNode(BinaryHeap, HeapSize);
                pair<int,int> temp = extractMin(BinaryHeap, lastnode);
                HeapSize--;
                cout << temp.first << " " << temp.second << endl;
            }
            else if (command == 'h') {
                int sizearray;
                cin >> sizearray;
                cout << sizearray << endl;;
                for (; i < sizearray; ++i) {
                    int key;
                    cin >> key;
                    ++HeapSize;
                    if (i == 0) {
                        BinaryHeap = getBinaryHeap(key, 0);
                        continue;
                    }
                    Stack.clear();
                    j = HeapSize;
              
                    while (j != 0) {
                        if (j & 1) {
                            Stack.push_front(true);
                        } else {
                            Stack.push_front(false);
                        }
                        j = j >> 1;
                    }    
                    insertIntoHeapDown(BinaryHeap, key, 0, &Stack);    
                }
            }
            else if (command == 's') {
                cout << HeapSize << endl;
                cout << endl;
            }
        }
    }
}


void HeapSort1() {
    // TODO : add your logic here.
    int order, n, numbers;
    char command;
    cin >> order >> n;
    numbers = n;

    
    int i = 0, j, k, HeapSize = 0;
    struct node * BinaryHeap;
    list<bool> Stack;

    while (n--) {
        int key, val;
        cin >> key >> val;
        if (order == 2) {
            ++HeapSize;
            if (i == 0) {
                BinaryHeap = getBinaryHeap(key, val);
                i++;
                continue;
            }
                
            Stack.clear();

            j = HeapSize;
          
            while (j != 0) {
                if (j & 1) {
                    Stack.push_front(true);
                } else {
                    Stack.push_front(false);
                }
                j = j >> 1;
            }
            insertIntoHeap(BinaryHeap, key, val, &Stack);
        }

        else if (order == 1) {
            ++HeapSize;
            if (i == 0) {
                BinaryHeap = getBinaryHeap(key, val);
                i++;
                continue;
            }
                
            Stack.clear();

            j = HeapSize;
          
            while (j != 0) {
                if (j & 1) {
                    Stack.push_front(true);
                } else {
                    Stack.push_front(false);
                }
                j = j >> 1;
            }
            insertIntoHeapDown(BinaryHeap, key, val, &Stack);
        }
    }

    cin >> command;
    if (command == 'q') {
        if (order == 1) {
            for (int b = 0; b < numbers; b++) {
                struct node * lastnode;
                lastnode = findLastNode(BinaryHeap, HeapSize);
                pair<int,int> temp = extractMin(BinaryHeap, lastnode);
                HeapSize--;
                cout << temp.first << " " << temp.second << endl;
            }
            cout << endl;
        }
        else if (order == 2) {
            for (int b = 0; b < numbers; b++) {
                struct node * lastnode;
                lastnode = findLastNode(BinaryHeap, HeapSize);
                pair<int,int> temp = extractMax(BinaryHeap, lastnode);
                HeapSize--;
                cout << temp.first << " " << temp.second << endl;
            }
            cout << endl;
        }
    }
}


/* Main function */
int main(int argc, char** argv) {

    /* Read the option */
    int option;
    std::cin >> option;

    /* Call the respective function */
    switch(option) {

        /* Binary Heap */
        case 2:
            BinaryHeap1();
            break;
        
        case 3:
            HeapSort1();
            break;

        /* Wrong option */
        default:
            std::cout << "Wrong option" << std::endl;

    }

    /* Close the program */
	return 0;
}

