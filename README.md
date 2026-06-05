# 組別：第19組
## 系級班級: 資訊工程學系 1A
## 成員：曾佩瑜、徐于涵、江柏毅
# 小專題題目：軍艦棋

# 遊戲玩法：
## 遊戲目標  
 搶先擊沉對手所有艦艇，即可獲勝  

## 棋盤說明  
  棋盤為 10x10 格，欄位以 A-J 表示列、1-10 表示行。  
  ### 符號說明：  
    ~  海洋（未攻擊）  
    S  你自己的艦艇  
    X  命中  
    O  落空  
## 艦艇說明  
  長度 5 x1、長度 4 x1、長度 3 x2、長度 2 x1，共5艘艦艇   
## 遊戲流程 
  1.佈陣：依序為每艘艦艇選擇起始座標與方向。  
  2.攻擊：輸入座標（如 A1 或 H10）攻擊敵方棋盤。  
  3.連續攻擊：命中時可繼續攻擊，直到落空才換手。  
  4.電腦也適用同樣規則。    
## 操作方式 
  ・座標格式：字母 + 數字，例如 A1、B10、J5  
  ・方向選擇：1 = 水平放置　0 = 垂直放置  
  ・隨時輸入 Q 可投降離開遊戲  
  ・有一方的艦艇被全部擊沉則遊戲結束

# 程式介紹：
## 程式說明
本專題以 C++ 實作終端機版軍艦棋遊戲，玩家需與電腦對戰  
輪流攻擊對方棋盤，率先擊沉所有敵艦者獲勝  
命中敵艦可獲得額外攻擊機會，直到落空才換手  
## 類別架構
### Ship
- 儲存艦艇長度
- 提供受擊與是否沉沒的判斷

### Board
- 儲存 10x10 棋盤狀態與 5 艘艦艇
- 負責放置艦艇、顯示棋盤、處理攻擊

### Computer
- 負責電腦的隨機放船與攻擊

### Game
- 管理整場遊戲流程
- 擁有玩家棋盤、敵方棋盤與電腦物件
- 負責回合輪替與勝負判斷

## UML圖：
<img width="321" height="391" alt="UML" src="https://github.com/user-attachments/assets/cbfcec68-57de-42db-a529-44ce81ee5d3d" />

# 程式如何安裝執行：
### 在github的download分支終點開綠色的code按鈕
<img width="928" height="265" alt="01" src="https://github.com/user-attachments/assets/eddbab8a-e01e-4a72-8087-547501fe8e00" /> <br>
### 點擊Download ZIP下載
<img width="926" height="444" alt="02" src="https://github.com/user-attachments/assets/66ea9d38-3cb7-40e0-9c93-8ec51c59c80e" /> <br>
### 將檔案解壓縮
### 在Visual Studio裡選擇開啟本機資料夾，找到檔案並開啟
### 在方案總管中開啟battleship.slnx專案
<img width="346" height="238" alt="03" src="https://github.com/user-attachments/assets/1b3ff169-f75a-43b6-9eb6-0d575551c640" /> <br>
### 完成安裝
### 點選上方偵錯工具後就可以開始遊玩
<img width="182" height="34" alt="04" src="https://github.com/user-attachments/assets/686970c3-891b-4afe-8f02-c91556348c63" /> <br>

# 程式畫面截圖：
### 放置船艦
<img width="365" height="254" alt="放置" src="https://github.com/user-attachments/assets/70605a55-c68c-4bc8-97a6-a2fb6d64d51a" /> <br> 
### 攻擊過程
<img width="436" height="602" alt="攻擊" src="https://github.com/user-attachments/assets/320064ac-e351-4812-8099-ba3a4e27666b" /> <br>
### 遊戲結束
<img width="441" height="136" alt="遊戲結束" src="https://github.com/user-attachments/assets/9ba3d7f6-c27a-4f55-a8af-0a71d5013db4" /> <br>  

# 分工資訊：
曾佩瑜：  
徐于涵：  
江柏毅： 
