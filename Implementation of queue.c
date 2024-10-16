typedef struct {
    int* s1; 
    int* s2; 
    int top1;  
    int top2;   
    int STACK_SIZE; 
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->STACK_SIZE = 1000; 
    queue->s1 = (int*)malloc(queue->STACK_SIZE * sizeof(int));
    queue->s2 = (int*)malloc(queue->STACK_SIZE * sizeof(int));
    queue->top1 = 0; 
    queue->top2 = 0; 
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[obj->top1++] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == 0) {
        while (obj->top1 > 0) {
            obj->s2[obj->top2++] = obj->s1[--obj->top1];
        }
    }
    return obj->s2[--obj->top2];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == 0) {
        while (obj->top1 > 0) {
            obj->s2[obj->top2++] = obj->s1[--obj->top1];
        }
    }
    return obj->s2[obj->top2 - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == 0 && obj->top2 == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
*/
