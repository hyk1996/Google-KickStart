﻿# C. Kickstart Alarm

### 描述

给定一个参数数组 A1, A2, ..., AN，对于该数组里的每一个连续子数组，计算对应的power之和。具体内容比较复杂，请直接参考原题。

### 分析

对于小数据集，暴力算法即可以解决，注意要对结果进行取模。时间复杂度为O(N^3 * K).

对于大数据集的解法如下：

首先，对于一个连续子数组[A_j, ..., A_k]的power_i的计算公式如下：

A_j × 1^i + A_j+1 × 2^i + A_j+2 × 3^i + ... + A_k × (k-j+1)^i

我们观察到，i仅仅与K相关，即i = 1:K, 因此可以想到用等比数列求和公式去化简遍历K的步骤。

为了方便起见，这里用gem(Ax, p)表示等比数列求和的结果，p是等比数列的比值（也是Ax在子数组中的位置）:

gem(p) = K, if p = 1

gem(p) = p * (p^K - 1) / (p - 1), otherwise

gem(Ax, p) = Ax * gem(p)

对于等比数列求和公式中的幂运算，使用快速幂算法，于是时间复杂度从O(K)变成了O(log(K)).

接着，对于数组元素Ax，我们分析它对最终结果的贡献。我们发现，如果Ax在任意一个连续子数组中的位置相同，那么它对最终结果的贡献也相同。

并且，Ax位于子数组的位置p (1<=p<=x) 的次数正好等于 N-x+1.

于是，Ax对答案的贡献等于：

contri_x = (N-x+1) * [gem(Ax,1) + gem(Ax,2) + ... + gem(Ax,x)]

对x从1到N进行遍历，累加contri_x，即可得到最终答案。注意到p=1时要单独考虑，因为求和公式中分母不能为0.

但是问题还没有结束，这里的时间复杂度为O(N^2 * log(K))，仍然会超时。

再次对公式进行整理，得到：

contri_x = Ax * (N-x+1) * (K + sum_gem(2, x)), sum_gem等于等比数列和的累加，即：

sum_gem(2, x) = gem(2) + gem(3) + ... + gem(x)

马上可以发现，sum_gem(2, x)实际上可以由sum_gem(2, x-1)加上gem(x)递推得到，省去了许多重复计算。

于是，时间复杂度最终优化为O(N * log(K)).

最后的最后，由于要对结果进行取模运算，而除法取模需要一些小trick，即把除法转换为乘法逆元（费马小定理）：

a / b % m = a * b^(m-2) % m

PS，费马小定理： a^(p-1) == 1 (mod p)

至此，problem solved.

### 算法

实际上代码实现并不复杂，主要难在推导过程。

### 教训

1.一开始直接使用c++自带的pow函数，该函数默认返回double类型，即便是类型转换也会导致莫名的数据失真，所以无法使用。直接上快速幂算法吧。

另外，python中的pow函数（注意不是math.pow，也不是a ** b）似乎也是快速幂实现，且带有取模的参数。然而这道题的大数据集用python会超时。

2.读入数据时，A[1] = (x1 + y1) % F，一开始忘记对F取模，以至于找了很久的bug. 所以还是要细心。
