class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int row = img.size();
        int col = img[0].size();

        vector<vector<int>> answer;


        for(int i = 0;i < row;i++){
            vector<int> tempo;
            for(int j = 0;j < col;j++){
                int count = 0;
                int sum = 0;
                int left = j - 1;
                int right = j + 1;
                int up = i - 1;
                int down = i + 1;

                int ldtop_x = i - 1;
                int ldtop_y = j - 1;

                int lddown_x = i + 1;
                int lddown_y = j - 1;

                int rdtop_x = i - 1;
                int rdtop_y = j + 1;

                int rddown_x = i + 1;
                int rddown_y = j + 1;

                if(left >= 0){
                    count++;
                    sum = sum + img[i][left];
                }
                if(right < col){
                    count++;
                    sum = sum + img[i][right];
                }

                if(up >= 0){
                    count++;
                    sum = sum + img[up][j];
                }

                if(down < row){
                    count++;
                    sum = sum + img[down][j];
                }

                if(ldtop_x >= 0 && ldtop_y >= 0){
                    count++;
                    sum = sum + img[ldtop_x][ldtop_y];
                }

                if(lddown_x < row && lddown_y >= 0){
                    count++;
                    sum = sum + img[lddown_x][lddown_y];
                }

                if(rdtop_x >= 0 && rdtop_y < col){
                    count++;
                    sum = sum + img[rdtop_x][rdtop_y];
                }

                if(rddown_x < row && rddown_y < col){
                    count++;
                    sum = sum + img[rddown_x][rddown_y];
                }

                count++;
                sum = sum + img[i][j];

                int avg = sum/count;

                tempo.push_back(avg);

            }

            answer.push_back(tempo);
        }

        return answer;



        
    }
};