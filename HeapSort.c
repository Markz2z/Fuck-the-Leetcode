//堆筛选函数
//已知H[start~end]中除了start之外均满足堆的定义
//本函数进行调整，使H[start~end]成为一个大顶堆
typedef int ElemType;
void HeapAdjust(ElemType H[], int start, int end)
{
    ElemType temp = H[start];
    for(int i = 2*start + 1; i<=end; i*=2)
    {
        //因为假设根结点的序号为0而不是1，所以i结点左孩子和右孩子分别为2i+1和2i+2
        if(i<end && H[i]<H[i+1])//左右孩子的比较
        {
            ++i;//i为较大的记录的下标
        }

        if(temp > H[i])//左右孩子中获胜者与父亲的比较
        {
            break;
        }

        //将孩子结点上位，则以孩子结点的位置进行下一轮的筛选
        H[start]= H[i];
        start = i;
        
    }

    H[start]= temp; //插入最开始不和谐的元素
}

void HeapSort(ElemType A[], int n)
{
    //先建立大顶堆
    for(int i=n/2; i>=0; --i) {
        HeapAdjust(A,i,n);
    }
    //进行排序
    for(int i=n-1; i>0; --i) {
        //最后一个元素和第一元素进行交换
        ElemType temp=A[i];
        A[i] = A[0];
        A[0] = temp;

        //然后将剩下的无序元素继续调整为大顶堆
        HeapAdjust(A,0,i-1);
    }

}