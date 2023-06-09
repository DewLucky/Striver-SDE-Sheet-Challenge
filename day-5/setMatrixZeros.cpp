// Brute-1
// Extra space O(nxm) + TC: O((nxm)*(n+m))
#include<vector>

void setRows(vector<vector<int>> &matrix, int row){
	for(int i = 0; i<matrix[row].size(); i++){
		matrix[row][i] = 0;
	}
}

void setCols(vector<vector<int>> &matrix, int col){
	for(int i = 0; i<matrix.size(); i++){
		matrix[i][col] = 0;
	}
}

void setZeros(vector<vector<int>> &matrix)
{
	vector<vector<int>> original(matrix.size());
	for(int i = 0; i<matrix.size(); i++){
		original.push_back(matrix[i]);
	}

	for(int i = 0; i<matrix.size(); i++){
		for(int j = 0; j<matrix[i].size(); j++){
			if(original[i][j] == 0){
				setRows(matrix, i);
				setCols(matrix, j);
			}
		}
	}

	return;
}



// Brute-2
// TC: O((nxm)*(n+m)) SC: O(1)

void setRows(vector<vector<int>> &matrix, int row){
	for(int i = 0; i<matrix[row].size(); i++){
		if(matrix[row][i] != 0)
			matrix[row][i] = -1;
	}
}

void setCols(vector<vector<int>> &matrix, int col){
	for(int i = 0; i<matrix.size(); i++){
		if(matrix[i][col] != 0)
			matrix[i][col] = -1;
	}
}

void setZeros(vector<vector<int>> &matrix)
{
	for(int i = 0; i<matrix.size(); i++){
		for(int j = 0; j<matrix[i].size(); j++){
			if(matrix[i][j] == 0){
				setRows(matrix, i);
				setCols(matrix, j);
			}
		}
	}

	for(int i = 0; i<matrix.size(); i++){
		for(int j = 0; j<matrix[i].size(); j++){
			if(matrix[i][j] == -1){
				matrix[i][j] = 0;
			}
		}
	}

	return;
}



// Better 
// TC: O(2xnxm) SC: O(n+m)

void setRows(vector<vector<int>> &matrix, int row){
	for(int i = 0; i<matrix[row].size(); i++){
		if(matrix[row][i] != 0)
			matrix[row][i] = -1;
	}
}

void setCols(vector<vector<int>> &matrix, int col){
	for(int i = 0; i<matrix.size(); i++){
		if(matrix[i][col] != 0)
			matrix[i][col] = -1;
	}
}

void setZeros(vector<vector<int>> &matrix)
{
	for(int i = 0; i<matrix.size(); i++){
		for(int j = 0; j<matrix[i].size(); j++){
			if(matrix[i][j] == 0){
				setRows(matrix, i);
				setCols(matrix, j);
			}
		}
	}

	for(int i = 0; i<matrix.size(); i++){
		for(int j = 0; j<matrix[i].size(); j++){
			if(matrix[i][j] == -1){
				matrix[i][j] = 0;
			}
		}
	}

	return;
}


// Optimal: TC: O(2xnxm) SC: O(1)

void setZeros(vector<vector<int>> &matrix) {

	// optimal
	int colZero = 1;
	int n = matrix.size();
	int m = matrix[0].size();
  
	// int row[n]..........matrix[i][0]
	// int col[m]..........matrix[0][j]

	// step 1. mark the rows and cols whenever you get 0

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(matrix[i][j] == 0){
				
				// mark the row
				matrix[i][0] = 0;

				// check for the 0th col
				if(j == 0){
					colZero = 0;
				} else{
					// mark the col
					matrix[0][j] = 0;
				}
			}
		}
	}

	// step 2. update the marked rows and cols to 0, 
	// but start with cells other than 0th row and 0th col
	for(int i = 1; i<n; i++){
		for(int j = 1; j<m ; j++){
			if(matrix[0][j] == 0 || matrix[i][0] == 0){
				matrix[i][j] = 0;
			}
		}
	}

	// update the 0th row
	if(matrix[0][0] == 0){
		for(int j = 0; j<m; j++){
			matrix[0][j] = 0;
		}
	}

	// update the 0th col
	if(colZero == 0){
		for(int i = 0; i<n; i++){
			matrix[i][0] = 0;
		}
	}
	

	return;
}