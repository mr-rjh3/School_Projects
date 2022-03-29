---
title: 'Machine Learning: Assignment 3'
created: '2022-03-25T22:17:25.318Z'
modified: '2022-03-26T00:01:36.131Z'
---

# Machine Learning: Assignment 3
## 1 | Concept Question
### 1.1 | Neural Nets: 3 points
**What is the output $P(y = 1|x, w)$ from the above neural net? Express it in terms of $x_i$, $c$ and weights $w_i$ (2 points).**

$$g(z) = \frac{1}{1+e^{-z}}~~~and~~~h(z)=cz$$
$$
P(y=1|x,w) = g(w_7 + w_8h(w_1+w_3x_1+w_5x_2)+w_9h(w_2+w_4x_1+w_6x_2)) \\
= \frac{1}{1+e^{-(w_7 + w_8h(w_1+w_3x_1+w_5x_2)+w_9h(w_2+w_4x_1+w_6x_2))}} \\
= \frac{1}{1+e^{-(w_7 + w_8(cw_1 + cw_3x_1 + cw_5x_2)+w_9(cw_2 + cw_4x_1 + cw_6x_2))}} \\
= \frac{1}{1+e^{-(w_7 + cw_1w_8 + cw_3w_8x_1 + cw_5w_8x_2 + cw_2w_9 + cw_4w_9x_1 + cw_6w_9x_2)}} \\
= \frac{1}{1+e^{-(w_7 + cw_1w_8 + cw_2w_9 + x_1(cw_3w_8 + cw_4w_9) + x_2(cw_5w_8 + cw_6w_9))}}
$$
$~$
**Is it true that any multi-layered neural net with linear activation functions at hidden layers can be represented as a
neural net without any hidden layer? Briefly explain your answer (1 point).**
Yes it is true since any network that uses a linear activation function in any hidden layers can simply be chalked up to additional inputs to the final output layer. This is the same for the example above, now that we have the output it can easily be rewritten to have no hidden layers as seen below. 
![](@attachment/diagram.png)

### 1.2 | Support Vector Machines: 4 points
**As shown in Figure 2, there are 4 training samples in a 2-dimensional space. $x_1$ = (0, 0) and $x_2 = (2, 2)$ are being positive, while $x_3 = (h, 1)$ and $x_4 = (0, 3)$ are being negative. $h$ is a parameter whose value falls in the range of $[0, 3]$.**
1. **How large can $h \ge 0$ be so the training examples are still linearly separable (1 point)?**
$$\boxed{h \le 1}$$
2. **Will the direction of the maximum margin decision boundary change as a function of $h$ when the samples are separable? Explain your answer with one sentence (1 point).**
$$\boxed{\text{No, because }x_1, x_2, x_3 \text{ remain as the support vectors}}$$
3. **What will be the margin obtained by the maximum margin boundary as a function of $h$? Note that the margin as a function of $h$ is actually a linear function (2 points).**
$$
\boxed{ 
  \frac{1-h}{\sqrt{2}}~|~0 \le h \le 1, \text{otherwise }0
}
$$


