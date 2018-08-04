### 我所理解的DP



#### DP需要考虑的事情

对于`DP`而言, 我们需要考虑:

1. 我们的求解目标是什么?
2. `状态`是什么?
3. 影响状态发生变化的因素是什么?


#### 举一个例子

[在N件物品取出若干件放在容量为W的背包里，每件物品的体积为W1，W2……Wn（Wi为整数），与之相对应的价值为P1,P2……Pn（Pi为整数）。求背包能够容纳的最大价值。](http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1085)


我们逐条分析

1. 我们当前拥有的数据有哪些?

	a. 背包的容量为W
	
	b. 物品的数量为N
	
	c. 每件物品的重量和价值

2. 我们的目标是什么?

    a. 根据题干, 求解背包容纳的最大价值

3. 进一步思考, 背包容量的最大价值的依赖

    a. 假设容量无限大, 直接对N件物品的价值P, 直接进行累加求和即可.

    b. 假设容量无限小,小到只能放进去一件物品, 那么就要在能放进去的物品中, 选一件放进去即可.
    
    c. 假设容量介于极大、极小之间, 那么就意味着, 考虑容量的同时, 考虑物品

4. 状态是什么?

    a. 基于`3`的分析, 我们可以知道, 状态看起来与`背包的容量w`以及`N件物品`有关

5. 导致`状态`变化的因素是什么?

    a. 背包容量的变化、物品的变化

6. 我们来思考一个问题, 当背包容量为`W`时, 有一件物品`m`, 我们会做出什么操作?

    a. 判断物品N是否能放入

    b. 如果能放入, 计算当前背包的价值

    c. 如果不能放入, 则维持原样

7. 对于`6`, 发生了一次状态转移, 转移是因为放入了新的物品`m`, 那么我们定义一下这个状态方程?

    a. 令`dp[c][i]`的含义为当容量为c时, 放入第i件物品后的价值
    
    b. m到来后, 当满足约束`m.weight < c`时, 则当前`dp[c][i]=dp[c-m.weight][i]+m.value`

8. 至此, 整个求解过程完毕.

