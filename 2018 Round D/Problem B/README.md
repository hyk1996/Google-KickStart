# B. Paragliding

### 描述

在一个二维坐标系上，给定塔和气球的坐标，问能够获取多少个气球。具体获取的细节看题目。

### 分析

对于塔(p, h)，其对应了一个三角形的可到达范围，如果气球在该范围里，则可获取。我们对这个区域进行线性规划，即可推算出该区域的坐标范围：

(x - y - p + h >= 0) && (-x - y + p + h >= 0)

如果气球坐标(x,y)符合上面条件，则可获取。

对于小数据集，我们可以进行两层遍历，第一层对气球遍历，第二层对所有的塔遍历，判断当前气球能够取得。时间复杂度为O(NK)。

对于大数据集，时间复杂度还需要优化。分析上面的公式，我们可以进行一个坐标变换，得到：

塔坐标：(t.x, t.y) = (h-p, h+p)

气球坐标：(b.x, b.y) = (y-x, y+x)

约束条件可重写为：

t.x >= b.x && t.y >= b.y

于是问题就抽象为，对于两个二维点集T、B，计算点集B中符合条件（集合T至少存在一个点t位于其右上角）的点数目。

首先，我们分别对两个点集从大到小排序。接着，对气球进行遍历，同时设计一个指针指向塔的开头。记当前气球为b，下一气球为bb，当前塔为t。

对于当前气球b，我们判断塔t是否符合t.x >= b.x，如果符合，则指针++，重复前面的操作，直到不满足要求。同时记录下t.y的最大值。

这时，我们即可判断当前气球b是否可以取得。

重要的是，由于点集是有序的，因此对于下一个气球bb，我们不必对塔t从头开始扫描，而是从原来指针指向的位置开始。

因此，前面的排序操作的时间复杂度是O(NlogN+KlogK)，后面遍历操作的复杂度是O(N+K)，能够解决大数据集了。

### 教训

求解这道题的过程中，有一次在函数内部定义了一个大数组，导致了许多莫名的错误。根本原因在于栈空间溢出。

首先我们需要明白一下概念：**代码区**，**静态数据区**，**栈区**，**堆空间**。代码区存在代码，静态数据区存放全局变量和静态局部变量，栈区存放函数里的局部变量，堆空间存放用户动态申请的数据。其中，栈区空间非常小，只有4M或者8M（Linux），如果存在大数据的话很容易导致栈溢出。

### 知识点

平面几何，坐标点的排序

