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
# N = 1000  # 分割數目
b = np.pi  # 積分終點值
a = 0  # 積分初始值
times = [10, 50, 100, 500, 1000]
for N in times:
    delta = (b-a)/N  # deltaX
    ODDsum = 0
    EVENsum = 0
    xi = 0
    xj = 0
    ans = 0
    X = np.zeros(shape=2*N+1)
    Y = np.zeros(shape=2*N+1)
    for i in range(1, 2*N, 2):
        xi = a+i*delta/2
        ODDsum = ODDsum+np.sin(xi)
        # print(i)
        X[i] = xi
        Y[i] = np.sin(xi)
    for i in range(2, 2*N, 2):
        xj = a+i*delta/2
        EVENsum = EVENsum+np.sin(xj)
    ans = delta/6*(np.sin(a)+2*EVENsum+4*ODDsum+np.sin(b))  # 積分值 (答案)
    print(ans)
"""
# 繪圖部分

X[0] = a
Y[0] = np.sin(0)
X[N] = b
Y[N] = np.sin(b)

plt.plot(X, Y)
plt.xlim(a, b)
plt.ylim(-1.5, 1.5)
plt.xlabel("phase")
plt.ylabel("Sine  (arb.)")
plt.title("Plot  of  Sine  function")
plt.show()
"""
