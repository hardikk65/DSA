class Solution {
public:

    bool diagonals1(int row, int col ,vector<string>& ans,int n)
    {
        if(ans[row][col]=='Q')
            return false;

        if(row >0 && col > 0)
        {
            return diagonals1(row - 1,col - 1,ans,n);
        }

        return true;
    }

    bool diagonals2(int row, int col ,vector<string>& ans,int n)
    {
        if(ans[row][col]=='Q')
            return false;

        if(row >0 && col < n - 1)
        {
            return diagonals2(row - 1,col + 1,ans,n);
        }

        return true;
    }

    bool cols(int row,int col,vector<string>& ans){
        if(ans[row][col] == 'Q'){
            return false;
        }
        if(row > 0){
            return cols(row - 1,col,ans);
        }
        return true;
    }

    void driver(int n , vector<string> ans , vector<vector<string>>& matrix,int row)
    {
    
    if(row < n){
    for(int i = 0; i<n ; i++)
        {
            if(diagonals1(row,i,ans,n)*diagonals2(row,i,ans,n) && cols(row,i,ans)){
                cout<<"Yes"<<i<<row<<endl;
                ans[row][i] = 'Q';
                if(row + 1 == n){
                    matrix.push_back(ans);
                }
                driver(n,ans,matrix,row + 1);
                ans[row][i] = '.';
            }
        }
    }
    return;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> matrix;

        string vec = "";
        vector<string> ans ;
        for(int i =0 ; i <n ; i++){
            vec += '.';
        }
        for(int j =0 ; j <n ; j++)
        ans.push_back(vec);


        driver(n,ans,matrix,0);
    




        return matrix;

    }
};