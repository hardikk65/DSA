class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();
        
        int dlrow[] = {-1,0,1,0};
        int dlcol[] = {0,1,0,-1};

        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));

        int pixel = image[sr][sc];
        image[sr][sc] = color;

        int visited[m][n];

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)visited[i][j] = 0;
        }
        while(!q.empty()){
            for(int i = 0;i < 4;i++){
                int row = q.front().first + dlrow[i];
                int col = q.front().second + dlcol[i];
                    if((row >= 0 && row < m) && (col >= 0 && col < n) && (image[row][col] == pixel) && (visited[row][col] != 1)){
                        image[row][col] = color;
                        q.push(make_pair(row,col));
                    } 
            }
            visited[q.front().first][q.front().second] = 1;
            q.pop();
            
        }

        return image;

        
    }
};