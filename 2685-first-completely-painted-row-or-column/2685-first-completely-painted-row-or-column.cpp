class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size() ; 
        int m = mat[0].size() ; 
        vector<pair<int,int>> v((n*m)+1) ; 

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                v[mat[i][j]].first = i ; 
                v[mat[i][j]].second = j ; 
            }
        }

        map<int,int> row ; 
        map<int,int> col ; 
        for(int i=0 ; i<arr.size() ; i++){
            int a = arr[i] ; 

            int x = v[a].first ; 
            int y = v[a].second ; 

            col[x]++ ; 
            row[y]++ ; 

            if(col[x] == m) return i ; 
            if(row[y] == n) return i ;  
        }

        return 0 ; 
    }
};