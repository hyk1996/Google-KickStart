﻿## A. Wiggle Walk

### 描述

给定RxC大小的网格和SR和SC的起始点，一个机器人在该网格内按照东南西北的一系列指令移动，当机器人到达访问过的方格时，会继续保持当前方向移动，直到到达未访问过的方格为止。问机器人最后到达的位置。


### 分析

#### 小数据集

暴力解法，用一个RxC的数组记录所有网格是否访问过，接着我们遍历指令串即可，时间复杂度为O(N^2)

#### 大数据集

我们知道，暴力解法的缺点在于它重复访问了许多访问过的方格。如果我们可以记录下所有已访问方格的四个方向的目的地，我们就可以更快地执行每条指令。

观察到数据集的规模，我们不可以同时记录所有方格，因此我们只记录访问过的方格，空间复杂度为O(N)。

解法如下：

1.对于当前方格，我们记录其可以到达的四个位置；

2.读取移动的方向，得到下一个方格的位置；

3.如果下一个位置已经被访问，则查询其终点（使用并查集的路径压缩方法更新记录）。

这应该是一个O(N)时间复杂度的解法。


### 关键词

二维网格，路径压缩，并查集

