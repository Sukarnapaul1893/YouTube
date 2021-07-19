Video tutorial: https://youtu.be/HmbRc3wEJaE

class Solution {
public:
    
    vector<vector<string> >ans;
    map<int,int>diagonal1,diagonal2;
    bool vertical[15];
    bool board[15][15];
    int len;
    
    vector<vector<string>> solveNQueens(int n) {
        len = n;
        
        for(int i=1;i<=len;i++){
            vertical[i] = false;
        }
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                diagonal1[i+j]=0;
                diagonal2[i-j]=0;
                board[i][j] = false;
            }
        }
        
        PlaceQueenHere(1);
        return ans;
    }
    
    void Add(){
        vector<string>vec;
        for(int i=1;i<=len;i++){
            string combi="";
            for(int j=1;j<=len;j++){
                 
            }
            vec.push_back(combi);
        }
        ans.push_back(vec);
    }
    
    void PlaceQueenHere(int row){
        
        if(row==len+1){
            Add();
            return;
        }
        
        for(int col = 1; col<=len; col++){
            
            if(diagonal1[row+col]==1 or diagonal2[row-col]==1 or vertical[col]==true)continue;
            
            diagonal1[row+col] = 1;
            diagonal2[row-col] = 1;
            vertical[col] = true;
            board[row][col] = true;
            
            PlaceQueenHere(row+1);
            
            diagonal1[row+col] = 0;
            diagonal2[row-col] = 0;
            vertical[col] = false;
            board[row][col] = false;
        }
    }
    
};
