"""
班級、學號、姓名:機電一、S0951037、許佳硯
作業內容：

矩形積分法
計算切格數為10,15,100,500,1000，並列表

Simpson's 積分法
分別計算計算切格數為10,15,100,500,1000，並列表
並說明
"""
import matplotlib.pyplot as plt
import numpy as np
import scipy as sp
N = 1000
b = np.pi
a = 0
delta = (b-a)/N
sum = 0
xi = 0
ans = 0
X = np.zeros(shape=N+1)
Y = np.zeros(shape=N+1)

for i in range(1, N):
    xi = a+i*delta
    sum = sum+np.sin(xi)
    print(i)
    X[i] = xi
    Y[i] = np.sin(xi)

ans = delta/2.0*(np.sin(a)+2*sum+np.sin(b))  # 積分值 (答案)
X[0] = a
Y[0] = np.sin(0)
X[N] = b
Y[N] = np.sin(b)
print(ans)

plt.plot(X, Y)
plt.xlim(a, b)
plt.ylim(-1.5, 1.5)
plt.xlabel("phase")
plt.ylabel("Sine  (arb.)")
plt.title("Plot  of  Sine  function")
plt.show()
