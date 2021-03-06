#include "common.h"
// 线程回调函数
void *thread_callback(void *arg){/*{{{*/
	HS *hs = (HS *)arg;

	printf("传入线程的数据: %d , %d \n",*hs->heap,*hs->stack);
	
	// 改变数据

	*hs->heap *= 10;
	*hs->stack *= 10;

	return NULL;
}/*}}}*/

void pro_start(){/*{{{*/
	printf("-----------------process %d start -------------------- \n",getpid());
	self_info();
}/*}}}*/

void pro_end(){/*{{{*/
	printf("-----------------process %d end ---------------------- \n\n\n",getpid());
}/*}}}*/

int swap(int *a,int *b){/*{{{*/
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return *a + *b;
}/*}}}*/

void f()
{
	printf("b1 in f() : %d \n", b1);
}

// 不定参数
int print_args(int begin, ...){/*{{{*/
	va_list ap;
	char *p;
	int n = 0;
	va_start(ap,begin);

	p = va_arg(ap, char*);
	printf("arg %d : %s\n",n,p);
	while(p != NULL){
		n++;
		printf("arg %d : %s\n",n,p);
		p = va_arg(ap, char*);
	}
	va_end(ap);
	return n;
}/*}}}*/

// 指针
void pointer(void){/*{{{*/
	int a[5] = {1,2,3,4,5};
	int (*p)[5];
	int *ptr;
	p = &a;
	ptr = (int *)(p + 1);
	printf("the result is : %d \n",*(ptr - 1));
}/*}}}*/

// 指针的指针
void pp(){/*{{{*/
	int a = 100;
	int *p = &a;
	int **q = &p;
	printf("*p : %d \n",*p);
	printf("p : %p \n",(void*)p);
	printf("*q : %p \n",(void*)*q);
}/*}}}*/

// 改变指针的指向
void alter(int** p){/*{{{*/
	int *q;
	q = (int *)malloc(sizeof(int));
	*q = 100;
	*p = q;
}/*}}}*/

void _print_space(int a){/*{{{*/
	for(int i = 0;i < a;i++){
		printf(" ");
	}
}/*}}}*/

void _print_star(int a){/*{{{*/
	for(int i = 0;i < a;i++){
		printf("*");
	}
}/*}}}*/

// 打印一个菱形
void print_diamond(int a)
{
	printf("菱形长度: %d \n",a);
	int i;
	for(i = 0;i < a;i++){
		_print_space(a - i);
		_print_star((2 * i) - 1);
		printf("\n");
	}

	_print_star(2 * a - 1) ;
	printf("\n");
	for(i = a - 1;i > 0;i--){
		_print_space(a - i);
		_print_star((2 * i) - 1);
		printf("\n");
	}
}

// 乘法表
void plus(int a)
{
	for(int row = 1; row <= a;row++){
		for(int col = 1;col <= row;col ++){
			printf("%d x %d = %d\t",col,row,col * row);
		}
		printf("\n");
	}
}

// 处理二维数组的函数
void sum_rows(int ar[][2],int rows){/*{{{*/
	for(int i = 0;i < rows;i++){
		for(int j = 0;j < 2;j++){
			printf("ar[%d][%d] :%d \t",i,j,ar[i][j]);
		}
		printf("\n");
	}
}/*}}}*/

// 处理变长数组的函数
int sum2d(int rows,int cols,int ar[rows][cols]){/*{{{*/
    int r;
    int c;
    int tot = 0;
    for(r = 0;r < rows;r++){
        for(c = 0;c < cols;c++){
            tot += ar[r][c];
        }
    }
    return tot;
}/*}}}*/

// 习题11.5
char *pr(char *str){/*{{{*/
	char *pc;
	pc = str;
	while(*pc){
		printf("%p : ",pc);
		putchar(*pc++);
		printf("\n");
	}
	printf("pc : %p \n",pc);

	do{
		printf("%p : ",--pc);
		putchar(*pc);
		printf("\n");
	}while(pc - str);

	return pc;
}/*}}}*/

// 快速排序的划分函数
// arr 该数组
// low 低下标
// high 高下标
void divide(int *arr,int low,int high){/*{{{*/
	if(low >= high){
		return ;
	}

	// 需要交换的情况
	int base      = arr[low]; // 找基准点
	int low_mark  = low; // 低下标
	int high_mark = high; // 高下标
	
	printf("b:");
	for(int i = low;i <= high;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");

	while(low_mark != high_mark && low_mark < high_mark){
		while(arr[high_mark] >= base && low_mark < high_mark){
			high_mark--;
		}
		while(arr[low_mark] <= base && low_mark < high_mark){
			low_mark++;
		}
		swap(&arr[low_mark],&arr[high_mark]);
	}
	swap(&arr[low],&arr[high_mark]);
	printf("middle index : %d , base : %d\n",high_mark,base);
	printf("a:");
	for(int i = low;i <= high;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n\n");

	divide(arr, low , high_mark - 1);
	divide(arr, high_mark + 1, high);
}/*}}}*/

void show_arr(int arr[],int num){/*{{{*/
	for(int i = 0;i < num;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}/*}}}*/

// 打印队列
void show_queue(const struct queue *q){/*{{{*/
	for(int i = q->head;i < q->tail;i++){
		printf("%d\t",q->data[i]);
	}
}/*}}}*/

// 打印栈
void show_stack(const struct stack *s){/*{{{*/
	for(int i = 0;i < s->top;i++){
		printf("%d\t",s->data[i]);
	}
}/*}}}*/

// 玩家的一次出牌过程(队列数据添加到栈)
void card_out(struct queue *q,struct stack *s){/*{{{*/
	// 出牌
	s->data[s->top] = q->data[q->head];
	s->top++;
	q->head++;
	card_eat(q,s);
}/*}}}*/

// 判断吃牌
void card_eat(struct queue *q,struct stack *s){/*{{{*/
	int num = s->data[s->top-1]; // 要比较的数
	int mark = s->top - 2; // 比较到哪一位才相等

	// 判断是否吃牌
	for(;0 <= mark;mark--){
		if(s->data[mark] == num ){
			// printf(" (吃到:%d位) ",mark);
			// 吃牌
			for(;s->top > mark;s->top--){
				q->data[q->tail] = s->data[s->top-1];
				q->tail++;
			}
			break;
		}
	}
}/*}}}*/

// 测试下gdb
int factorial(int n)
{
	int i = 1;
	int sum = 0;
	for(;i<n;i++){
		sum = sum + i;
	}
	return sum;
}

// 进程中止处理函数
void when_exit(void)
{
	printf("\n进程 %d 退出了\n",getpid());
}

void self_info()
{
	printf("PID: %d  PPID:%d  UID: %d  EUID:%d  GID: %d  EGID: %d\n",getpid(),getppid(),getuid(),geteuid(),getgid(),getegid());
}

// 打印进程 ID 和 线程ID
void* print_pro_thread_id(void * arg)
{
	pid_t pid = getpid();
	pthread_t tid = pthread_self();
	printf("pid : %u , thread id : %u \n",(unsigned int)pid, (unsigned  int)tid);
	
	ARG* p = (ARG*) arg;
	printf("the args : %s , %d ,%f \n",p->arg1 , p->arg2 , p->arg3 );
	return NULL;
}

void sort_in_quick(int arr[] , int s, int e){
	// 先选取一个基准 默认左边第一个
	int base = arr[s];
	int left = s; // 设置左边标兵
	int right = e; // 设置右边标兵
	
	if(left > right) return ;
	while ( left != right){
		// 向左移动 e
		while( arr[right] > base && left < right ){
			right --;
		}

		// 向右移动s
		while( arr[left] <= base && left < right ){
			left ++;
		}

		if( left < right ){
			printf("交换: [%d] : %d , [%d] : %d \n",left,arr[left],right,arr[right]);
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	arr[s] = arr[right];
	arr[right] = base;
	
	// printf("right: %d \n",right);
	for(int i = 0; i <= 15; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
	// printf("s_sort_in_quick(arr,%d,%d) \n",s,right - 1);
	// printf("e_sort_in_quick(arr,%d,%d) \n",right + 1,e);
	sort_in_quick(arr,s,right - 1);
	sort_in_quick(arr,right + 1,e);
	return ;
}

// 返回最大值
int max(int x ,int y){
	return x > y ? x : y;
}

// 设计一个参数是函数的函数，即实现回掉函数功能
int call_func(fp1 call){
	return call(23,45);
}

// 打印结构体Books
void printBook(struct Books *b){
	printf("Book title : %s \n",b->title);
	printf("Book author : %s \n",b->author);
	printf("Book subject : %s \n",b->subject);
	printf("Book id : %d \n",b->id);
}

// 深度优先搜索 初始化数据
int a[10],book[10],total = 0;
void dfs( int step )
{
    int i;
    if( step == 10 )
    {
        if( a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8]*10 + a[9] )
        {
            total++;
            printf("%d%d%d + %d%d%d = %d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
        else
        {
            printf("error: %d%d%d + %d%d%d = %d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
        return;
    }

    for( i = 1; i<=9 ; i++ )
    {
        if( book[i] == 0 )
        {
            a[step] = i;
            book[i] = 1;

            dfs( step+1 );
            book[i] = 0;
        }
    }
    return;
}
