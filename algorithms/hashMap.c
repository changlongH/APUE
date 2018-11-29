#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLE_SIZE  (1000)
#define BASE_MOD_NUM    (1000)
#define HASH(value) (((value ^ (value >> 31)) - (value >> 31))%BASE_MOD_NUM)

struct node_t {
    int k;
    int v;
    struct node_t* next;
};

typedef struct node_t* pNode;

void FreeNode(pNode* pt);
void Insert(pNode* pHead, int k, int v)
{
    int hashKey = HASH(k);

    struct node_t* p = (struct node_t*)malloc(sizeof(struct node_t));
    p->k = k;
    p->v = v;
    if (NULL == pHead[hashKey]) {
        // no conflict
        pHead[hashKey] = p;
        p->next = NULL;
    }else{
        // has conflict insert head
        p->next = pHead[hashKey]->next;
        pHead[hashKey]->next = p;
    }
}

int Search(pNode* pHead, int k)
{
    struct node_t* p = pHead[HASH(k)];

    while(p != NULL) {
        if (p->k == k) return p->v;
        p = p->next;
    }

    return -1;
}


int* twoSum(int* nums, int numsSize, int target) {
    pNode* pHead = (struct node_t* *)malloc(sizeof(struct node_t*)*MAX_TABLE_SIZE);
    int i;
    int sub = 0;
    static int ret[2] = {0};

    for (i = 0; i < numsSize; ++i) {
        int v = Search(pHead, nums[i]);
        if (v >= 0) {
            ret[0] = v;
            ret[1] = i;
            break;
        }

        sub = target - nums[i];
        Insert(pHead, sub, i);
    }

    FreeNode(pHead);
    return ret;
}

int main()
{
    int a[132] = {217,231,523,52,547,243,648,509,415,149,689,710,265,187,370,56,977,182,400,329,471,805,955,989,255,766,38,566,79,843,295,229,988,108,781,619,704,542,335,307,359,907,727,959,161,699,123,650,147,459,657,188,304,268,405,685,620,721,351,570,899,60,388,771,24,659,425,440,508,373,32,645,409,272,356,175,533,740,370,152,34,510,745,251,227,494,258,527,817,773,178,194,860,387,627,851,449,736,15,212,529,950,316,28,65,484,968,63,4,643,795,669,203,677,139,636,289,555,430,849,150,493,301,377,240,873,965,441,230,349,447,470};
    int *ret = twoSum(a, 132, 718);
    int n1 = ret[0];
    int n2 = ret[1];
    printf("n1=%d n2=%d cnt=%d\n", n1, n2, a[n1] + a[n2]);
    return 1;
}

void FreeNode(pNode* pt)
{
    pNode p, pdelte;
    int i;
    int cnt = 0;
    for(i = 0; i < MAX_TABLE_SIZE; ++i){
        if (pt[i] == NULL) continue;
        p = pt[i];
        //printf("i=%d ", i);
        while(p != NULL) {
            //printf(" k=%d,v=%d -> ", p->k, p->v);
            pdelte = p;
            p = p->next;
            free(pdelte);
        }
        //printf("NULL\n");
    }

    free(pt);
}
