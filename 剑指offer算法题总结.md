# 剑指offer算法题总结
## 链表
#### 面试题5 从尾到头打印链表
> 使用一个栈先遍历一遍链表，然后再从链表里面取出结点，打印。

#### 面试题13 O(1)时间删除链表结点
> 把要删除的结点的下一个结点的内容复制到要删除的结点，然后把这下一个结点删除

#### 面试题15 链表中倒数第K个结点
> 使用两个指针，一个指针先走k-1，另一个指针不动，然后两个指针再一起走，前面的到了指针结尾，后面的指针也就指向了倒数第k个结点。

#### 面试题16 反转链表
> 创建两个指针，一个指针指向当前的结点，一个指向当前结点前面的结点，然后进入while循环，在循环里面先保存当前结点的next结点，再做其他操作。

#### 面试题17 合并两个排序的链表
> 递归合并

```
ListNode* merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL)
    {
        return pHead2;
    }
    if (pHead2 == NULL)
    {
        return pHead1;
    }
    ListNode* pMergeHead = NULL;
    if (pHead1->value > pHead2->value)
    {
        pMergeHead = pHead1;
        pMergeHead->next = merge(pHead1->next, pHead2);
    }else
    {
        pMergeHead = pHead2;
        pMergeHead->next = merge(pHead1, pHead2->next);
    }
    return pMergeHead;
}
```

#### 面试题26 复杂链表的复制
> 第一步根据原始链表的每个结点创建对应的结点，把这个结点链接在原始结点的后面。

#### 面试题37 两个链表的第一个公共结点
> 首先遍历得到两个链表的长度，然后使用一快一慢两个指针，最后两个指针相遇的地方就是公共结点的起点

#### 面试题45 圆圈中最后剩下的数字
> 用循环链表模拟圆圈

#### 面试题56 链表中环的入口结点
> 先用一快一慢两个指针，快指针每次移动两个，他们相遇的结点肯定在环内，然后再从这个结点出发，走若干步之后回到了这个结点，那么这若干步就是环的大小，然后再用一前一后两个指针，前面的指针先行环的大小若干步，后面的指针才开始走，两个指针相遇的地方就死环的入口。

#### 面试题57 删除链表中重复的结点
> 使用一前一后挨着的两个指针，每次判断这两个指针的值是否相等，若相等则移动后面的指针，直到找到一个结点，值不等于前面指针的值，然后让前面结点指向这个结点，同时让前面结点移动到这个结点。

## 树
#### 面试题6 重建二叉树
> 已知前序遍历结果和中序遍历结果，要求重建二叉树。使用递归的思想。

#### 面试题18 树的子结构

```
bool hasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;
    if (pRoot1 == NULL || pRoot2 == NULL)
    {
        return false;
    }
    if (pRoot1->value == pRoot2->value)
    {
        result = doesTree1hasTree2(pRoot1, pRoot2);
    }
    if (!result)
    {
        result = hasSubTree(pRoot1->left, pRoot2->left);
    }
    if (!result)
    {
        result = hasSubTree(pRoot1->right, pRoot2->right);
    }
    return result;
}

bool doesTree1hasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (pRoot2 == NULL)
    {
        return true;
    }
    if (pRoot1 == NULL)
    {
        return false;
    }
    if (pRoot1->value != pRoot2->value)
    {
        return false;
    }
    return doesTree1hasTree2(pRoot1->left, pRoot2->left) && doesTree1hasTree2(pRoot1->right, pRoot2->right);
}
```

#### 面试题19 二叉树的镜像
> 使用递归交换左右

```
void mirror(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
    {
        return;
    }
    if (pRoot->left == NULL && pRoot->right == NULL)
    {
        return ;
    }
    BinaryTreeNode* tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    if (pRoot->left != NULL)
    {
        mirror(pRoot->left);
    }
    if (pRoot->right != NULL)
    {
        mirror(pRoot->right);
    }
}
```

#### 第23题 从上往下打印二叉树
> 需要一个队列，两个常数，常数记录当前层的结点数量，以及下一层的结点数量，开始循环前首先把根节点进队，current=1， next=0

#### 第24题 二叉搜索树的后序遍历
> 输入一个整数序列，判断是不是一个二叉树的后序遍历。
> 
> 使用递归，每次通过最右边的根节点分成两段

#### 第25题 二叉树中和为某一值的路径
```
void findPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int> &path, int currentSum)
{
    currentSum += pRoot->value;
    bool isLeaf = pRoot->left == NULL && pRoot->right == NULL;
    if (currentSum == expectedSum && isLeaf)
    {
        
    }
    path.push_back(pRoot->value);
    if (pRoot->left != NULL)
    {
        findPath(pRoot->left, expectedSum, path, currentSum);
    }
    if (pRoot->right != NULL)
    {
        findPath(pRoot->right, expectedSum, path, currentSum);
    }
    path.pop_back();
}
```

#### 第27题 二叉搜索树和双向链表
> 输入一颗二叉搜索树，转化为双向链表

#### 第39题 二叉树的深度
> 使用递归，二叉树的深度等于，左子树和右子树，谁的深度更大，那么就是谁的深度见1

#### 面试题50 二叉搜索树中两个节点的最低公共祖先
> 从根节点开始遍历，遍历到一个结点，其值比其中一个的值大，比其中一个的值小，那么这个值就是其最低公共结点

#### 面试题58 二叉树的下一个结点
> 给定一颗二叉树和其中一个结点，找出中序遍历顺序的下一个结点

> 第一种情况，如果有右子树，那么就是右子树的最左子节点
> 
> 第二种情况，本身是左子结点，那么下一个结点就是父节点
> 
> 第三种情况，找出一个结点，它在父节点中是左子节点，那么这个结点的父节点就是下一个需要遍历的

#### 面试题59 对称二叉树
```
bool isSymmentrical(BinaryTreeNode* pRoot)
{
    return isSymmentrical(pRoot->left, pRoot->right);
}

bool isSymmentrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (pRoot1 == NULL && pRoot2 == NULL)
    {
        return true;
    }
    if (pRoot1 != NULL || pRoot2 != NULL)
    {
        return false;
    }
    if (pRoot1->value != pRoot2->value)
    {
        return false;
    }
    
    return isSymmentrical(pRoot1->left, pRoot2->right) && isSymmentrical(pRoot1->right, pRoot2->left);

}
```

#### 面试题60 把二叉树打印成多行
> 创建一个队列，两个值存储当前行要打印的，以及下一行要打印的

#### 面试题61 按之字形顺序打印二叉树
> 使用栈来存储，并且增加一个表示方向的值，用来切换遍历的方向。

#### 面试题63 二叉搜索树的第K个结点
> 首先在左边分支找，左边分支如果没找到，并且K=1，那么当前结点就是要找的，k--,如果k不是1，那么要在右边分支找

## 数组
#### 第六题 旋转数组的最小值
> 使用双指针，每次取中间值

#### 面试题14 调整数组顺序使奇数位于偶数前面
> 第一个指针指向第一个数字，第二个指针指向最后一个数组，移动第一个指针直到指向一个偶数，移动第二个指针直到指向一个奇数，交换两个指针的值，继续操作。

#### 第29题 数组中出现次数超过一半的数字
> 可以像快排一样，每次选择一个基准值，让小于基准值的在左边，大于基准值的在右边，递归操作，直到基准值等于middle

#### 第30题 最小的K个数
> 可以上一题一样操作

#### 面试题31 连续子数组的最大值
```
int firstLargestSum(vector<int> &array)
{
    int curSum = 0;
    int largestSum = 0x80000000;
    for (int i = 0; i < array.size(); i++)
    {
        if (curSum <= 0)
        {
            curSum = array[i];
        }else
        {
            curSum += array[i];
        }
        if (curSum > largestSum)
        {
            largestSum = curSum;
        } 
    }
    return largestSum;
    
}
```

#### 面试题38 数字在排序数组中出现的次数
> 通过二分法查找第一个K以及最后一个K

#### 面试题40 数组中只出现一次的数字
> 使用异或，因为那些成对出现两次的数字全部在异或中消失了。

#### 面试题41 和为s的两个数字
> 使用首尾两个指针，然后移动指针

#### 面试题41.1 和为S的连续正数序列
> 和上面一样，只是一开始使用两个挨着的指针

#### 面试题44 扑克牌的顺子

#### 面试题51 数组中重复的数字
> 可以利用map存储

## 队列，栈
#### 面试题7 用两个栈实现队列
> 队列的特点就是先进先出，所以push的时候push到stack1，pop的时候从stack2中pop，当stack2中为空的时候，才把stack1中的转移到stack2

#### 面试题21 包含min函数的栈
> 使用两个栈，一个栈存数据，一个栈存min

## 字符串相关
#### 面试题4 替换空格
> 首先计算出空格的数量，然后从尾向头移动

#### 面试题36 第一个只出现一次的字符
>扫描两次，第一次扫描存入map，第二次扫描再读取数量

#### 面试题42 翻转单词顺序
> 两次翻转，第一次翻转单词，第二次翻转整根句子

#### 面试题42.1 左旋转字符串
> 就是把字符串看做是两个单词来处理

## 其他
#### 面试题10 二进制中1的个数
```
int numberOf1(int n)
{
    unsigned int flag = 1;
    int count = 0;
    while (flag)
    {
        if (flag & n)
        {
            count++;
        }

        flag = flag >> 1; 
    } 
}
```

#### 面试题47 不用加减乘除做加法
> 不用加减乘除只能用位运算了，这里使用异或做基本的加法，再用与运算做进位，进位后左移一位。










