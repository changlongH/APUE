#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <openssl/md5.h>
#define HASH(value) ((value << 1) >> 9)

// hash uid 到对应 点上
static int hashUid(int key)
{
    MD5_CTX ctx;
    MD5_Init(&ctx);

    unsigned char buff[9] = {0};
    sprintf(buff, "%d", key);

    MD5_Update(&ctx, buff, sizeof(buff));
    unsigned char md[16];
    MD5_Final(md, &ctx);

    int i;
    unsigned int a = 0;
    for(i = 0; i < 4 ; i++){
        a = (a << 8);
        a += (md[i+12]);
    }
    return a;
}

struct node_t{
    int hash;
    int mid;    // 机器ID
} Node;
typedef struct node_t* pNode;

// 节点数不能动态变化 但是节点里面的机器数量可以
static pNode* InitNode(int cnt)
{
    pNode* node = (pNode*)malloc(sizeof(pNode) * cnt);
    int i;
    unsigned int range = UINT_MAX/cnt;

    for(i = 0; i < cnt; i++) {
        pNode newNode = (pNode)malloc(sizeof(pNode));
        newNode->hash = i * range;
        newNode->mid = i+1; // 读取配置
        *(node + i) = newNode;
    }
    return node;
}

int CalcNode(int hash, int nodeCnt)
{
    unsigned int range = UINT_MAX/nodeCnt;
    int idx = hash/range;
    if (idx >= nodeCnt) idx = 0;
    return idx;
}

int FindNode(pNode* p, int uid)
{
    int h = hashUid(uid);
    int idx = CalcNode(h, 4);
    return (*(p+idx))->mid;
}

int main()
{
    pNode* p = InitNode(4);
    int i;
    int ret[4] = {0};
    for(i= 1000; i < 100000; i++){
        int mid = FindNode(p, i);
        ret[mid-1]++;
    }

    printf("a=%d, b=%d, c=%d, e=%d\n", ret[0], ret[1], ret[2], ret[3]);

    return 1;
}

