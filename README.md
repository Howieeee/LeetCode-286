# LeetCode-286
Walls and Gates


給定一個 (m x n) 的 2D 表格 , 此表格內只有以下三種值(分別代表不同意思)
1. -1 (牆壁或者障礙)
2. 0 (門)
3. INF, 無限大 (一個空的房間)  此處利用 2^31 -1 = 2147483647 來代表
   ( 可假設房間到門的距離小於 2147483647 )

每個空房間的值為到門的「最近距離」。 若此房間無法到達門,值為 INF

例如, 給定一個2D 表格



![before](https://user-images.githubusercontent.com/33632760/137959838-7aa55bfe-a841-40a7-bf32-f8e435964b8e.jpg)

  
執行完程式後應為



![after](https://user-images.githubusercontent.com/33632760/137959834-deca9f7f-bf25-49a8-8b14-385adf2fc2bb.jpg)

  
