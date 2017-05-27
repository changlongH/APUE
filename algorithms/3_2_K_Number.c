#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt = 0;
int T[100005];
int lT[100005*20]; // 左子树
int rT[100005*20]; // 右子树
int cT[100005*20]; // 总数
int a[100005] = {0}; // 输入原数组
int b[100005] = {0}; // 输入副本

void InitTree(int &id, int left, int size)
{
	int m;
	id = ++cnt;
	cT[cnt] = 0;
	if(left == size){
		rT[id] = 0;
		lT[id] = 0; 
	}else{
		m = (left+size)>>1;
		InitTree(lT[id], left, m);
		InitTree(rT[id], m+1, size);
	};
	//printf("lT:%d rT: %d  id:%d\n",lT[id], rT[id], id);
}

void BuildTree(int &id, const int pre, int n, int l, int r)
{
	id = ++cnt;
	cT[id] = cT[pre] + 1;
	lT[id] = lT[pre];
	rT[id] = rT[pre];
	if(l == r) return;

	int m = (l+r)>>1;
	if(n > m) BuildTree(rT[id], rT[pre], n, m+1, r); // 1.左儿子和前一棵树一样 2.链到新增加右孩子
	else BuildTree(lT[id], lT[pre], n, l, m);   //1. 右儿子和前一棵树一样 2.链到新的左儿子
}

int Query(const int start, const int end, int l, int r, int k)
{
	if(l == r) return l;
	int n = cT[lT[end]] - cT[lT[start]]; // 判断左孩子之间的差别
	//printf("n:%d  k:%d\n",  n, k);
	int m = (l+r)>>1;
	if( n >= k ) return Query(lT[start], lT[end], l, m, k); //答案在左边
	else return Query(rT[start], rT[end], m+1, r, k-n); //答案在右边
}

int main()
{
	int i, len, size, times;
	scanf("%d%d", &len, &times);

	for(i = 1; i <= len; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	//size = 0;
	sort(b+1, b+len+1);
	size = unique(b + 1, b + len + 1) - (b + 1);
	//排序之后去重复 才能使用lower_bound 
	//对输入没有限制 如果有限制使用hash 不用排序去重和 lower_bound效率好很多
	for(i = 1; i <= len; i++) a[i] = lower_bound(b+1, b+size+1,a[i]) - b;

	InitTree(T[0], 1, size);
	for(i = 1; i <= len; i++) BuildTree(T[i], T[i-1],a[i], 1, size);
	
	while(times--){
		int start, end, k;
		scanf("%d%d%d",&start, &end, &k);
	 	int ask = Query(T[start-1], T[end], 1, size, k);
		printf("%d\n", b[ask]);
	}
}
