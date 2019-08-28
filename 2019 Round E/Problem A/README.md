﻿## A. Cherries Mesh

### 描述

给定N个节点，这些节点通过无向边两两连接，总的边数目为N*(N-1)/2，其中M条边的权值为1，剩余边的权值为2.

现在允许你移除一些边，但是要保证任意两节点直接或间接相连。问你能得到的最小权值和？

### 分析

#### 小数据集

标准的最小生成树的问题，可以用Prim算法解决。

#### 大数据集

大数据集的数据量超出了构建图的范围，会导致内存超限。因此需要另找别的解法。

我们有一个发现是，权值为1的边希望尽可能的保留，除非有节点实在到不了，才需要保留权值为2的边。

我们可以用并查集去考虑，假设初始时各个节点都是独立的子图，接着我们添加权值为1对应的M条边，构建连接关系。

最终我们可以得到若干个小的子图。显然，这些子图之间用权值为1的边是不可能相互连接的，因此只能用权值为2的边去连接。

假设子图的数目为x，那么权值为2的边的总权值就等于(x-1)*2.

而权值为1的边的总权值应该如何计算呢？我们可以先分别考虑各个子图，假设子图Gi里有Ni个节点，那么对应的总权值

等于Ni-1. 对所有子图求和，我们可以得到权值为1的边的总权值N-x.

所以最终结果res = (x-1)*2 + N-x = N+x-2.


### 关键词

图，最小生成树， Prim算法，并查集
